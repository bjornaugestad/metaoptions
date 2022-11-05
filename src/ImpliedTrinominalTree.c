/*
    libmetaoptions - A collection of option-related functions. 
    Copyright (C) 2000-2004 B. Augestad, bjorn.augestad@gmail.com 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "metaoptions.h"

double Transpose();

extern double ImpliedTrinomialTree(
    const char* ReturnFlag,
    int STEPn,
    int STATEi,
    double S,
    double X,
    double T,
    double r,
    double b,
    double v,
    double Skew,
    int nSteps)
{
    int i, j, n, z = 0;
    double _pi, qi, Sum, OptionValue;
    double Fo, result;
    
    double dt, u, d, Df;

    double OptionValueNode[nSteps * 2];
    double ArrowDebreu[nSteps][nSteps * 2];
    double UpProbability[nSteps - 1][nSteps * 2 - 2];
    double DownProbability[nSteps - 1][nSteps * 2 - 2];
    double LocalVolatility[nSteps - 1][nSteps * 2 - 2];

    assert_valid_price(S);
    assert_valid_strike(X);
    assert_valid_time(T);
    assert_valid_interest_rate(r);
    assert_valid_cost_of_carry(b);
    assert_valid_volatility(v);
    
    dt = T / nSteps;
    u = exp(v * sqrt(2.0 * dt));
    d = 1.0 / u;
    Df = exp(-r * dt);
    ArrowDebreu[0][0] = 1.0 ;
    
    for(n = 0; n < nSteps; n++) {
        for(i = 0; i <= n * 2; i++) {
            const double Si1 
                = S * pow(u, fmax((double)i - n, 0.0)) 
                * pow(d, fmax((double)n * 2.0 - n - i, 0.0));
            const double Si = Si1 * d;
            const double Si2 = Si1 * u;
            const double Fi = Si1 * exp(b * dt);
            const double vi = v + (S - Si1) * Skew;
            
            Sum = 0.0 ;
            if(i < (n * 2) / 2 + 1) {
                for(j = 0; j < i; j++) {
                    const double Fj 
                        = S 
                        * pow(u, fmax((double)j - n, 0.0)) 
                        * pow(d, fmax((double)n * 2.0 - n - j, 0.0)) 
                        * exp(b * dt);

                    Sum = Sum + ArrowDebreu[n][j] * (Si1 - Fj);
                }

                OptionValue = TrinomialTree(1, 0, S, Si1, (n + 1) * dt, r, b, vi, n + 1.0);
                qi = (exp(r * dt) * OptionValue - Sum) / (ArrowDebreu[n][i] * (Si1 - Si));
                _pi = (Fi + qi * (Si1 - Si) - Si1) / (Si2 - Si1);
            }
            else {
                OptionValue = TrinomialTree(1, 1, S, Si1, (n + 1) * dt, r, b, vi, n + 1.0);
                Sum = 0;
                for(j = i + 1; j <= n * 2; j++) {
                    const double Fj 
                        = S * pow(u, fmax((double)j - n, 0.0)) * pow(d, fmax((double)n * 2.0 - n - j, 0.0)) * exp(b * dt);
                    Sum = Sum + ArrowDebreu[n][j] * (Fj - Si1);
                }

                _pi = (exp(r * dt) * OptionValue - Sum) / (ArrowDebreu[n][i] * (Si2 - Si1));
                qi = (Fi - _pi * (Si2 - Si1) - Si1) / (Si - Si1);
            }

            /* Replacing negative probabilities */
            if(_pi < 0 || _pi > 1.0 || qi < 0 || qi > 1.0) {
                if(Fi > Si1 && Fi < Si2) {
                    _pi = 0.5 * ((Fi - Si1) / (Si2 - Si1) + (Fi - Si) / (Si2 - Si));
                    qi = 0.5 * ((Si2 - Fi) / (Si2 - Si));
                }
                else if(Fi > Si && Fi < Si1) {
                    _pi = 0.5 * ((Fi - Si) / (Si2 - Si));
                    qi = 0.5 * ((Si2 - Fi) / (Si2 - Si) + (Si1 - Fi) / (Si1 - Si));
                }
            }

            DownProbability[n][i] = qi;
            UpProbability[n][i] = _pi;

            /* Calculating local volatilities */
            Fo = (_pi * Si2 + qi * Si + (1.0 - _pi - qi) * Si1) * exp(b * dt);
            LocalVolatility[n][i] 
                = sqrt(_pi * pow2((Si2 - Fo))
                + (1.0 - _pi - qi) * pow2((Si1 - Fo))
                + qi * pow2((Si - Fo)) / (pow2(Fo) * dt));

            /* Calculating Arrow-Debreu prices */
            if(n == 0) {
                ArrowDebreu[n + 1][i] = qi * ArrowDebreu[n][i] * Df;
                ArrowDebreu[n + 1][i + 1] = (1.0 - _pi - qi) * ArrowDebreu[n][i] * Df ;
                ArrowDebreu[n + 1][i + 2] = _pi * ArrowDebreu[n][i] * Df;
            }
            else if(n > 0 && i == 0) {
                ArrowDebreu[n + 1][i] = qi * ArrowDebreu[n][i] * Df;
            }
            else if(n > 0 && i == n * 2) {
                ArrowDebreu[n + 1][i] 
                    = UpProbability[n][i - 2] * ArrowDebreu[n][i - 2] * Df  
                    + (1.0 - UpProbability [n][i - 1] - DownProbability [n][i - 1]) * ArrowDebreu[n][i - 1] * Df  
                    + qi * ArrowDebreu[n][i] * Df ;
                ArrowDebreu[n + 1][i + 1] 
                    = UpProbability[n][i - 1] * ArrowDebreu[n][i - 1] * Df 
                    + (1.0 - _pi - qi) * ArrowDebreu[n][i] * Df ;

                ArrowDebreu[n + 1][i + 2] = _pi * ArrowDebreu[n][i] * Df;
            }
            else if(n > 0 && i == 1) {
                ArrowDebreu[n + 1][i] 
                    = (1.0 - UpProbability[n][i - 1] - DownProbability[n][i - 1]) * ArrowDebreu[n][i - 1] * Df  
                    + qi * ArrowDebreu[n][i] * Df ;
            }
            else {
                ArrowDebreu[n + 1][i] 
                    = UpProbability[n][i - 2] * ArrowDebreu[n][i - 2] * Df  
                    + (1.0 - UpProbability [n][i - 1] - DownProbability [n][i - 1]) * ArrowDebreu[n][i - 1] * Df  
                    + qi * ArrowDebreu[n][i] * Df;
            }
        } 
    }

    if(!strcmp(ReturnFlag, "DPM")) {
        result = Transpose(DownProbability);
    }
    else if(!strcmp(ReturnFlag, "UPM")) {
        result = Transpose(UpProbability);
    }
    else if(!strcmp(ReturnFlag, "DPni")) {
        result = DownProbability[STEPn][STATEi];
    }
    else if(!strcmp(ReturnFlag, "UPni")) {
        result = UpProbability[STEPn][STATEi];
    }
    else if(!strcmp(ReturnFlag, "ADM")) {
        result = Transpose(ArrowDebreu);
    }
    else if(!strcmp(ReturnFlag, "LVM")) {
        result = Transpose(LocalVolatility);
    }
    else if(!strcmp(ReturnFlag, "LVni")) {
        result = Transpose(LocalVolatility[STEPn][STATEi]);
    }
    else if(!strcmp(ReturnFlag, "ADni")) {
        result = ArrowDebreu[STEPn][STATEi];
    }
    else if(!strcmp(ReturnFlag, "c")) {
        z = 1;
    }
    else if(!strcmp(ReturnFlag, "p")) {
        z = -1;
    }
    else {
        assert(0);
        abort();
    }

    for(i = 0; i <= 2 * nSteps; i++) {
        OptionValueNode[i] = fmax(0.0, z * (S * pow(u, fmax((double)i - nSteps, 0.0)) * pow(d, fmax(nSteps - i, 0)) - X));
    }
    
    for(n = nSteps - 1; n >= 0; n--) {
        for(i = 0; i <= n * 2; i++) {
            OptionValueNode[i] = (	
                UpProbability[n][i] * OptionValueNode[i + 2] 
                + (1 - UpProbability[n][i] - DownProbability[n][i]) * OptionValueNode[i + 1] 
                + DownProbability[n][i] * OptionValueNode[i]
            ) * Df ;
        } 
    }
    result = OptionValueNode[0];
    return result;
}


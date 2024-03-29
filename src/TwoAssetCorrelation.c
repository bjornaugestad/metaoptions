/*
    libmetaoptions - A collection of option-related functions. 
    Copyright (C) 2000-2022 B. Augestad, bjorn.augestad@gmail.com 

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

#include <math.h>
#include <assert.h>

#include "metaoptions.h"

/* Two asset correlation options */
double TwoAssetCorrelation(
    int fCall,
    double S1,
    double S2,
    double X1,
    double X2,
    double T,
    double b1,
    double b2,
    double r,
    double v1,
    double v2,
    double Rho)
{
    double sT, d1, d2, result;

    assert_valid_price(S1);
    assert_valid_price(S2);
    assert_valid_strike(X1);
    assert_valid_strike(X2);
    assert_valid_time(T);
    assert_valid_interest_rate(r);
    assert_valid_cost_of_carry(b1);
    assert_valid_cost_of_carry(b2);
    assert_valid_volatility(v1);
    assert_valid_volatility(v2);

    sT = sqrt(T);
    d1 = (log(S1 / X1) + (b1 - pow2(v1) / 2.0) * T) / (v1 * sT);
    d2 = (log(S2 / X2) + (b2 - pow2(v2) / 2.0) * T) / (v2 * sT);
    
    if (fCall) {
        result 
            = S2 * exp((b2 - r) * T) * cbnd(d2 + v2 * sT, d1 + Rho * v2 * sT, Rho) 
            - X2 * exp(-r * T)       * cbnd(d2, d1, Rho);
    }
    else {
        result 
            = X2 * exp(-r * T)       * cbnd(-d2, -d1, Rho) 
            - S2 * exp((b2 - r) * T) * cbnd(-d2 - v2 * sT, -d1 - Rho * v2 * sT, Rho);
    }

    assert(is_sane(result));
    return result;
}

#ifdef TWOASSETCORRELATION_CHECK
void check_TwoAssetCorrelation(void)
{
    printf("	%s(): Not implemented\n", __func__);
}

int main(void)
{
    check_TwoAssetCorrelation();
    return 77;
}
#endif




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

#include "metaoptions.h"

/* Vasicek: value zero coupon bond */
extern double VasicekBondPrice(
    double t1,
    double T,
    double r,
    double Theta,
    double kappa,
    double v) 
{
    double BtT, AtT, PtT;

    assert_valid_time(T);
    assert_valid_interest_rate(r);
    assert_valid_volatility(v);

    BtT = (1 - exp(-kappa * (T - t1))) / kappa;
    AtT = exp(
        (BtT - T + t1) * (pow2(kappa) * Theta - pow2(v) / 2.0) / pow2(kappa) 
        - pow2(v) * pow2(BtT) / (4.0 * kappa)
    );

    PtT = AtT * exp(-BtT * r);

    assert(is_sane(PtT));
    return PtT;
}


#ifdef VASICEKBONDPRICE_CHECK
void check_VasicekBondPrice(void)
{
    printf("	%s(): Not implemented\n", __func__);
}

int main(void)
{

    check_VasicekBondPrice();
    return 77;
}
#endif


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

/* Test the speed of the algorithms */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "metaoptions.h"

static double speed_Swapoption(void);
static double speed_Quanto(void);
static double speed_ForEquOptInDomCur(void);
static double speed_SoftBarrier(void);
static double speed_FloatingStrikeLookback(void);
static double speed_PartialFixedLB(void);
static double speed_DoubleBarrier(void);
static double speed_NewtonRaphson(void);
static double speed_normdist(void);
static double speed_miltersenschwartz(void);
static double speed_SimpleChooser(void);
static double speed_ExchangeExchangeOption(void);
static double speed_gdelta(void);
static double speed_gcarry(void);
static double speed_PartialTimeTwoAssetBarrier(void);
static double speed_gtheta(void);
static double speed_ggamma(void);
static double speed_grho(void);
static double speed_gfrench(void);
static double speed_gbs(void);
static double speed_gvega(void);
static double speed_TwoAssetBarrier(void);
static double speed_AmericanExchangeOption(void);
static double speed_black76(void);
double speed_LookBarrier(void);
static double speed_blackscholes(void);
static double speed_RollGeskeWhaley(void);
static double speed_BAWAmericanApprox(void);
static double speed_TimeSwitchOption(void);
static double speed_OptionsOnOptions(void);
static double speed_ComplexChooser(void);
static double speed_LevyAsian(void);
static double speed_PartialFloatLB(void);
static double speed_FixedStrikeLookback(void);
static double speed_SuperShare(void);
static double speed_Executive(void);
static double speed_SpreadApproximation(void);
static double speed_EquityLinkedFXO(void);
static double speed_EuropeanExchangeOption(void);
static double speed_JumpDiffusion(void);
static double speed_BinaryBarrier(void);
static double speed_BSAmericanApprox(void);
static double speed_AssetOrNothing(void);
static double speed_GapOption(void);
static double speed_bisection(void);
static double speed_ForwardStartOption(void);
static double speed_ExtremeSpreadOption(void);
static double speed_StandardBarrier(void);
static double speed_ExtendibleWriter(void);
static double speed_CashOrNothing(void);
static double speed_TurnbullWakemanAsian(void);

void die_if_nan(long double d)
{
	if(!is_sane(d)) {
		fprintf(stderr, "Crap, we got a NaN\n");
		abort();
	}
}

void report(const char* fn, clock_t start, clock_t stop, size_t niter)
{
	double duration = (1.0 * (stop - start)) / CLOCKS_PER_SEC;
	printf("%30s: %8zu calls in %.2f seconds, %8.0f calls/sec\n",
		fn,
		niter,
		duration,
		(double)niter/duration);
	fflush(stdout);
}

int main(void)
{
	long double sum = 0.0;

	if(1) {
		/* Broken, crashes in cbnd() */
		// sum += speed_LookBarrier();
		sum += speed_ExtremeSpreadOption(); die_if_nan(sum);
	}
	else {

		sum += speed_normdist(); die_if_nan(sum);
		sum += speed_gbs(); die_if_nan(sum);
		sum += speed_black76(); die_if_nan(sum);
		sum += speed_blackscholes(); die_if_nan(sum);
		sum += speed_gdelta(); die_if_nan(sum);
		sum += speed_gcarry(); die_if_nan(sum);
		sum += speed_gtheta(); die_if_nan(sum);
		sum += speed_ggamma(); die_if_nan(sum);
		sum += speed_gvega(); die_if_nan(sum);
		sum += speed_grho(); die_if_nan(sum);
		sum += speed_PartialFloatLB(); die_if_nan(sum);

		sum += speed_TwoAssetBarrier(); die_if_nan(sum);
		sum += speed_PartialTimeTwoAssetBarrier(); die_if_nan(sum);
		sum += speed_Swapoption(); die_if_nan(sum);
		sum += speed_SpreadApproximation(); die_if_nan(sum);
		sum += speed_TimeSwitchOption(); die_if_nan(sum);
		sum += speed_SimpleChooser(); die_if_nan(sum);
		sum += speed_Quanto(); die_if_nan(sum);
		sum += speed_ForEquOptInDomCur(); die_if_nan(sum);
		sum += speed_SoftBarrier(); die_if_nan(sum);
		sum += speed_LevyAsian(); die_if_nan(sum);
		sum += speed_FloatingStrikeLookback(); die_if_nan(sum);
		sum += speed_TurnbullWakemanAsian(); die_if_nan(sum);
		sum += speed_PartialFixedLB(); die_if_nan(sum);
		sum += speed_FixedStrikeLookback(); die_if_nan(sum);
		sum += speed_SuperShare(); die_if_nan(sum);
		sum += speed_Executive(); die_if_nan(sum);
		sum += speed_EquityLinkedFXO(); die_if_nan(sum);
		sum += speed_EuropeanExchangeOption(); die_if_nan(sum);
		sum += speed_DoubleBarrier(); die_if_nan(sum);
		sum += speed_CashOrNothing(); die_if_nan(sum);
		sum += speed_BinaryBarrier(); die_if_nan(sum);
		sum += speed_BSAmericanApprox(); die_if_nan(sum);
		sum += speed_AssetOrNothing(); die_if_nan(sum);
		sum += speed_NewtonRaphson(); die_if_nan(sum);
		sum += speed_ExtremeSpreadOption(); die_if_nan(sum);
		sum += speed_ExtendibleWriter(); die_if_nan(sum);
		sum += speed_StandardBarrier(); die_if_nan(sum);
		sum += speed_ExchangeExchangeOption(); die_if_nan(sum);
		sum += speed_miltersenschwartz(); die_if_nan(sum);
		sum += speed_AmericanExchangeOption(); die_if_nan(sum);
		sum += speed_RollGeskeWhaley(); die_if_nan(sum);
		sum += speed_BAWAmericanApprox(); die_if_nan(sum);
		sum += speed_OptionsOnOptions(); die_if_nan(sum);
		sum += speed_ComplexChooser(); die_if_nan(sum);
		sum += speed_JumpDiffusion(); die_if_nan(sum);
		sum += speed_gfrench(); die_if_nan(sum);
		sum += speed_bisection(); die_if_nan(sum);
		sum += speed_GapOption(); die_if_nan(sum);
		sum += speed_ForwardStartOption(); die_if_nan(sum);
	}

	printf("Printing sum to avoid too much optimizations: %Lf\n", sum);
	return 0;
}

static double speed_miltersenschwartz(void)
{
	/* Miltersen and Schwartz Futures Option prices, page 32-33.
	 * Here we need lots and lots of parameters.
	 */
	struct {
		double t, T, X, ms;
	} values[] = {
		{ 0.25, 0.25,  80.0, 15.1918 },
		{ 0.25, 0.25,  95.0,  4.5669 },
		{ 0.25, 0.25, 110.0,  0.6896 },
		{ 0.25, 0.30,  80.0, 15.1424 },
		{ 0.25, 0.30,  95.0,  4.4170 },
		{ 0.25, 0.30, 110.0,  0.6131 },
		{ 0.25, 0.50,  80.0, 15.0049 },
		{ 0.25, 0.50,  95.0,  3.9251 },
		{ 0.25, 0.50, 110.0,  0.3903 },
		{ 0.50, 1.00,  80.0, 15.0787 },
		{ 0.50, 1.00,  95.0,  4.7245 },
		{ 0.50, 1.00, 110.0,  0.7972 }
	};

	double Kappae = 1.045, Kappaf = 0.2, FT = 95.0, vS = 0.266;
	double vE = 0.249, vf = 0.0096, rhoSf = 0.0964, rhoSe = 0.805;
	double rhoef = 0.1243, sum = 0.0;

	size_t i, niter = 50 * 1000;
	clock_t stop, start;
	size_t idx = 0, nelem = sizeof(values) / sizeof(values[0]);

	start = clock();
	for(i = 0; i < niter; i++) {
		for(idx = 0; idx < nelem; idx++) {
			double Pt = exp(-0.05 * values[idx].t);

			sum += MiltersenSchwartz(1,
				Pt,
				FT,
				values[idx].X,
				values[idx].t,
				values[idx].T,
				vS,
				vE,
				vf,
				rhoSe,
				rhoSf,
				rhoef,
				Kappae,
				Kappaf);
		}
	}
	stop = clock();
	report("MiltersenSchwartz", start, stop, niter * 12); /* function iterates over test data */
	return sum;
}

/* Page 54-56 */
/* Calls function() 72 times for each niter */
static double speed_ExchangeExchangeOption(void)
{
	double S2 = 100, t1 = 0.75, T2 = 1.0, r = 0.10, b1 = 0.10, b2 = 0.10, Q = 0.10;
	double sum = 0.0;

	struct entry {
		double s1_100, s1_105;
	};
		
	/* Lots of test values from page 56 */
	static struct {
		int typeflag; 
		double v1, v2; 			/* Two volatility values */
		struct entry values[3];	/* We have values for rho -0,5, 0, 0.5 */
	} val[] = {
		{ 1, 0.20, 0.20, { { 8.5403, 10.9076}, {6.2333, 8.4333}, {3.3923, 5.2802}}},
		{ 1, 0.20, 0.25, { {10.1756, 12.6391}, {7.5787, 9.8819}, {4.3605, 6.3758}}},
		{ 1, 0.25, 0.20, { {10.1756, 12.6391}, {7.5787, 9.8819}, {4.3605, 6.3758}}},

		{ 2, 0.20, 0.20, { { 4.7893,  4.1747}, {4.9870, 4.2359}, {5.4267, 4.3746}}},
		{ 2, 0.20, 0.25, { { 4.6948,  4.1492}, {4.8607, 4.1961}, {5.2395, 4.3166}}},
		{ 2, 0.25, 0.20, { { 4.6948,  4.1492}, {4.8607, 4.1961}, {5.2395, 4.3166}}},

		{ 3, 0.20, 0.20, { { 7.3679,  5.9428}, {5.3005, 3.9927}, {2.7895, 1.7663}}},
		{ 3, 0.20, 0.25, { { 8.8426,  7.3670}, {6.5040, 5.1199}, {3.6392, 2.4929}}},
		{ 3, 0.25, 0.20, { { 8.8426,  7.3670}, {6.5040, 5.1199}, {3.6392, 2.4929}}},

		{ 4, 0.20, 0.20, { { 3.6169,  4.2099}, {4.0542, 4.7954}, {4.8239, 5.8607}}},
		{ 4, 0.20, 0.25, { { 3.3619,  3.8771}, {3.7859, 4.4341}, {4.5182, 5.4337}}},
		{ 4, 0.25, 0.20, { { 3.3619,  3.8771}, {3.7859, 4.4341}, {4.5182, 5.4337}}},
	};

	size_t n, j, nelem = sizeof(val) / sizeof(val[0]);
	size_t i, niter = 1 * 1000;

	clock_t start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			double rho;
			for(j = 0, rho = -0.5; j < 3; j++, rho += 0.5) {
				sum += ExchangeExchangeOption(val[i].typeflag, 100, S2, Q, t1, T2, r, b1, b2, val[i].v1, val[i].v2, rho);
				sum += ExchangeExchangeOption(val[i].typeflag, 105, S2, Q, t1, T2, r, b1, b2, val[i].v1, val[i].v2, rho);
			}
		}
	}

	clock_t stop = clock();
	report("ExchangeExchangeOption", start, stop, niter * 72); /* function iterates over test data */
	return sum;
}

static double speed_gdelta(void)
{
	size_t i, niter = 5*1000*1000;
	clock_t stop, start = clock();
	double sum = 0.0;
	double X = 60.0, T = 0.75, r = 0.10, b = 0.10, v = 0.30;

	/* Check gbs_delta calls */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gdelta(1, 40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gdelta(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gdelta_call(40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gdelta_call(inline version)", start, stop, niter);

	/* Check gdelta puts */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gdelta(0, 40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gdelta(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gdelta_put(40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gdelta_put(inline version)", start, stop, niter);

	return sum;
}

static double speed_gcarry(void)
{
	size_t i, niter = 5*1000*1000;
	clock_t stop, start;
	double sum = 0.0;
	double X = 60.0, T = 0.75, r = 0.10, b = 0.10, v = 0.30;

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gcarry(0, 40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gcarry(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gcarry(1, 40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gcarry(call)", start, stop, niter);
	
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gcarry_put(40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gcarry_put(inline version)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gcarry_call(40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gcarry_call(inline version)", start, stop, niter);
	return sum;
}


static double speed_gtheta(void)
{
	size_t i, niter = 2*1000*1000;
	clock_t stop, start;
	double sum = 0.0;
	double X = 60.0, T = 0.75, r = 0.10, b = 0.10, v = 0.30;

	/* Check gtheta call */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gtheta(1, 40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gtheta(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gtheta_call(40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gtheta_call(inline version)", start, stop, niter);

	/* Check gtheta put */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gtheta(0, 40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gtheta(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gtheta_put(40 + i%20, X, T, r, b, v);
	stop = clock();
	report("gtheta_put(inline version)", start, stop, niter);

	return sum;
}

static double speed_ggamma(void)
{
	size_t i, niter = 5*1000*1000;
	clock_t stop, start;
	double sum = 0.0;
	double X = 60.0, T = 0.75, r = 0.10, b = 0.10, v = 0.30;

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += ggamma(40 + i%20, X, T, r, b, v);
	stop = clock();
	report("ggamma", start, stop, niter);
	return sum;
}

static double speed_grho(void)
{
	size_t i, niter = 3*1000*1000;
	clock_t stop, start;
	double sum = 0.0;
	double X = 60.0, T = 0.75, r = 0.10, b = 0.10, v = 0.30;

	/* Check grho call */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += grho(1, 40+i%20, X, T, r, b, v);
	stop = clock();
	report("grho(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += grho_call(40+i%20, X, T, r, b, v);
	stop = clock();
	report("grho_call(inline version)", start, stop, niter);

	/* Check grho put */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += grho(0, 40+i%20, X, T, r, b, v);
	stop = clock();
	report("grho(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += grho_put(40+i%20, X, T, r, b, v);
	stop = clock();
	report("grho_put(inline version)", start, stop, niter);
	return sum;
}


/* general black & Scholes */
static double speed_gbs(void)
{
	size_t i, niter = 2*1000*1000;
	clock_t stop, start;
	double sum = 0.0;
	double X = 70.0, T = 0.5, r = 0.10, b = 0.05, v = 0.35;

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gbs(0, 60+i%20, X, T, r, b, v);
	stop = clock();
	report("gbs(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gbs_put(60+i%20, X, T, r, b, v);
	stop = clock();
	report("gbs_put(inline version)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gbs(1, 60+i%20, X, T, r, b, v);
	stop = clock();
	report("gbs(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gbs_call(60+i%20, X, T, r, b, v);
	stop = clock();
	report("gbs_call(inline version)", start, stop, niter);

	return sum;
}

double speed_AmericanExchangeOption(void)
{
	double S1 = 22.0, S2 = 20.0, Q1 = 1.0, Q2 = 1.0, r = 0.10, b1 = 0.04, b2 = 0.06, v1 = 0.20;

	double T, v2, rho;
	size_t iT, iv2, irho;

	size_t i, niter = 10*1000;
	clock_t stop, start;
	double sum = 0.0;

	start = clock();
	for(i = 0; i < niter; i++)  {
		for(iv2 = 0, v2 = 0.15; iv2 < 3; iv2++, v2 += 0.05) {
			for(iT = 0, T = 0.1; iT < 2; iT++, T += 0.4) {
				for(irho = 0, rho = -0.5; irho < 3; irho++, rho += 0.5) {
					sum += AmericanExchangeOption(S1, S2, Q1, Q2, T, r, b1, b2, v1, v2, rho);
				}
			}
		}
	}

	stop = clock();
	report("AmericanExchangeOption", start, stop, niter * 18);
	return sum;
}

static double speed_gvega(void)
{
	/* Check gvega */
	size_t i, niter = 5 * 1000*1000;
	clock_t stop, start;
	
	double sum = 0.0;
	double X = 60.0, T = 0.75, r = 0.10, b = 0.10, v = 0.30;

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gvega(80 + i % 40, X, T, r, b, v);
	stop = clock();
	report("gvega", start, stop, niter);
	return sum;
}

static double speed_black76(void)
{
	clock_t start, stop;
	double sum = 0.0, X = 60.0, T = 0.75, r = 0.10, v = 0.30;
	size_t i, niter = 2*1000*1000;

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += black76(1, 80 + i%40, X, T, r, v);
	stop = clock();
	report("black76(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += black76_call(80 + i%40, X, T, r, v);
	stop = clock();
	report("black76_call(inlined version)", start, stop, niter);


	/* Check black76 put */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += black76(0, 80 + i%40, X, T, r, v);
	stop = clock();
	report("black76(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += black76_put(80 + i%40, X, T, r, v);
	stop = clock();
	report("black76_put(inlined version)", start, stop, niter);

	return sum;
}

static double speed_blackscholes(void)
{
	clock_t start, stop;
	double sum = 0.0, X = 60.0, T = 0.75, r = 0.10, v = 0.30;
	size_t i, niter = 2*1000*1000;

	/* Check blackscholes call */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += blackscholes(1, 80 + i%40, X, T, r, v);
	stop = clock();
	report("blacksholes(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += blackscholes_call(80 + i%40, X, T, r, v);
	stop = clock();
	report("blacksholes_call(inlined)", start, stop, niter);


	/* Check blackscholes put */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += blackscholes(0, 80 + i%40, X, T, r, v);
	stop = clock();
	report("blacksholes(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += blackscholes_put(80 + i%40, X, T, r, v);
	stop = clock();
	report("blacksholes_put(inlined)", start, stop, niter);

	return sum;
}

static double speed_RollGeskeWhaley(void)
{
	/* Check RollGeskeWhaley put */
	double sum = 0.0, S = 80.0, X = 82.0;
	double t1 = 3.0 /12;	/* Time to expiration. */
	double T2 = 4.0 / 12; /* Time to dividend is paid */
	double D = 4.0; /* Dividend paid */
	double r = 0.06;
	double v = 0.30; 
	size_t i, niter = 50*1000;

	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += RollGeskeWhaley(S, X, t1, T2, r, D, v);
	clock_t stop = clock();
	report("RollGeskeWhaley", start, stop, niter);
	return sum;
}

static double speed_BAWAmericanApprox(void)
{
	double sum = 0.0, S = 90, X = 100, T = 0.5, r = 0.10, b = 0.0, v = 0.15;
	size_t i, niter = 100*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += BAWAmericanApprox(0, S, X, T, r, b, v);

	clock_t stop = clock();
	report("BAWAmericanApprox(put)", start, stop, niter);
	
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += BAWAmericanApprox(1, S, X, T, r, b, v);
	stop = clock();
	report("BAWAmericanApprox(call)", start, stop, niter);

	return sum;
}

static double speed_OptionsOnOptions(void)
{
	double sum = 0.0, S = 500.0, X1 = 520.0, X2 = 50.0, t1 = 0.25, T2 = 0.5, r = 0.08, b = 0.05, v = 0.35;
	size_t i, niter = 100*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += OptionsOnOptions(OOO_PUT_ON_CALL, S, X1, X2, t1, T2, r, b, v);

	clock_t stop = clock();
	report("OptionsOnOptions(put on call)", start, stop, niter);
	return sum;
}

static double speed_normdist(void)
{
	size_t i, niter = 3*1000*1000;

	clock_t start, stop;
	double sum = 0.0;


	start = clock();
	for(i = 0; i < niter; i++) {
		sum += normdist((double)i);
	}
	stop = clock();
	report("normdist", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) {
		sum += cnd((double)i);
	}
	stop = clock();
	report("cnd(), cumulative normdist", start, stop, niter);

	niter = 100*1000;
	start = clock();
	for(i = 0; i < niter; i++) {
		sum += cbnd((double)i, 0.1, 0.0);
	}
	stop = clock();
	report("cbnd", start, stop, niter);

	return sum;
}
		

static double speed_ComplexChooser(void)
{
	double sum = 0.0, S = 50, Xc = 55.0, Xp = 48.0, Tc = 0.5, Tp = 0.5833, T = 0.25, r = 0.10, b = 0.05, v = 0.35;

	size_t i, niter = 50*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += ComplexChooser(S, Xc, Xp, T, Tc, Tp, r, b, v);

	clock_t stop = clock();
	report("ComplexChooser", start, stop, niter);
	return sum;
}

/* Jump Diffusion, page 8-9 */
static double speed_JumpDiffusion(void)
{ 
	double sum = 0.0, S = 45.0, X = 55.0, T = 0.25, r = 0.10, v = 0.25;
	double lambda = 3.0;
	double gamma = 0.40;

	clock_t start = clock();
	size_t i, niter = 100 * 1000;
	for(i = 0; i < niter; i++) {
		sum += JumpDiffusion(1, S, X, T, r, v, lambda, gamma);
	}

	clock_t stop = clock();
	report("JumpDiffusion", start, stop, niter);
	return sum;
}


static double speed_gfrench(void)
{
	double sum = 0.0, X = 60.0, T = 0.75, t1 = 0.5, r = 0.10, b = 0.10, v = 0.30;

	/* Check gfrench call */
	size_t i, niter = 2*1000*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += gfrench(1, 80 + i%40, X, T, t1, r, b, v);
	clock_t stop = clock();
	report("gfrench(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gfrench_call(80 + i%40, X, T, t1, r, b, v);
	stop = clock();
	report("gfrench_call(inlined)", start, stop, niter);

	/* Check gfrench put */
	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gfrench(0, 80 + i%40, X, T, t1, r, b, v);
	stop = clock();
	report("gfrench(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += gfrench_put(80 + i%40, X, T, t1, r, b, v);
	stop = clock();
	report("gfrench_put(inlined)", start, stop, niter);
	return sum;
}

static double speed_ForwardStartOption(void)
{
	/* ForwardStartOption, page 37 */
	double sum = 0.0, S = 60, T = 1.0, r = 0.08, b = 0.08 - 0.04, v = 0.30;
	double t = 0.25, alpha = 1.1;

	size_t i, niter = 1 * 1000 * 1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += ForwardStartOption(1, S, alpha, t, T, r, b, v);

	clock_t stop = clock();
	report("ForwardStartOption", start, stop, niter);
	return sum;
}

static double speed_bisection(void)
{
	double sum = 0.0, S = 75.0, X = 70.0, T = 0.5, r = 0.10, b = 0.05;
	size_t i, niter = 100*1000;
	clock_t start = clock();

	for(i = 0; i < niter; i++) 
		sum += bisection(0, S, X, T, r, b, 4.086958);

	clock_t stop = clock();
	report("bisection", start, stop, niter);
	return sum;
}

/* Gap options , page 88 */
static double speed_GapOption(void)
{
	double sum = 0.0, X1 = 50.0, X2 = 57.0;
	double S = 50.0, T = 0.5, r = 0.09, b = 0.09, v = 0.20;
	size_t i, niter = 1000*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++)
		sum += GapOption(1, S, X1, X2, T, r, b, v);

	clock_t stop = clock();
	report("GapOption", start, stop, niter);
	return sum;

}

static double speed_StandardBarrier(void)
{
	struct {
		int typeflag;
		double X, H, v025, v030;
	} values[] = {
		{ SB_CALL_DOWN_OUT,  90.0,  95.0,  9.0246,  8.8334 },
		{ SB_CALL_DOWN_OUT, 100.0,  95.0,  6.7924,  7.0285 },
		{ SB_CALL_DOWN_OUT, 110.0,  95.0,  4.8759,  5.4137 },
		{ SB_CALL_DOWN_OUT,  90.0, 100.0,  3.0000,  3.0000 },
		{ SB_CALL_DOWN_OUT, 100.0, 100.0,  3.0000,  3.0000 },
		{ SB_CALL_DOWN_OUT, 110.0, 100.0,  3.0000,  3.0000 },
		{ SB_CALL_UP_OUT,  90.0, 105.0,  2.6789,  2.6341 },
		{ SB_CALL_UP_OUT, 100.0, 105.0,  2.3580,  2.4389 },
		{ SB_CALL_UP_OUT, 110.0, 105.0,  2.3453,  2.4315 },

		{ SB_CALL_DOWN_IN,  90.0,  95.0,  7.7627,  9.0093 },
		{ SB_CALL_DOWN_IN, 100.0,  95.0,  4.0109,  5.1370 },
		{ SB_CALL_DOWN_IN, 110.0,  95.0,  2.0576,  2.8517 },
		{ SB_CALL_DOWN_IN,  90.0, 100.0, 13.8333, 14.8816 },
		{ SB_CALL_DOWN_IN, 100.0, 100.0,  7.8494,  9.2045 },
		{ SB_CALL_DOWN_IN, 110.0, 100.0,  3.9795,  5.3043 },
		{ SB_CALL_UP_IN,  90.0, 105.0, 14.1112, 15.2098 },
		{ SB_CALL_UP_IN, 100.0, 105.0,  8.4482,  9.7278 },
		{ SB_CALL_UP_IN, 110.0, 105.0,  4.5910,  5.8350 },

		{ SB_PUT_DOWN_OUT,  90.0,  95.0,  2.2798,  2.4170 },
		{ SB_PUT_DOWN_OUT, 100.0,  95.0,  2.2947,  2.4258 },
		{ SB_PUT_DOWN_OUT, 110.0,  95.0,  2.6252,  2.6246 },
		{ SB_PUT_DOWN_OUT,  90.0, 100.0,  3.0000,  3.0000 },
		{ SB_PUT_DOWN_OUT, 100.0, 100.0,  3.0000,  3.0000 },
		{ SB_PUT_DOWN_OUT, 110.0, 100.0,  3.0000,  3.0000 },
		{ SB_PUT_UP_OUT,  90.0, 105.0,  3.7760,  4.2293 },
		{ SB_PUT_UP_OUT, 100.0, 105.0,  5.4932,  5.8032 },
		{ SB_PUT_UP_OUT, 110.0, 105.0,  7.5187,  7.5649 },

		{ SB_PUT_DOWN_IN,  90.0,  95.0,  2.9586,  3.8769 },
		{ SB_PUT_DOWN_IN, 100.0,  95.0,  6.5677,  7.7989 },
		{ SB_PUT_DOWN_IN, 110.0,  95.0, 11.9752, 13.3078 },
		{ SB_PUT_DOWN_IN,  90.0, 100.0,  2.2845,  3.3328 },
		{ SB_PUT_DOWN_IN, 100.0, 100.0,  5.9085,  7.2636 },
		{ SB_PUT_DOWN_IN, 110.0, 100.0, 11.6465, 12.9713 },
		{ SB_PUT_UP_IN,  90.0, 105.0,  1.4653,  2.0658 },
		{ SB_PUT_UP_IN, 100.0, 105.0,  3.3721,  4.4226 },
		{ SB_PUT_UP_IN, 110.0, 105.0,  7.0846,  8.3686 }
	};
	double sum = 0.0, S = 100.0, K = 3.0, T = 0.5, r = 0.08, b = 0.04;
	size_t i, nelem = sizeof(values)/sizeof(values[0]);
	size_t n, niter = 4*1000;

	clock_t start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			sum += StandardBarrier(values[i].typeflag, S, values[i].X, values[i].H, K, T, r, b, 0.25);
			sum += StandardBarrier(values[i].typeflag, S, values[i].X, values[i].H, K, T, r, b, 0.30);
		}
	}

	clock_t stop = clock();
	report("StandardBarrier", start, stop, niter * 72);
	return sum;
}

static double speed_ExtendibleWriter(void)
{
	double sum = 0.0, X1 = 90.0, X2= 82.0, t1 = 0.5, T2 = 0.75, r = 0.10, b = 0.10, v = 0.30;
	size_t i, niter = 100*1000;

	clock_t start = clock();
	for(i = 0; i < niter; i++)
		sum += ExtendibleWriter(1, 70 + i%20, X1, X2, t1, T2, r, b, v);
	clock_t stop = clock();
	report("ExtendibleWriter(call)", start, stop, niter);
	return sum;
}

/* Page 67-69 */
static double speed_ExtremeSpreadOption(void)
{
	double sum = 0.0, S = 100.0, T2 = 1.0, r = 0.10, b = 0.10;
	struct {
		int type;	/* option type */
		double v;	/* Volatility */
		double SM;	/* Smin or Smax depending on type Ã*/
		/* We have 4 answers, one for each of 4 time values (t1) */
		double fasit[4];
	} values[12] = {
		/* Extreme spread */
		{ ESO_CALL, 0.15, 100, { 17.5212, 10.6618,  6.7967, 3.3218 } },
		{ ESO_CALL, 0.15, 110, {  9.6924,  8.4878,  5.8519, 2.9676 } },
		{ ESO_CALL, 0.15, 120, {  4.6135,  4.5235,  3.6613, 2.0566 } },
		{ ESO_CALL, 0.30, 100, { 30.1874, 17.4998, 10.9444, 5.2735 } },
		{ ESO_CALL, 0.30, 110, { 22.0828, 16.3674, 10.4668, 5.0942 } },
		{ ESO_CALL, 0.30, 120, { 15.7847, 13.5892,  9.2051, 4.6071 } },

		/* Reverse Extreme spread */
		{ ESO_REVERSE_CALL, 0.15, 100, {  0.0000,  2.7046,  5.7250, 9.3347 } },
		{ ESO_REVERSE_CALL, 0.15,  90, {  3.6267,  6.3314,  9.3517, 12.9615 } },
		{ ESO_REVERSE_CALL, 0.15,  80, { 11.3474, 14.0521, 17.0724, 20.6821 } },
		{ ESO_REVERSE_CALL, 0.30, 100, {  0.0000,  3.6120,  7.8702, 13.3404 } },
		{ ESO_REVERSE_CALL, 0.30,  90, {  1.4769,  5.0890,  9.3471, 14.8173 } },
		{ ESO_REVERSE_CALL, 0.30,  80, {  5.7133,  9.3253, 13.5835, 19.0537 } }
	};

	size_t n, niter = 10*1000;
	size_t i, nelem = sizeof(values)/sizeof(values[0]);

	clock_t start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			sum += ExtremeSpreadOption(values[i].type, S, values[i].SM, values[i].SM, 0.00, T2, r, b, values[i].v);
			sum += ExtremeSpreadOption(values[i].type, S, values[i].SM, values[i].SM, 0.25, T2, r, b, values[i].v);
			sum += ExtremeSpreadOption(values[i].type, S, values[i].SM, values[i].SM, 0.50, T2, r, b, values[i].v);
			sum += ExtremeSpreadOption(values[i].type, S, values[i].SM, values[i].SM, 0.75, T2, r, b, values[i].v);
		}
	}
	clock_t stop = clock();
	report("ExtremeSpreadOption", start, stop, niter * 12 * 4);
	return sum;
}

static double speed_NewtonRaphson(void)
{
	size_t i, niter = 100000;
	double X = 100.0, T = 0.5, r = 0.08, v = 0.20;
	double sum = 0.0, iv;

	/* We precompute values so that we don't measure calls to blackscholes() .
	 * We store 20 values for S and cm for call/put */
	double values[20][3];
	for(i = 0; i < 20; i++) {
		double S = 90 + i%20;
		values[i][0] = S;
		values[i][1] = blackscholes(1, S, X, T, r, v);
		values[i][2] = blackscholes(0, S, X, T, r, v);
	}

	clock_t start = clock();
	for(i = 0; i < niter; i++) {
		#if 1
		iv = NewtonRaphson_call(values[i%20][0], X, T, r, values[i%20][1]);
		sum += iv;

		iv = NewtonRaphson_put(values[i%20][0], X, T, r, values[i%20][2]);
		sum += iv;
		#else
		iv = NewtonRaphson(1, values[i%20][0], X, T, r, values[i%20][1]);
		sum += iv;

		iv = NewtonRaphson(0, values[i%20][0], X, T, r, values[i%20][2]);
		sum += iv;
		#endif
	}

	clock_t stop = clock();
	report("NewtonRaphson", start, stop, niter * 2);
	return sum;
}

static double speed_AssetOrNothing(void)
{
	double sum = 0.0, X = 65.0, T = 0.5, r = 0.07, b = 0.07 - 0.05, v = 0.27;
	clock_t start, stop;
	size_t i, niter = 5*1000*1000;

	start = clock();
	for(i = 0; i < niter; i++)
		sum += AssetOrNothing(0, 65 + i%30, X, T, r, b, v);
	stop = clock();
	report("AssetOrNothing(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++)
		sum += AssetOrNothing(1, 65 + i%30, X, T, r, b, v);
	stop = clock();
	report("AssetOrNothing(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++)
		sum += AssetOrNothing_put(65 + i%30, X, T, r, b, v);
	stop = clock();
	report("AssetOrNothing_put()", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++)
		sum += AssetOrNothing_call(65 + i%30, X, T, r, b, v);
	stop = clock();
	report("AssetOrNothing_call()", start, stop, niter);

	return sum;
}

static double speed_BSAmericanApprox(void)
{ 
	/* Bjerksund & Stensland Approximation, page 26 */
	double sum = 0, X = 40.0, T = 0.75, r = 0.04, b = -0.04, v = 0.35;
	size_t i, niter = 500*1000;
	clock_t start, stop;

	start = clock();
	for(i = 0; i < niter; i++)
		sum += BSAmericanApprox(1, 40 + i%5, X, T, r, b, v);
	stop = clock();
	report("BSAmericanApprox(call)", start, stop, niter);
	return sum;
}

/* NOTE: See check_options.c for a description of the data found here */
static double speed_BinaryBarrier(void)
{
	double sum = 0.0, H = 100.0, T = 0.5, r = 0.10, b = 0.10, v = 0.20;
	 struct {
	 	double K, S, X102, X98;
		int eta, phi; /* Values from the list of options, eta==n and phi == Ã¸ */
	} values[28] = {
		{  15.0, 105.0,  9.7264,  9.7264, +1, +1},
		{  15.0,  95.0, 11.6553, 11.6553, -1, +1},

#ifdef USE_OLD_BROKEN_VERSION
		{ 15.0, 105.0,  9.7264,  9.7264, +1, +1},
#else
		{ 100.0, 105.0,  68.0848,  68.0848, +1, +1},
#endif
		{ 15.0,  95.0, 11.6553, 11.6553, -1, +1},
		{  15.0, 105.0,  9.3604,  9.3604, +1, -1},
		{  15.0,  95.0, 11.2223, 11.2223, -1, +1},
		{  15.0, 105.0, 64.8426, 64.8426, +1, -1},
		{  15.0,  95.0, 77.7017, 77.7017, -1, +1},
		{  15.0, 105.0,  4.9081,  4.9081, +1, +1},
		{  15.0,  95.0,  3.0461,  3.0461, -1, -1},
		{  15.0, 105.0, 40.1574, 40.1574, +1, +1},
		{  15.0,  95.0, 17.2983, 17.2983, -1, -1},
		{  15.0, 105.0,  4.9289,  6.2150, +1, +1},
		{  15.0,  95.0,  5.3710,  7.4519, -1, +1},

		{  15.0, 105.0, 37.2782, 45.8530, +1, +1},
		{  15.0,  95.0, 44.5294, 54.9262, -1, +1},
		{  15.0, 105.0,  4.4314,  3.1454, +1, -1},
		{  15.0,  95.0,  5.3297,  3.7704, -1, -1},
		{  15.0, 105.0, 27.5644, 18.9896, +1, -1},
		{  15.0,  95.0, 38.7533, 22.7755, -1, -1},
		{  15.0, 105.0,  4.8758,  4.9081, +1, +1},
		{  15.0,  95.0,  0.0000,  0.0407, -1, +1},
		{  15.0, 105.0, 39.9391, 40.1574, +1, +1},
		{  15.0,  95.0,  0.0000,  0.2676, -1, +1},
		{  15.0, 105.0,  0.0323,  0.0000, +1, -1},
		{  15.0,  95.0,  3.0461,  3.0054, -1, -1},
		{  15.0, 105.0,  0.2183,  0.0000, +1, -1},
		{  15.0,  95.0, 17.2983, 17.0306, -1, -1}
	};

	size_t i, nelem = sizeof(values) / sizeof(values[0]);
	size_t n, niter = 100*1000;

	clock_t start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			sum += BinaryBarrier(i + 1, values[i].S,  98, H, values[i].K, T, r, b, v, values[i].eta, values[i].phi);
			sum += BinaryBarrier(i + 1, values[i].S, 102, H, values[i].K, T, r, b, v, values[i].eta, values[i].phi);
		}
	}
	clock_t stop = clock();
	report("BinaryBarrier", start, stop, niter * nelem * 2);
	return sum;
}

static double speed_CashOrNothing(void)
{
	double sum = 0.0, X = 80.0, K = 10.0, T = 0.75, r = 0.06, b = 0.0, v = 0.35;
	clock_t start, stop;
	size_t i, niter = 5*1000*1000;

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += CashOrNothing(0, 90 + i%20, X, K, T, r, b, v);
	stop = clock();
	report("CashOrNothing(put)", start, stop, niter);

	return sum;
}

static double speed_DoubleBarrier(void)
{
	int typeflag = DB_CALL_OUT;
	double sum = 0.0, S = 100.0, X = 100.0, r = 0.10, b = 0.10;

	/* The table 2-10 contains a massive amount of test data, 
	 * 72 values for different combinations of T,v,L,U, delta1 and delta2.
	 */
	struct {
		double L, U, d1, d2;
		double fasit[2][3];
	} values[15] = {
		{ 50, 150, 0, 0,      { {4.3515, 6.1644, 7.0373}, {6.9853, 7.9336, 6.5088}}},
		{ 60, 140, 0, 0,      { {4.3505, 5.8500, 5.7726}, {6.8082, 6.3383, 4.3841}}},
		{ 70, 130, 0, 0,      { {4.3139, 4.8293, 3.7765}, {5.9697, 4.0004, 2.2563}}},
		{ 80, 120, 0, 0,      { {3.7516, 2.6387, 1.4903}, {3.5805, 1.5098, 0.5635}}},
		{ 90, 110, 0, 0,      { {1.2055, 0.3098, 0.0477}, {0.5537, 0.0441, 0.0011}}},

		{ 50, 150, -0.1, 0.1, { {4.3514, 6.0997, 6.6987}, {6.8974, 6.9821, 5.2107}}},
		{ 60, 140, -0.1, 0.1, { {4.3478, 5.6351, 5.2463}, {6.4094, 5.0199, 3.1503}}},
		{ 70, 130, -0.1, 0.1, { {4.2558, 4.3291, 3.1540}, {4.8182, 2.6259, 1.3424}}},
		{ 80, 120, -0.1, 0.1, { {3.2953, 1.9868, 1.0351}, {1.9245, 0.6455, 0.1817}}},
		{ 90, 110, -0.1, 0.1, { {0.5887, 0.1016, 0.0085}, {0.0398, 0.0002, 0.0000}}},

		{ 50, 150, 0.1, -0.1, { {4.3515, 6.2040, 7.3151}, {7.0086, 8.6080, 7.7218}}},
		{ 60, 140, 0.1, -0.1, { {4.3512, 5.9998, 6.2395}, {6.9572, 7.4267, 5.6620}}},
		{ 70, 130, 0.1, -0.1, { {4.3382, 5.2358, 4.3859}, {6.6058, 5.3761, 3.3446}}},
		{ 80, 120, 0.1, -0.1, { {4.0428, 3.2872, 2.0048}, {5.0718, 2.6591, 1.1871}}},
		{ 90, 110, 0.1, -0.1, { {1.9229, 0.6451, 0.1441}, {1.7079, 0.3038, 0.0255}}}

		/* Man, it was boring to write all those numbers :-(( */
	};

	size_t i, nelem = sizeof(values) / sizeof(values[0]);
	size_t n, niter = 1*1000;

	clock_t start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			size_t iT;
			double T;
			for(iT = 0, T = 0.25; iT < 2; iT++, T += 0.25) {
				size_t iv;
				double v;
				for(iv = 0, v = 0.15; iv < 3; iv++, v += 0.10) {
					sum += DoubleBarrier(typeflag, S, X, values[i].L, values[i].U, T, r, b, v, values[i].d1, values[i].d2);
				}
			}
		}
	}

	clock_t stop = clock();
	report("DoubleBarrier", start, stop, niter * nelem * 2 * 3);
	return sum;
}

static double speed_EuropeanExchangeOption(void)
{
	double sum = 0.0, S1 = 22.0, S2 = 20.0, Q1 = 1.0, Q2 = 1.0, r = 0.10, b1 = 0.04, b2 = 0.06, v1 = 0.20;

	size_t i, niter = 100*1000;
	double T, v2, rho;
	size_t iT, iv2, irho;
	clock_t start, stop;

	start = clock();
	for(i = 0; i < niter; i++) {
		for(iv2 = 0, v2 = 0.15; iv2 < 3; iv2++, v2 += 0.05) {
			for(iT = 0, T = 0.1; iT < 2; iT++, T += 0.4) {
				for(irho = 0, rho = -0.5; irho < 3; irho++, rho += 0.5) {
					sum += EuropeanExchangeOption(S1, S2, Q1, Q2, T, r, b1, b2, v1, v2, rho);
				}
			}
		}
	}
	stop = clock();
	report("EuropeanExchangeOption", start, stop, niter * 3 * 2 * 3);
	return sum;
}

static double speed_EquityLinkedFXO(void)
{
	double sum = 0.0, E = 1.5, X = 1.52, T = 0.25, r = 0.08, rf = 0.05, q = 0.04, vS = 0.20, vE = 0.12, rho = -0.40;
	size_t i, niter = 3 * 1000 * 1000;

	clock_t start = clock();
	for(i = 0; i < niter; i++)
		sum += EquityLinkedFXO(0, E, 90 + i%20, X, T, r, rf, q, vS, vE, rho);
	clock_t stop = clock();
	report("EquityLinkedFXO(put", start, stop, niter);
	return sum;
}

static double speed_Executive(void)
{
	double sum = 0, X = 64.0, T = 2, r = 0.07, b = r - 0.03, v = 0.38, lambda = 0.15;
	clock_t start, stop;
	size_t i, niter = 3*1000*1000;

	start = clock();
	for(i = 0; i < niter; i++)
		sum += Executive(1, 55 + i%20, X, T, r, b, v, lambda);
	stop = clock();
	report("Executive(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++)
		sum += Executive(0, 55 + i%20, X, T, r, b, v, lambda);
	stop = clock();
	report("Executive(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++)
		sum += Executive_call(55 + i%20, X, T, r, b, v, lambda);
	stop = clock();
	report("Executive_call(inlined)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++)
		sum += Executive_put(55 + i%20, X, T, r, b, v, lambda);
	stop = clock();
	report("Executive_put(inlined)", start, stop, niter);

	return sum;
}

static double speed_SuperShare(void)
{
	double sum = 0.0, XL = 90, XH = 110.0, T = 0.25, v = 0.20, r = 0.10, b = 0.0;
	size_t i, niter = 3*1000*1000;
	clock_t start, stop;

	start = clock();
	for(i = 0; i < niter; i++)
		sum += SuperShare(90 + i%20, XL, XH, T, r, b, v);
	stop = clock();
	report("SuperShare", start, stop, niter);

	return sum;
}

/* Page 63-64 */
static double speed_FixedStrikeLookback(void)
{
	/* We have test data for both puts and calls, with 3 different
	 * volatilities(0.10, 0.20,0.30), as well as 2 time values(0.5 and 1.0)
	 * and 3 strikes. This gives use the following array:
	 */
	const size_t nvol = 3, nelem = 6;
	struct {
		double X, T; 
		double vol[3], calls[3], puts[3];
	} values[6] = {
		{  95.0, 0.5, {0.10, 0.20, 0.30}, { 13.2687, 18.9263, 24.9857}, {0.6899,  4.4448,  8.9213}},
		{ 100.0, 0.5, {0.10, 0.20, 0.30}, {  8.5126, 14.1702, 20.2296}, {3.3917,  8.3177, 13.1579}},
		{ 105.0, 0.5, {0.10, 0.20, 0.30}, {  4.3908,  9.8905, 15.8512}, {8.1478, 13.0739, 17.9140}},
		{  95.0, 1.0, {0.10, 0.20, 0.30}, { 18.3241, 26.0731, 34.7116}, {1.0534,  6.2813, 12.2376}},
		{ 100.0, 1.0, {0.10, 0.20, 0.30}, { 13.8000, 21.5489, 30.1874}, {3.8079, 10.1294, 16.3889}},
		{ 105.0, 1.0, {0.10, 0.20, 0.30}, {  9.5445, 17.2965, 25.9002}, {8.3321, 14.6536, 20.9130}}
	};

	double sum = 0.0, S = 100.0, Smin = 100.0, Smax = 100.0, r = 0.10, b = 0.10;
	size_t i, v;

	size_t n, niter = 100*1000;
	clock_t start, stop;

	start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			for(v = 0; v < nvol; v++) {
				sum += FixedStrikeLookback(1, S, Smin, Smax, values[i].X, values[i].T, r, b, values[i].vol[v]);
			}
		}
	}
	stop = clock();
	report("FixedStrikeLookback(call)", start, stop, niter * nelem * nvol);

	start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			for(v = 0; v < nvol; v++) {
				sum += FixedStrikeLookback(0, S, Smin, Smax, values[i].X, values[i].T, r, b, values[i].vol[v]);
			}
		}
	}
	stop = clock();
	report("FixedStrikeLookback(put)", start, stop, niter * nelem * nvol);
	return sum;
}

/* Page 65-66 */
static double speed_PartialFloatLB(void)
{
	double calls[6][5]  = {
		{  90.0, 0.10,  8.6524,  9.2128,  9.5567 },
		{  90.0, 0.20, 13.3402, 14.5121, 15.3140 },
		{  90.0, 0.30, 17.9831, 19.6618, 20.8493 },
		{ 110.0, 0.10, 10.5751, 11.2601, 11.6804 },
		{ 110.0, 0.20, 16.3047, 17.7370, 18.7171 },
		{ 110.0, 0.30, 21.9793, 24.0311, 25.4825 }
	};

	double put_values[6][5]  = {
		{  90.0, 0.10,  2.7189,  3.4639,  4.1912 },
		{  90.0, 0.20,  7.9153,  9.5825, 11.0362 },
		{  90.0, 0.30, 13.4719, 16.1495, 18.4071 },
		{ 110.0, 0.10,  3.3231,  4.2336,  5.1226 },
		{ 110.0, 0.20,  9.6743, 11.7119, 13.4887 },
		{ 110.0, 0.30, 16.4657, 19.7383, 22.4976 }
	};

	double sum = 0.0, lambda = 1.0, T2 = 1.0, r = 0.06, b = 0.06;
	size_t i, nelem = 6;
	clock_t start, stop;
	size_t n, niter = 10*1000;

	start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			sum += PartialFloatLB(1, calls[i][0], calls[i][0], calls[i][0], 0.25, T2, r, b, calls[i][1], lambda);
			sum += PartialFloatLB(1, calls[i][0], calls[i][0], calls[i][0], 0.50, T2, r, b, calls[i][1], lambda);
			sum += PartialFloatLB(1, calls[i][0], calls[i][0], calls[i][0], 0.75, T2, r, b, calls[i][1], lambda);
		}
	}
	stop = clock();
	report("PartialFloatLB(put)", start, stop, niter * nelem * 3);

	start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			sum += PartialFloatLB(0, put_values[i][0], put_values[i][0], put_values[i][0], 0.25, T2, r, b, put_values[i][1], lambda);
			sum += PartialFloatLB(0, put_values[i][0], put_values[i][0], put_values[i][0], 0.50, T2, r, b, put_values[i][1], lambda);
			sum += PartialFloatLB(0, put_values[i][0], put_values[i][0], put_values[i][0], 0.75, T2, r, b, put_values[i][1], lambda);
		}
	}
	stop = clock();
	report("PartialFloatLB(put)", start, stop, niter * nelem * 3);

	return sum;
}

/* Page 66-67 */
static double speed_PartialFixedLB(void)
{
	/* We have test data for puts&calls, both with 3 vol's and three lookback periods. 
	 * We also have 2 values for X, either 90 or 110.
	 * The array contains X,v,fasit1,fasit2,fasit3, 6 rows.
	 * We check calls first, then puts. 
	 */
	double calls[6][5]  = {
		{  90.0, 0.10, 20.2845, 19.6239, 18.6244 },
		{  90.0, 0.20, 27.5385, 25.8126, 23.4957 },
		{  90.0, 0.30, 35.4578, 32.7172, 29.1473 },
		{ 110.0, 0.10,  4.0432,  3.9580,  3.7015 },
		{ 110.0, 0.20, 11.4895, 10.8995,  9.8244 },
		{ 110.0, 0.30, 19.7250, 18.4025, 16.2976 },
	};

	double put_values[6][5]  = {
		{  90.0, 0.10,  0.4973,  0.4632,  0.3863 },
		{  90.0, 0.20,  4.5863,  4.1925,  3.5831 },
		{  90.0, 0.30,  9.9348,  9.1111,  7.9267 },
		{ 110.0, 0.10, 12.6978, 10.9492,  9.1555 },
		{ 110.0, 0.20, 19.0255, 16.9433, 14.6505 },
		{ 110.0, 0.30, 25.2112, 22.8217, 20.0566 },
	};

	double sum = 0.0, S = 100.0, T2 = 1.0, r = 0.06, b = 0.06;
	size_t i, nelem = 6;
	size_t n, niter = 10*1000;

	clock_t start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			sum += PartialFixedLB(1, S, calls[i][0], 0.25, T2, r, b, calls[i][1]);
			sum += PartialFixedLB(1, S, calls[i][0], 0.50, T2, r, b, calls[i][1]);
			sum += PartialFixedLB(1, S, calls[i][0], 0.75, T2, r, b, calls[i][1]);
		}
	}
	clock_t stop = clock();
	report("PartialFixedLB(call)", start, stop, niter * nelem * 3);

	start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			sum += PartialFixedLB(0, S, put_values[i][0], 0.25, T2, r, b, put_values[i][1]);
			sum += PartialFixedLB(0, S, put_values[i][0], 0.50, T2, r, b, put_values[i][1]);
			sum += PartialFixedLB(0, S, put_values[i][0], 0.75, T2, r, b, put_values[i][1]);
		}
	}

	stop = clock();
	report("PartialFixedLB(put)", start, stop, niter * nelem * 3);
	return sum;
}

static double speed_TurnbullWakemanAsian(void)
{
	double sum = 0.0, SA = 88, X = 95.0, T = 0.5, T2 = 0.25, tau = 0.0, r = 0.07, b = 0.02, v = 0.25;
	size_t i, niter = 1000*1000;

	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += TurnbullWakemanAsian(0, 85 + i%10, SA, X, T, T2, tau, r, b, v);
	clock_t stop = clock();
	report("TurnbullWakemanAsian(put)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += TurnbullWakemanAsian(1, 85 + i%10, SA, X, T, T2, tau, r, b, v);
	stop = clock();
	report("TurnbullWakemanAsian(call)", start, stop, niter);

	return sum;
}

static double speed_FloatingStrikeLookback(void)
{
	double sum = 0.0;
	double S = 90.0, Smin = 100.0, T = 0.5, r = 0.10, b = r - 0.06, v = 0.30;
	size_t i, niter = 1000*1000;

	clock_t start = clock();
	for(i = 0; i < niter; i++)
		sum += FloatingStrikeLookback(1, S + i%40, Smin, Smin, T, r, b, v);
	clock_t stop = clock();
	report("FloatingStrikeLookback", start, stop, niter);
	return sum;
}

static double speed_LevyAsian(void)
{
	double sum = 0.0, S = 6.80, SA = 6.80, X = 6.90, T = 0.5, T2 = 0.5, r = 0.07, b = -0.02, v = 0.14;
	size_t i, niter = 1000*1000;

	clock_t start = clock();
	for(i = 0; i < niter; i++)
		sum += LevyAsian(0, S + ((i%10) * 1.0)/100, SA, X, T, T2, r, b, v);
	clock_t stop = clock();
	report("LevyAsian(put)", start, stop, niter);

	size_t iT2, nT2 = 3;
	size_t iv = 0, niv = 2;
	size_t iX = 0, nX = 3;

	niter = 40 * 1000;
	start = clock();
	for(i = 0; i < niter; i++) {
		S = SA = 100; T = 0.75; r = 0.10; b = 0.05;
		for(iX = 0, X = 95.0; iX < nX; iX++, X += 5.0) {
			for(iv = 0, v = 0.15; iv < niv; iv++, v += 0.20) {
				for(iT2 = 0, T2 = 0.75; iT2 < nT2; iT2++, T2 -= 0.25) {
					sum += LevyAsian(1, S, SA, X, T, T2, r, b, v);
				}
			}
		}
	}
	stop = clock();
	report("LevyAsian(call)", start, stop, niter * niv * nT2 * nX);
	return sum;
}

static double speed_SoftBarrier(void)
{
	double sum = 0.0, S = 100.0, X = 100.0, U = 95.0, r = 0.10, b = 0.05;

	/* Now we loop on L, T and v */
	size_t i, j, k;
	double L, T, v;
	size_t n, niter = 10*1000;

	/* Note that we start off from row ONE, not zero. That's because the test data contains
	 * a case where Upper == Lower, causing the function to return -inf.
	 */
	clock_t start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 1, L = 90.0; i < 10; i++, L -= 5.0) {
			for(j = 0, T = 0.5; j < 2; j++, T += 0.5) {
				for(k = 0, v = 0.10; k < 3; k++, v += 0.10) {
					sum += SoftBarrier(SB_CALL_DOWN_OUT, S, X, L, U, T, r, b, v);
				}
			}
		}
	}
	clock_t stop = clock();
	report("SoftBarrier(cdo)", start, stop, niter * 9 * 2 * 3);

	return sum;
}

static double speed_ForEquOptInDomCur(void)
{
	double sum = 0.0, S = 100, X = 160, T = 0.5, E = 1.5, r = 0.08, q = 0.05, vs=0.20, ve = 0.12, rho = 0.45;
	size_t i, niter = 1000*1000;

	clock_t start = clock();

	for(i = 0; i < niter; i++)
		sum += ForEquOptInDomCur(1, E, S - 10 + (i%20), X, T, r, q, vs, ve, rho);
	clock_t stop = clock();
	report("ForEquOptInDomCur",start, stop, niter);
	return sum;
}

double speed_LookBarrier(void)
{
	double sum = 0.0, S = 100.0, X = 100.0, T2 = 1.0, r = 0.10, b = 0.10;

	/* Test data for up&out LookBarrier calls 
	 * We combine data for H, t1 and v.
	 */
	struct {
		double v;
		double H;
		double fasit[5];
	} values[6] = {
		{0.15, 110.0, {17.5212,  9.6529,  4.2419,  1.7112, 0.2388}}, 
		{0.15, 120.0, {17.5212, 16.0504, 11.0593,  6.4404, 2.1866}}, 
		{0.15, 130.0, {17.5212, 17.0597, 14.9975, 11.1547, 5.5255}}, 
		{0.30, 110.0, {30.1874,  7.4146,  2.7025,  0.8896, 0.0357}}, 
		{0.30, 120.0, {30.1874, 16.4987,  7.5509,  3.1682, 0.4259}}, 
		{0.30, 130.0, {30.1874, 23.1605, 13.1118,  6.6034, 1.5180}}
	};

	size_t n, niter = 1*1000;
	size_t i, nelem = 6;

	clock_t start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < nelem; i++) {
			double t1;
			size_t j;

			for(j = 1, t1 = 0.25; j < 5; j++, t1 += 0.25)  {
				sum += LookBarrier(SB_CALL_UP_OUT, S, X, values[i].H, t1, T2, r, b, values[i].v);
			}
		}
	}
	clock_t stop = clock();
	report("LookBarrier()", start, stop, niter * nelem * 5);
	return sum;
}

static double speed_Quanto(void)
{
	double sum = 0.0, S = 100.0, X = 105.0, T = 0.5, Ep = 1.5, r = 0.08, rf = 0.05, q = 0.04, vS = 0.20, vE = 0.10, rho = 0.30;

	size_t i, niter = 3*1000*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += Quanto(1, Ep, S - 10 + i%20, X, T, r, rf, q, vS, vE, rho);
	clock_t stop = clock();
	report("Quanto(call)", start, stop, niter);

	start = clock();
	for(i = 0; i < niter; i++) 
		sum += Quanto(0, Ep, S - 10 + i%20, X, T, r, rf, q, vS, vE, rho);
	stop = clock();
	report("Quanto(put)", start, stop, niter);
	return sum;
}

static double speed_SimpleChooser(void)
{
	double sum = 0, S = 50.0, X = 50.0, T2 = 0.5, t1 = 0.25, r = 0.08, b = 0.08, v = 0.25;
	size_t i, niter = 3*1000*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += SimpleChooser(S - 10 + i%20, X, t1, T2, r, b, v);
	clock_t stop = clock();
	report("SimpleChooser()", start, stop, niter);
	return sum;
}

static double speed_TimeSwitchOption(void)
{
	double sum = 0;
	double S = 100, A = 5, X = 110, T = 1, dt = 1.0/365.0, r = 0.06, b = r, v = 0.26;
	int m = 0;
	size_t i, niter = 10*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += TimeSwitchOption(1, S, X, A, T, m, dt, r, b, v);
	clock_t stop = clock();
	report("TimeSwitchOption()", start, stop, niter);
	return sum;
}

static double speed_SpreadApproximation(void)
{
	double sum = 0;
	double F1 = 28, F2 = 20, X = 7, T = 0.25, r = 0.05, v1 = 0.29, v2 = 0.36, rho = 0.42;
	size_t i, niter = 2*1000*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += SpreadApproximation(1, F1 - 5 + i%5, F2 - 4 + i%6, X, T, r, v1, v2, rho);
	clock_t stop = clock();
	report("SpreadApproximation()", start, stop, niter);
	return sum;
}

static double speed_Swapoption(void)
{
	double sum = 0;
	double t1 = 4, m = 2, F = 0.07, X = 0.075, T = 2, r = 0.06, v = 0.20;
	size_t i, niter = 2*1000*1000;
	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += Swapoption(1, t1, m, F, X, T, r, v);
	clock_t stop = clock();
	report("Swapoption()", start, stop, niter);
	return sum;
}

static double speed_PartialTimeTwoAssetBarrier(void)
{
	struct {
		int type;
		double rho;
		double fasit[5];
	} values[6] = {
		{ SB_CALL_DOWN_OUT,  0.5, {14.9758, 12.3793, 10.9409, 10.2337, 9.8185}},
		{ SB_PUT_DOWN_OUT,   0.5, { 5.4595,  3.5109,  2.3609,  1.7502, 1.3607}},
		{ SB_CALL_DOWN_OUT,  0.0, {14.9758, 11.2067,  8.9828,  7.8016, 7.0480}},
		{ SB_PUT_DOWN_OUT,   0.0, { 5.4595,  4.0855,  3.2747,  2.8441, 2.5694}},
		{ SB_CALL_DOWN_OUT, -0.5, {14.9758,  9.8818,  6.8660,  5.2576, 4.2271}},
		{ SB_PUT_DOWN_OUT,  -0.5, { 5.4595,  4.5801,  4.1043,  3.8778, 3.7497}}
	};

	double sum = 0.0;
	double S1 = 100, S2 = 100, X = 100, H = 85, T2 = 1, r = 0.10, b1 = 0.10, b2 = 0.10, v1 = 0.25, v2 = 0.30;
	size_t i, j;
	size_t n, niter = 1*1000;

	clock_t start = clock();
	for(n = 0; n < niter; n++) {
		for(i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
			int type = values[i].type;
			double rho = values[i].rho;
			double t1;
			/* NOTE: If t1 == 0.0, then the function will fail. Why? Because we divide by t1 and division by 0.0
			 * is generally considered to be a bad thing.
			 */
			for(j = 1, t1 = 0.25; j < sizeof(values[0].fasit) / sizeof(values[0].fasit[0]); j++, t1 += 0.25) {
				sum += PartialTimeTwoAssetBarrier(type, S1, S2, X, H, t1, T2, r, b1, b2, v1, v2, rho);
			}
		}
	}
	clock_t stop = clock();
	report("PartialTimeTwoAssetBarrier", start, stop, niter * 6 * 4);
	return sum;
}

static double speed_TwoAssetBarrier(void)
{
	double sum = 0, rho = 0, S1 = 100.0, S2 = 100.0, T = 0.5, v1 = 0.20, v2 = 0.20, r = 0.08, b1 = 0.08, b2 = 0.08;
	double X = 100, H = 95;
	size_t i, niter = 100*1000;

	clock_t start = clock();
	for(i = 0; i < niter; i++) 
		sum += TwoAssetBarrier(SB_CALL_DOWN_OUT, S1, S2, X, H, T, r, b1, b2, v1, v2, rho);
	clock_t stop = clock();
	report("TwoAssetBarrier(cdo)", start, stop, niter);
	return sum;
}

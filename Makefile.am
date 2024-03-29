#FM=-ffast-math

AM_CFLAGS=-Winline -Wshadow $(FM) -O2 -DNDEBUG -pthread -std=c99\
	-Wno-misleading-indentation

lib_LIBRARIES=libmetaoptions.a 
EXTRA_DIST=$(man_MANS) src/TESTSUITE.README 
TESTS=check_options\
	TurnbullWakemanAsian_check\
	CashOrNothing_check\
	NewtonRaphson_check\
	RollGeskeWhaley_check\
	bisection_check\
	cnd_check\
	cbnd_check\
	ExtremeSpreadOption_check\
	PartialFloatLB_check \
	PartialFixedLB_check \
	FloatingStrikeLookback_check\
	StandardBarrier_check\
	DoubleBarrier_check\
	LevyAsian_check\
	SoftBarrier_check\
	BinaryBarrier_check\
	JumpDiffusion_check\
	EuropeanExchangeOption_check\
	AmericanExchangeOption_check\
	ExchangeExchangeOption_check\
	gbs_check\
	quanto_check\
	theta_check\
	delta_check\
	gamma_check\
	vega_check\
	carry_check\
	rho_check\
	blackscholes_check\
	black76_check\
	french_check\
	ExtendibleWriter_check\
	MiltersenSchwartz_check\
	PartialTimeTwoAssetBarrier_check\
	FixedStrikeLookback_check\
	Executive_check\
	SuperShare_check\
	TwoAssetBarrier_check\
	AssetOrNothing_check\
	ComplexChooser_check\
	TimeSwitchOption_check\
	GapOption_check\
	SimpleChooser_check\
	Swapoption_check\
	BSAmericanApprox_check\
	SpreadApproximation_check\
	EquityLinkedFXO_check\
	ForwardStartOption_check\
	OptionsOnOptions_check\
	BAWbisection_check\
	ForEquOptInDomCur_check\
	GeometricAverageRateOption_check\
	DiscreteAdjustedBarrier_check\
	PartialTimeBarrier_check\
	OptionsOnTheMaxMin_check\
	TakeoverFXoption_check\
	TwoAssetCashOrNothing_check\
	TwoAssetCorrelation_check\
	GarmanKohlhagen_check\
	merton73_check\
	speed_options

# Broken tests, mostly due to errors in test data or lack of test data
# BSbisection_check VasicekBondOption_check VasicekBondPrice_check
# LookBarrier_check: cbnd() fails because a^2 == b^2(-a == b), so we get a divide by zero.
# BAWAmericanApprox_check: Lack of proper test data.

include_HEADERS=src/metaoptions.h

libmetaoptions_a_CFLAGS=$(FM) -O3 -std=c99 \
	-Werror -Wshadow -W -Wall -pedantic -DNDEBUG -Wmissing-prototypes

libmetaoptions_a_SOURCES=\
	src/AmericanExchangeOption.c\
	src/AssetOrNothing.c\
	src/BAWAmericanApprox.c\
	src/BAWbisection.c\
	src/BinaryBarrier.c\
	src/bisection.c\
	src/black76.c\
	src/blackscholes.c\
	src/BSAmericanApprox.c\
	src/BSbisection.c\
	src/CashOrNothing.c\
	src/cbnd.c\
	src/cnd.c\
	src/ComplexChooser.c\
	src/DiscreteAdjustedBarrier.c\
	src/DoubleBarrier.c\
	src/EquityLinkedFXO.c\
	src/EuropeanExchangeOption.c\
	src/Executive.c\
	src/ExtendibleWriter.c\
	src/ExtremeSpreadOption.c\
	src/FixedStrikeLookback.c\
	src/FloatingStrikeLookback.c\
	src/ForEquOptInDomCur.c\
	src/ForwardStartOption.c\
	src/GapOption.c\
	src/gbs.c\
	src/carry.c\
	src/delta.c\
	src/GeometricAverageRateOption.c\
	src/french.c\
	src/gamma.c\
	src/rho.c\
	src/theta.c\
	src/vega.c\
	src/JumpDiffusion.c\
	src/LevyAsian.c\
	src/LookBarrier.c\
	src/GarmanKohlhagen.c\
	src/merton73.c\
	src/MiltersenSwartz.c\
	src/NewtonRaphson.c\
	src/OptionsOnOptions.c\
	src/OptionsOnTheMaxMin.c\
	src/PartialFixedLB.c\
	src/PartialFloatLB.c\
	src/PartialTimeBarrier.c\
	src/PartialTimeTwoAssetBarrier.c\
	src/Quanto.c\
	src/RollGeskeWhaley.c\
	src/SimpleChooser.c\
	src/SoftBarrier.c\
	src/SpreadApproximation.c\
	src/StandardBarrier.c\
	src/SuperShare.c\
	src/Swapoption.c\
	src/TakeoverFXoption.c\
	src/TimeSwitchOption.c\
	src/TurnbullWakemanAsian.c\
	src/TwoAssetBarrier.c\
	src/TwoAssetCashOrNothing.c\
	src/TwoAssetCorrelation.c\
	src/ExchangeExchangeOption.c\
	src/VasicekBondOption.c\
	src/VasicekBondPrice.c

# We exclude the tree-functions right now, because they allocate memory
# and the API is not suitable for error handling.
#
# src/ThreeDimensionalBinominal.c
# src/ImpliedTrinominalTree.c # Uses transpose() in a weird way
#
# Works fine, but no proper error handling
# src/TrinominalTree.c 
# src/BarrierBinominal.c
# src/CRRBinominal.c
# src/ConvertibleBond.c
#
check_PROGRAMS= $(TESTS)

man_MANS=\
	doc/AmericanExchangeOption.3\
	doc/AssetOrNothing.3\
	doc/BAWAmericanApprox.3\
	doc/BAWbisection.3\
	doc/BinaryBarrier.3\
	doc/bisection.3\
	doc/black76.3\
	doc/blackscholes.3\
	doc/BSAmericanCallApprox.3\
	doc/BSbisection.3\
	doc/CashOrNothing.3\
	doc/cbnd.3\
	doc/cnd.3\
	doc/ComplexChooser.3\
	doc/ConvertibleBond.3\
	doc/CRRBinominal.3\
	doc/DiscreteAdjustedBarrier.3\
	doc/DoubleBarrier.3\
	doc/EquityLinkedFXO.3\
	doc/EuropeanExchangeOption.3\
	doc/ExchangeExchangeOption.3\
	doc/Executive.3\
	doc/ExtendibleWriter.3\
	doc/ExtremeSpreadOption.3\
	doc/FixedStrikeLookback.3\
	doc/FloatingStrikeLookback.3\
	doc/ForEquOptInDomCur.3\
	doc/ForwardStartOption.3\
	doc/GapOption.3\
	doc/gbs.3\
	doc/gbs_call.3\
	doc/gbs_put.3\
	doc/carry.3\
	doc/delta.3\
	doc/delta_call.3\
	doc/delta_put.3\
	doc/GeometricAverageRateOption.3\
	doc/french.3\
	doc/gamma.3\
	doc/rho.3\
	doc/theta.3\
	doc/vega.3\
	doc/ImpliedTrinominalTree.3\
	doc/JumpDiffusion.3\
	doc/LevyAsian.3\
	doc/GarmanKohlhagen.3\
	doc/merton73.3\
	doc/MiltersenSchwartz.3\
	doc/NewtonRaphson.3\
	doc/normdist.3\
	doc/OptionsOnOptions.3\
	doc/OptionsOnTheMaxMin.3\
	doc/PartialFixedLB.3\
	doc/PartialFloatLB.3\
	doc/PartialTimeBarrier.3\
	doc/pow2.3\
	doc/Quanto.3\
	doc/RollGeskeWhaley.3\
	doc/sign.3\
	doc/SimpleChooser.3\
	doc/SpreadApproximation.3\
	doc/StandardBarrier.3\
	doc/SuperShare.3\
	doc/Swapoption.3\
	doc/TakeoverFXoption.3\
	doc/ThreeDimensionalBinominal.3\
	doc/TimeSwitchOption.3\
	doc/TrinominalTree.3\
	doc/TurnbullWakemanAsian.3\
	doc/TwoAssetBarrier.3\
	doc/TwoAssetCashOrNothing.3\
	doc/TwoAssetCorrelation.3\
	doc/VasicekBondOption.3\
	doc/VasicekBondPrice.3

speed_options_CFLAGS=-Wshadow $(FM) -O3 -std=c99 -W -Wall -pedantic 
speed_options_LDADD=-L. -lmetaoptions -lm
speed_options_SOURCES=src/speed_options.c 

check_options_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb
check_options_LDADD=-L. -lmetaoptions -lm
check_options_SOURCES=src/check_options.c 

ExtremeSpreadOption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DEXTREMESPREADOPTION_CHECK
ExtremeSpreadOption_check_LDADD=-lm
ExtremeSpreadOption_check_SOURCES=src/ExtremeSpreadOption.c src/cnd.c

PartialFloatLB_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DPARTIALFLOATLB_CHECK
PartialFloatLB_check_LDADD=-lm
PartialFloatLB_check_SOURCES=src/PartialFloatLB.c src/cbnd.c src/cnd.c

PartialFixedLB_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DPARTIALFIXEDLB_CHECK
PartialFixedLB_check_LDADD=-lm
PartialFixedLB_check_SOURCES=src/PartialFixedLB.c src/cbnd.c src/cnd.c

FixedStrikeLookback_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DFIXEDSTRIKELOOKBACK_CHECK
FixedStrikeLookback_check_LDADD=-lm
FixedStrikeLookback_check_SOURCES=src/FixedStrikeLookback.c src/cnd.c

FloatingStrikeLookback_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DFLOATINGSTRIKELOOKBACK_CHECK
FloatingStrikeLookback_check_LDADD=-lm
FloatingStrikeLookback_check_SOURCES=src/FloatingStrikeLookback.c src/cnd.c

# BAWAmericanApprox_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DBAWAMERICANAPPROX_CHECK
# BAWAmericanApprox_check_LDADD=-lm
# BAWAmericanApprox_check_SOURCES=src/BAWAmericanApprox.c src/gbs.c src/cnd.c src/black76.c

StandardBarrier_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DSTANDARDBARRIER_CHECK
StandardBarrier_check_LDADD=-lm
StandardBarrier_check_SOURCES=src/StandardBarrier.c src/cnd.c 

PartialTimeTwoAssetBarrier_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DPARTIALTIMETWOASSETBARRIER_CHECK
PartialTimeTwoAssetBarrier_check_LDADD=-lm
PartialTimeTwoAssetBarrier_check_SOURCES=src/PartialTimeTwoAssetBarrier.c src/cbnd.c src/cnd.c src/gbs.c

cbnd_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DCBND_CHECK
cbnd_check_LDADD=-lm
cbnd_check_SOURCES=src/cbnd.c src/cnd.c 

cnd_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DCND_CHECK
cnd_check_LDADD=-lm
cnd_check_SOURCES=src/cnd.c 

# LookBarrier_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DLOOKBARRIER_CHECK
# LookBarrier_check_LDADD=-lm
# LookBarrier_check_SOURCES=src/LookBarrier.c src/cnd.c src/cbnd.c src/PartialFixedLB.c

DoubleBarrier_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DDOUBLEBARRIER_CHECK
DoubleBarrier_check_LDADD=-lm
DoubleBarrier_check_SOURCES=src/DoubleBarrier.c src/gbs.c src/cnd.c 

SoftBarrier_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DSOFTBARRIER_CHECK
SoftBarrier_check_LDADD=-lm
SoftBarrier_check_SOURCES=src/SoftBarrier.c src/gbs.c src/cnd.c 

LevyAsian_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DLEVYASIAN_CHECK
LevyAsian_check_LDADD=-lm
LevyAsian_check_SOURCES=src/LevyAsian.c src/cnd.c

BinaryBarrier_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DBINARYBARRIER_CHECK
BinaryBarrier_check_LDADD=-lm
BinaryBarrier_check_SOURCES=src/BinaryBarrier.c src/cnd.c

JumpDiffusion_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DJUMPDIFFUSION_CHECK
JumpDiffusion_check_LDADD=-lm
JumpDiffusion_check_SOURCES=src/JumpDiffusion.c src/gbs.c src/cnd.c


AmericanExchangeOption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DAMERICANEXCHANGEOPTION_CHECK
AmericanExchangeOption_check_LDADD=-lm
AmericanExchangeOption_check_SOURCES=src/AmericanExchangeOption.c src/BSAmericanApprox.c src/gbs.c src/cnd.c

EuropeanExchangeOption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DEUROPEANEXCHANGEOPTION_CHECK
EuropeanExchangeOption_check_LDADD=-lm
EuropeanExchangeOption_check_SOURCES=src/EuropeanExchangeOption.c src/cnd.c

MiltersenSchwartz_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DMILTERSENSCHWARTZ_CHECK
MiltersenSchwartz_check_LDADD=-lm
# Slight typo in filename
MiltersenSchwartz_check_SOURCES=src/MiltersenSwartz.c src/cnd.c

ExchangeExchangeOption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DEXCHANGEEXCHANGEOPTION_CHECK
ExchangeExchangeOption_check_LDADD=-lm
ExchangeExchangeOption_check_SOURCES=src/ExchangeExchangeOption.c src/cnd.c src/cbnd.c

SuperShare_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DSUPERSHARE_CHECK
SuperShare_check_LDADD=-lm
SuperShare_check_SOURCES=src/SuperShare.c src/cnd.c

NewtonRaphson_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DNEWTONRAPHSON_CHECK
NewtonRaphson_check_LDADD=-lm
NewtonRaphson_check_SOURCES=src/NewtonRaphson.c src/gbs.c src/vega.c src/blackscholes.c src/cnd.c

bisection_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DBISECTION_CHECK
bisection_check_LDADD=-lm
bisection_check_SOURCES=src/bisection.c src/gbs.c src/cnd.c

CashOrNothing_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DCASHORNOTHING_CHECK
CashOrNothing_check_LDADD=-lm
CashOrNothing_check_SOURCES=src/CashOrNothing.c src/cnd.c

TwoAssetBarrier_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DTWOASSETBARRIER_CHECK
TwoAssetBarrier_check_LDADD=-lm
TwoAssetBarrier_check_SOURCES=src/TwoAssetBarrier.c src/gbs.c src/cbnd.c src/cnd.c

TurnbullWakemanAsian_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DTURNBULLWAKEMANASIAN_CHECK
TurnbullWakemanAsian_check_LDADD=-lm
TurnbullWakemanAsian_check_SOURCES=src/TurnbullWakemanAsian.c src/gbs.c src/cnd.c

AssetOrNothing_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DASSETORNOTHING_CHECK
AssetOrNothing_check_LDADD=-lm
AssetOrNothing_check_SOURCES=src/AssetOrNothing.c src/cnd.c

ComplexChooser_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DCOMPLEXCHOOSER_CHECK
ComplexChooser_check_LDADD=-lm
ComplexChooser_check_SOURCES=src/ComplexChooser.c src/cnd.c src/cbnd.c src/gbs.c src/delta.c

TimeSwitchOption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DTIMESWITCHOPTION_CHECK
TimeSwitchOption_check_LDADD=-lm
TimeSwitchOption_check_SOURCES=src/TimeSwitchOption.c src/cnd.c

GapOption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGAPOPTION_CHECK
GapOption_check_LDADD=-lm
GapOption_check_SOURCES=src/GapOption.c src/cnd.c

SimpleChooser_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DSIMPLECHOOSER_CHECK
SimpleChooser_check_LDADD=-lm
SimpleChooser_check_SOURCES=src/SimpleChooser.c src/cnd.c

Swapoption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DSWAPOPTION_CHECK
Swapoption_check_LDADD=-lm
Swapoption_check_SOURCES=src/Swapoption.c src/cnd.c

BSAmericanApprox_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DBSAMERICANAPPROX_CHECK
BSAmericanApprox_check_LDADD=-lm
BSAmericanApprox_check_SOURCES=src/BSAmericanApprox.c src/cnd.c src/gbs.c

SpreadApproximation_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DSPREADAPPROXIMATION_CHECK
SpreadApproximation_check_LDADD=-lm
SpreadApproximation_check_SOURCES=src/SpreadApproximation.c src/cnd.c src/gbs.c

EquityLinkedFXO_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DEQUITYLINKEDFXO_CHECK
EquityLinkedFXO_check_LDADD=-lm
EquityLinkedFXO_check_SOURCES=src/EquityLinkedFXO.c src/cnd.c

ForwardStartOption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DFORWARDSTARTOPTION_CHECK
ForwardStartOption_check_LDADD=-lm
ForwardStartOption_check_SOURCES=src/ForwardStartOption.c src/gbs.c src/cnd.c

OptionsOnOptions_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DOPTIONSONOPTIONS_CHECK
OptionsOnOptions_check_LDADD=-lm
OptionsOnOptions_check_SOURCES=src/OptionsOnOptions.c src/gbs.c src/delta.c src/cbnd.c src/cnd.c

GeometricAverageRateOption_check_CFLAGS=-Wshadow -ffast-math -O0 -std=c99 -W -Wall -pedantic -ggdb -DGEOMETRICAVERAGERATEOPTION_CHECK
GeometricAverageRateOption_check_LDADD=-lm
GeometricAverageRateOption_check_SOURCES=src/GeometricAverageRateOption.c src/gbs.c src/cnd.c

BAWbisection_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DBAWBISECTION_CHECK
BAWbisection_check_LDADD=-lm
BAWbisection_check_SOURCES=src/BAWbisection.c src/BAWAmericanApprox.c src/gbs.c src/cnd.c

# BSbisection_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DBSBISECTION_CHECK
# BSbisection_check_LDADD=-lm
# BSbisection_check_SOURCES=src/BSbisection.c src/BSAmericanApprox.c src/gbs.c src/cnd.c

rho_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGRHO_CHECK
rho_check_LDADD=-lm
rho_check_SOURCES=src/rho.c src/cnd.c src/gbs.c

ForEquOptInDomCur_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DFOREQUOPTINDOMCUR_CHECK
ForEquOptInDomCur_check_LDADD=-lm
ForEquOptInDomCur_check_SOURCES=src/ForEquOptInDomCur.c src/cnd.c

DiscreteAdjustedBarrier_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DDISCRETEADJUSTEDBARRIER_CHECK
DiscreteAdjustedBarrier_check_LDADD=-lm
DiscreteAdjustedBarrier_check_SOURCES=src/DiscreteAdjustedBarrier.c 

PartialTimeBarrier_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DPARTIALTIMEBARRIER_CHECK
PartialTimeBarrier_check_LDADD=-lm
PartialTimeBarrier_check_SOURCES=src/PartialTimeBarrier.c src/cbnd.c src/cnd.c

merton73_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DMERTON73_CHECK
merton73_check_LDADD=-lm
merton73_check_SOURCES=src/merton73.c src/cnd.c

OptionsOnTheMaxMin_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DOPTIONSONTHEMAXMIN_CHECK
OptionsOnTheMaxMin_check_LDADD=-lm
OptionsOnTheMaxMin_check_SOURCES=src/OptionsOnTheMaxMin.c src/EuropeanExchangeOption.c src/cbnd.c src/cnd.c

TakeoverFXoption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DTAKEOVERFXOPTION_CHECK
TakeoverFXoption_check_LDADD=-lm
TakeoverFXoption_check_SOURCES=src/TakeoverFXoption.c src/cbnd.c src/cnd.c

TwoAssetCorrelation_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DTWOASSETCORRELATION_CHECK
TwoAssetCorrelation_check_LDADD=-lm
TwoAssetCorrelation_check_SOURCES=src/TwoAssetCorrelation.c src/cbnd.c src/cnd.c

TwoAssetCashOrNothing_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DTWOASSETCASHORNOTHING_CHECK
TwoAssetCashOrNothing_check_LDADD=-lm
TwoAssetCashOrNothing_check_SOURCES=src/TwoAssetCashOrNothing.c src/cbnd.c src/cnd.c

# VasicekBondPrice_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DVASICEKBONDPRICE_CHECK
# VasicekBondPrice_check_LDADD=-lm
# VasicekBondPrice_check_SOURCES=src/VasicekBondPrice.c src/cnd.c

# VasicekBondOption_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DVASICEKBONDOPTION_CHECK
# VasicekBondOption_check_LDADD=-lm
# VasicekBondOption_check_SOURCES=src/VasicekBondOption.c src/VasicekBondPrice.c src/cnd.c

gbs_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGBS_CHECK
gbs_check_LDADD=-lm
gbs_check_SOURCES=src/gbs.c src/cnd.c

theta_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGTHETA_CHECK
theta_check_LDADD=-lm
theta_check_SOURCES=src/theta.c src/cnd.c

delta_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGDELTA_CHECK
delta_check_LDADD=-lm
delta_check_SOURCES=src/delta.c src/cnd.c

carry_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGCARRY_CHECK
carry_check_LDADD=-lm
carry_check_SOURCES=src/carry.c src/cnd.c

black76_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DBLACK76_CHECK
black76_check_LDADD=-lm
black76_check_SOURCES=src/black76.c src/cnd.c

blackscholes_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DBLACKSCHOLES_CHECK
blackscholes_check_LDADD=-lm
blackscholes_check_SOURCES=src/blackscholes.c src/cnd.c

gamma_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGGAMMA_CHECK
gamma_check_LDADD=-lm
gamma_check_SOURCES=src/gamma.c 

french_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGFRENCH_CHECK
french_check_LDADD=-lm
french_check_SOURCES=src/french.c src/cnd.c

vega_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGVEGA_CHECK
vega_check_LDADD=-lm
vega_check_SOURCES=src/vega.c 

quanto_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DQUANTO_CHECK
quanto_check_LDADD=-lm
quanto_check_SOURCES=src/Quanto.c src/cnd.c

RollGeskeWhaley_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DROLLGESKEWHALEY_CHECK
RollGeskeWhaley_check_LDADD=-lm
RollGeskeWhaley_check_SOURCES=src/RollGeskeWhaley.c src/blackscholes.c src/cbnd.c src/cnd.c

ExtendibleWriter_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DEXTENDIBLEWRITER_CHECK
ExtendibleWriter_check_LDADD=-lm
ExtendibleWriter_check_SOURCES=src/ExtendibleWriter.c src/gbs.c src/cbnd.c src/cnd.c


Executive_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DEXECUTIVE_CHECK
Executive_check_LDADD=-lm
Executive_check_SOURCES=src/Executive.c src/gbs.c src/cnd.c


GarmanKohlhagen_check_CFLAGS=-Wshadow $(FM) -O0 -std=c99 -W -Wall -pedantic -ggdb -DGARMANKOHLHAGEN_CHECK
GarmanKohlhagen_check_LDADD=-lm
GarmanKohlhagen_check_SOURCES=src/GarmanKohlhagen.c src/cnd.c


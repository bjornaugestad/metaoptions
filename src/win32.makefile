# What we are building:
# 1. A DLL which can be used by other applications, e.g. MS Excel 2007
#    and TradeStation 8.
# 2. Later on, we will add wrappers for stuff like MS SQL Server 2005
#    and C#/.NET.

# How we are building it:
# We use Microsoft C to build everything, just to be on the safe side.
#

# Installation:
# Can we create install files using MS C++ Express? Hardly.

.suffixes: .obj .c .dll .lib

%.c %.obj:
	$(CC) $(CFLAGS) /c $*.c
	

CC=cl.exe
CFLAGS=/W3 /Wp64 /nologo /WL /arch:SSE2 

OBJ=\
	AmericanExchangeOption.obj AssetOrNothing.obj\
	BAWAmericanApprox.obj BAWbisection.obj\
	BSAmericanApprox.obj BSbisection.obj\
	BarrierBinominal.obj BinaryBarrier.obj\
	CRRBinominal.obj CashOrNothing.obj\
	ComplexChooser.obj ConvertibleBond.obj\
	DiscreteAdjustedBarrier.obj DoubleBarrier.obj\
	EquityLinkedFXO.obj EuropeanExchangeOption.obj\
	ExchangeExchangeOption.obj Executive.obj\
	ExtendibleWriter.obj ExtremeSpreadOption.obj\
	FixedStrikeLookback.obj FloatingStrikeLookback.obj\
	ForEquOptInDomCur.obj ForwardStartOption.obj\
	GapOption.obj GeometricAverageRateOption.obj\
	JumpDiffusion.obj LevyAsian.obj\
	LookBarrier.obj MiltersenSwartz.obj\
	NewtonRaphson.obj OptionsOnOptions.obj\
	OptionsOnTheMaxMin.obj PartialFixedLB.obj\
	PartialFloatLB.obj PartialTimeBarrier.obj\
	PartialTimeTwoAssetBarrier.obj Quanto.obj\
	RollGeskeWhaley.obj SimpleChooser.obj\
	SoftBarrier.obj SpreadApproximation.obj\
	StandardBarrier.obj SuperShare.obj\
	Swapoption.obj TakeoverFXoption.obj\
	TimeSwitchOption.obj\
	TurnbullWakemanAsian.obj\
	TwoAssetBarrier.obj TwoAssetCashOrNothing.obj\
	TwoAssetCorrelation.obj VasicekBondOption.obj\
	VasicekBondPrice.obj bisection.obj\
	black76.obj blackscholes.obj\
	cbnd.obj cnd.obj gbs.obj\
	gcarry.obj gdelta.obj\
	gfrench.obj ggamma.obj\
	grho.obj gtheta.obj\
	gvega.obj merton73.obj

TARGET=metaoptions.dll


all: $(TARGET)
	echo "done"

$(TARGET): $(OBJ)
	echo "done"
	$(CC) /LD /MT /out:$(TARGET) $(OBJ)


clean:
	rm -f $(OBJ)

SRC=\
	AmericanExchangeOption.c AssetOrNothing.c BarrierBinominal.c\
	BAWAmericanApprox.c BAWbisection.c BinaryBarrier.c\
	bisection.c black76.c blackscholes.c BSAmericanApprox.c\
	BSbisection.c CashOrNothing.c cbnd.c \
	cnd.c ComplexChooser.c ConvertibleBond.c CRRBinominal.c\
	DiscreteAdjustedBarrier.c DoubleBarrier.c EquityLinkedFXO.c\
	EuropeanExchangeOption.c ExchangeExchangeOption.c Executive.c\
	ExtendibleWriter.c ExtremeSpreadOption.c FixedStrikeLookback.c\
	FloatingStrikeLookback.c ForEquOptInDomCur.c ForwardStartOption.c\
	GapOption.c gbs.c gcarry.c gdelta.c\
	GeometricAverageRateOption.c gfrench.c grho.c gtheta.c\
	gvega.c ImpliedTrinominalTree.c JumpDiffusion.c LevyAsian.c\
	LookBarrier.c merton73.c MiltersenSwartz.c NewtonRaphson.c\
	OptionsOnOptions.c OptionsOnTheMaxMin.c PartialFixedLB.c\
	PartialFloatLB.c PartialTimeBarrier.c PartialTimeTwoAssetBarrier.c\
	Quanto.c RollGeskeWhaley.c SimpleChooser.c SoftBarrier.c\
	SpreadApproximation.c StandardBarrier.c SuperShare.c\
	Swapoption.c TakeoverFXoption.c ThreeDimensionalBinominal.c\
	TimeSwitchOption.c TrinominalTree.c TurnbullWakemanAsian.c\
	TwoAssetBarrier.c TwoAssetCashOrNothing.c TwoAssetCorrelation.c\
	VasicekBondOption.c VasicekBondPrice.c

HEADERS=metaoptions.h
EXTRA_DIST=TESTSUITE.README INSTALL README NEWS ChangeLog speed_options.c check_options.c Makefile
DISTNAME=metaoptions-0.0.1.tar.gz

OBJ=$(subst .c,.o, $(SRC))
TARGET=libmetaoptions.a
#CFLAGS_BASE=-std=c89 -W -Wall -pedantic -ffast-math
CFLAGS_BASE=-W -Wall -pedantic -ffast-math -Werror -ansi -Wmissing-prototypes
CFLAGS_DEBUG=-O0 -ggdb 
CFLAGS_RELEASE=-O3 -DNDEBUG
#CFLAGS=$(CFLAGS_BASE) $(CFLAGS_DEBUG)
CFLAGS=$(CFLAGS_BASE) $(CFLAGS_RELEASE)

ARFLAGS=crus

INSTALLROOT=/usr/local

LDFLAGS=-L. -lmetaoptions -lm

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $+

clean:
	rm -f *.o $(TARGET) check_options speed_options

check: check_options 
	./check_options

speed: speed_options
	./speed_options

check_options: check_options.o $(TARGET)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

speed_options: speed_options.c $(TARGET)
	$(CC) $(CFLAGS) -Wno-unused-function -o $@ $< $(LDFLAGS)

dist: $(TARGET)
	tar zcf $(DISTNAME) $(SRC) $(HEADERS) $(EXTRA_DIST) 

zip: $(TARGET)
	-(test -f metaoptions.zip && rm -f metaoptions.zip)
	zip -l -q metaoptions.zip $(SRC) $(HEADERS) $(EXTRA_DIST) 

install: $(TARGET) 
	cp metaoptions.h $(INSTALLROOT)/include
	cp $(TARGET) $(INSTALLROOT)/lib


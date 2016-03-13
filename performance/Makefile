CFLAGS=-DNDEBUG -O3 -march=native -mtune=native -msse4.2 -save-temps -dp
TARGETS=stock_c check_cnd

all: $(TARGETS)

stock_c: stock_c.o cnd.o blackscholes.o
	$(CC) $(CFLAGS) -o $@ $+ -lm

check_cnd: check_cnd.o cnd.o
	$(CC) $(CFLAGS) -o $@ $+ -lm

clean:
	rm -f $(TARGETS) *.o *.i

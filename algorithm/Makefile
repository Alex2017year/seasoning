CFXXFLAGS=-g -Wall -O0

BINARIES=QuickSort

OUTSIDER=../
INCLUDES=-I$(OUTSIDER)

all: $(BINARIES)

# just like a pattern
$(BINARIES):
	g++ $(CFXXFLAGS) $(filter %.cc %.hpp %.c,$^) $(INCLUDES) -o $@

QuickSort: QuickSort.hpp

clean
	rm -f $(BINARIES)


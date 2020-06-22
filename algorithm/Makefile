CFXXFLAGS=-g -Wall -O0

BINARIES=QuickSort

all: $(BINARIES)

# just like a pattern
$(BINARIES):
	g++ $(CFXXFLAGS) $(filter %.cc %.hpp %.c,$^) -o $@

QuickSort: QuickSort.hpp

clean:
	rm -f $(BINARIES)


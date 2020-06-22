CFXXFLAGS=-g -Wall -O0

BINARIES=QuickSort

all: $(BINARIES)

# just like a pattern
$(BINARIES):
	g++ $(CFXXFLAGS) $(filter %.cc %.cpp,$^) -o $@

QuickSort: QuickSort.cc

clean:
	rm -f $(BINARIES)


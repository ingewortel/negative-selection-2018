all : contiguous-fa-lang contiguous-fa countpaths mjc-fa contiguous-negative-selection-lang makerep-contiguous-fa makerep-contiguous-fa-lang contiguous-negative-selection

CXXFLAGS=-O3 -std=c++0x
FSTLIB=-lfst

FSTFLAGS=#-L /usr/local/Cellar/openfst/1.6.3/lib/ -I /usr/local/Cellar/openfst/1.6.3/include/ 

%-fa : %-fa.cpp dfa.hpp idfa.hpp refinable-partition.hpp aminoacids.hpp miyazawa-jernigan-matrix.hpp
	$(CXX) $(CXXFLAGS) -o $*-fa $*-fa.cpp

printlang: printlang.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

countpaths: countpaths.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

contiguous-negative-selection-lang : contiguous-negative-selection-lang.cpp latinalphabet.hpp
	$(CXX) $(FSTFLAGS) $(CXXFLAGS) -o $@ $< -lfst

contiguous-negative-selection : contiguous-negative-selection.cpp aminoacids.hpp
	$(CXX) $(FSTFLAGS) $(CXXFLAGS) -o $@ $< -lfst

clean : 
	rm -f contiguous-fa-lang contiguous-fa countpaths mjc-fa pattern-fa contiguous-negative-selection-lang pattern-exact-fa makerep-contiguous-fa makerep-contiguous-fa-lang makerep-pattern-exact-fa contiguous-negative-selection

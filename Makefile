CXX = g++-5
CXXFLAGS = -std=c++14 -g3 -O2

FILES = $(shell find . -name "*.cpp")
INCLUDE = /home/per/Code/gaia/src
LDFLAGS = -larmadillo

gaia: $(OBJ)
	$(CXX) $(CXXFLAGS) -o gaia $(FILES) -I$(INCLUDE) $(LDFLAGS)


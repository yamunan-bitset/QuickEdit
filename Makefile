OBJS     = src/qui.o
CXXFLAGS = -std=c++17
CXX      = g++
OUT      = qui

build: $(OBJS)
	$(CXX) -o $(OUT) $(OBJS) $(CXXFLAGS)
clean:
	rm -rf $(OUT)

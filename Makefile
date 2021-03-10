OBJS     = src/qui.o
CXXFLAGS = -std=c++17
CXX      = g++
OUT      = qui
PATH     = /usr/bin/

build: clean $(OBJS)
	$(CXX) -o $(OUT) $(OBJS) $(CXXFLAGS)
clean:
	rm -rf $(OUT) $(OBJS)

install:
	sudo cp $(OUT) $(PATH)

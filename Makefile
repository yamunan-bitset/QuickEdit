OBJS = qui.o handle.o
CXX = g++
OUT = qui

build: $(OBJS)
	$(CXX) -o $(OUT)

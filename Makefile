OBJS = src/handle.o src/qui.o
CXX = g++
OUT = qui

build: $(OBJS)
	$(CXX) -o $(OUT)

clean:
	rm -rf $(OUT) $(OBJS)

FILES = src/less.cc src/handle.cc src/qui.cc
CXX   = g++
OUT   = qui

build:
	$(CXX) -o $(OUT) $(FILES)
clean:
	rm -rf $(OUT) $(OBJS)

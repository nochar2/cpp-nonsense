all: chrono invert-bits

chrono: chrono.cpp
	g++ -std=c++20 $< -o $@
invert-bits: invert-bits.cpp
	g++ -std=c++23 $< -o $@
clean:
	rm chrono invert-bits

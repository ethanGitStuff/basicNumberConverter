build: main.cpp
	clang++ -o main.o main.cpp

run: main.o
	./main.o

br: main.cpp
	clang++ -o main.o main.cpp
	./main.o

clean: main.o
	rm main.o
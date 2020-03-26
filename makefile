all: programm

programm: build/main.o build/pars.o build/circle.o
	g++ -Wall -Werror build/main.o build/pars.o build/circle.o

build/main.o: src/main.cpp
	g++ -Wall -Werror -c src/main.cpp

build/pars.o: src/pars.cpp
	g++ -Wall -Werror -c src/pars.cpp

build/circle.o: src/circle.cpp
	g++ -Wall -Werror -c src/circle.cpp
clean:
	rm -rf build/*.o
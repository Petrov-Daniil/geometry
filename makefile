all: programm

programm: src/main.o src/pars.o src/circle.o
	g++ -Wall -Werror src/main.o src/pars.o src/circle.o

main.o: src/main.cpp
	g++ -Wall -Werror -c src/main.cpp

pars.o: src/pars.cpp
	g++ -Wall -Werror -c src/pars.cpp

circle.o: src/circle.cpp
	g++ -Wall -Werror -c src/circle.cpp
clean:
	rm -rf src/*.o
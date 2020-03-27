all: bin/programm

bin/programm: build/main.o build/pars.o build/circle.o build/perimeter.o
	g++ -Wall -Werror build/main.o build/pars.o build/circle.o build/perimeter.o -o bin/programm

build/main.o: src/main.cpp
	g++ -Wall -Werror -c src/main.cpp -o build/main.o

build/pars.o: src/pars.cpp
	g++ -Wall -Werror -c src/pars.cpp -o build/pars.o

build/circle.o: src/circle.cpp
	g++ -Wall -Werror -c src/circle.cpp -o build/circle.o

build/perimeter.o: src/perimeter.cpp
	g++ -Wall -Werror -c src/perimeter.cpp -o build/perimeter.o
	
clean:
	rm -rf build/*.o
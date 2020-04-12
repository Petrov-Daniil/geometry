CFLAGS = -Wall -Werror
USER_DIR_S = build/src
USER_DIR_T = build/test
EXECUTABLE = bin/programm
TEST = bin/test

all: $(EXECUTABLE) bin/test

$(EXECUTABLE): $(USER_DIR_S)/main.o $(USER_DIR_S)/pars.o $(USER_DIR_S)/circle.o $(USER_DIR_S)/perimeter.o
	g++ $(CFLAGS) $(USER_DIR_S)/main.o $(USER_DIR_S)/pars.o $(USER_DIR_S)/circle.o $(USER_DIR_S)/perimeter.o -o $(EXECUTABLE)

$(USER_DIR_S)/main.o: src/main.cpp
	g++ $(CFLAGS) -c src/main.cpp -o $(USER_DIR_S)/main.o

$(USER_DIR_S)/pars.o: src/pars.cpp
	g++ $(CFLAGS) -c src/pars.cpp -o $(USER_DIR_S)/pars.o

$(USER_DIR_S)/circle.o: src/circle.cpp
	g++ $(CFLAGS) -c src/circle.cpp -o $(USER_DIR_S)/circle.o

$(USER_DIR_S)/perimeter.o: src/perimeter.cpp
	g++ $(CFLAGS) -c src/perimeter.cpp -o $(USER_DIR_S)/perimeter.o

$(USER_DIR_T)/test.o: test/test.c
	gcc $(CFLAGS) -I thirdparty -I src -c test/test.c -o $(USER_DIR_T)/test.o 

$(USER_DIR_T)/main.o: test/main.c
	gcc $(CFLAGS) -I thirdparty -c  test/main.c -o $(USER_DIR_T)/main.o 

$(TEST): $(USER_DIR_T)/test.o  $(USER_DIR_T)/main.o 
	gcc $(CFLAGS) $(USER_DIR_T)/test.o $(USER_DIR_T)/main.o -o $(TEST) 

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf $(USER_DIR_T)/*.o
	rm -rf bin/*
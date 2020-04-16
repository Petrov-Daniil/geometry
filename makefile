CFLAGS = -Wall -Werror
USER_DIR_S = build/src
USER_DIR_T = build/test
EXECUTABLE = bin/programm
TEST = bin/test

all: $(EXECUTABLE) $(TEST)

$(EXECUTABLE): $(USER_DIR_S)/main.o $(USER_DIR_S)/pars.o $(USER_DIR_S)/circle.o $(USER_DIR_S)/perimeter.o
	gcc $(CFLAGS) $(USER_DIR_S)/main.o $(USER_DIR_S)/pars.o $(USER_DIR_S)/circle.o $(USER_DIR_S)/perimeter.o -o $(EXECUTABLE)

$(USER_DIR_S)/main.o: src/main.c
	gcc $(CFLAGS) -c src/main.c -o $(USER_DIR_S)/main.o

$(USER_DIR_S)/pars.o: src/pars.c
	gcc $(CFLAGS) -c src/pars.c -o $(USER_DIR_S)/pars.o

$(USER_DIR_S)/circle.o: src/circle.c
	gcc $(CFLAGS) -c src/circle.c -o $(USER_DIR_S)/circle.o

$(USER_DIR_S)/perimeter.o: src/perimeter.c
	gcc $(CFLAGS) -c src/perimeter.c -o $(USER_DIR_S)/perimeter.o

$(USER_DIR_T)/pars_test.o: test/pars_test.c
	gcc $(CFLAGS) -I thirdparty -I src -c test/pars_test.c -o $(USER_DIR_T)/pars_test.o 

$(USER_DIR_T)/main.o: test/main.c
	gcc $(CFLAGS) -I thirdparty -c  test/main.c -o $(USER_DIR_T)/main.o 

$(TEST): $(USER_DIR_T)/pars_test.o  $(USER_DIR_T)/main.o 
	gcc $(CFLAGS) $(USER_DIR_S)/pars.o $(USER_DIR_T)/pars_test.o $(USER_DIR_T)/main.o -o $(TEST) 

clean:
	rm -rf $(USER_DIR_S)/*.o
	rm -rf $(USER_DIR_T)/*.o
	rm -rf bin/*
.PHONY: all  clean
CC=src/
CO=build/
CI=bin/
BB=gcc -Wall -Werror

all: 123

123: folder repository  $(CO)main.o $(CO)menu.o $(CO)game.o 
	$(BB) $(CO)main.o $(CO)menu.o $(CO)game.o -o 123 -lncurses
$(CO)main.o: $(CC)main.c
	$(BB) -c -o $(CO)main.o $(CC)main.c -lncurses
$(CO)menu.o: $(CC)menu.c
	$(BB) -c -o $(CO)menu.o $(CC)menu.c -lncurses
$(CO)game.o: $(CC)game.c
	$(BB) -c -o $(CO)game.o $(CC)game.c -lncurses

folder:
	sudo apt-get install libncurses5-dev libncursesw5-dev

repository:
	mkdir -p bin
	mkdir -p build

clean:
	rm -rf 123
	rm $(CO)*.o
	rm -R bin
	rm -R build

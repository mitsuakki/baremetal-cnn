all: clean
	gcc -std=c11 -Wall -Wextra -O2 main.c src/matrix.c -o main
	./main

clean:
	rm -rf main
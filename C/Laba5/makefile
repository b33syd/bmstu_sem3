FLAGS := -std=c99   -ggdb -Wall -Werror -pedantic 

main: main.o func.o
	gcc -o $@ $^ -lm
	./main
	

%.o: %.c *.h 
	gcc $(FLAGS) -c $< -lm


tester: tester.o func.o
	gcc $(FLAGS) -o $@ $^ -lm
	./$@

gcov: main.c list.c
	rm *.gc*
	c99 -Wall -Werror -pedantic -O0 -fprofile-arcs -ftest-coverage $^ -o main
	make -i test
	gcov $^

clean:
	rm *.o main test
	rm *.gc*

valgrind: main
	valgrind --tool=memcheck ./main fileA fileB fileout INV
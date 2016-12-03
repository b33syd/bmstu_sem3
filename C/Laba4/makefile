FLAGS1 := -std=gnu99  -ggdb -Wall -Werror -pedantic
FLAGS := -std=c99  -ggdb -Wall -Werror -pedantic

main: main.o  func.o
	gcc -o $@ $^
	./main fileA fileB fileout SUMM
	./main fileA fileB fileout MULT
	./main fileA fileout INV

%.o: %.c *.h 
	gcc $(FLAGS) -c $<


test:
	./main fileA fileB fileout SUMM
	./main fileA fileB fileout MULT
	./main fileA fileB fileout INV


test_libstr2: test_libstr2.o libstr2.o
	gcc -o $@ $^
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
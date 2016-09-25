FLAGS := -std=c99  -ggdb -Wall -Werror -pedantic

main: main.o  functions.o
	gcc -o $@ $^

%.o: %.c 
	gcc  $(FLAGS) -c $<

test:
	./main 
	./main tests/does_not_exist
	./main tests/empty_file
	./main tests/first_max
	./main tests/end_max
	./main tests/cenrte_pair_max
	./main tests/cenrte__max
	./main tests/normal

moduletest: moduletest.o functions.o
	gcc -o $@ $^
	./$@

gcov: 
	rm *.gc*
	c99 -Wall -Werror -pedantic -O0 -fprofile-arcs -ftest-coverage main.c functions.c -o main
	make -i test
	gcov main.c functions.c
clean:
	rm *.o main moduletest
	rm *.gc*
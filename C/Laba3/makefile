FLAGS1 := -std=gnu99  -ggdb -Wall -Werror -pedantic
FLAGS := -std=gnu99  -ggdb -Wall -Werror -pedantic

main: main.o  libstr2.o 
	gcc -o  $@ $^
	./main file1 fileout name NAME
#	./main tests/normal tests/temp/file_normal_2 tests/temp/file_normal_3

%.o: %.c *.h 
	gcc  $(FLAGS) -c $<

test:
	./main
	./main tests/file1
	./main tests/file1 tests/file2 
	./main tests/does_not_exist tests/temp/file2 tests/temp/file3
	./main tests/empty_file tests/temp/file_null_2 tests/temp/file_null_3
	./main tests/normal tests/block_file tests/temp/file_normal_0
	./main tests/normal tests/temp/file_normal_1 tests/block_file
	./main tests/only_even tests/temp/file_even_2 tests/temp/file_even_3
	./main tests/only_odd tests/temp/file_odd_2 tests/temp/file_odd_3
	./main tests/normal tests/temp/file_normal_2 tests/temp/file_normal_3


test_libstr1: test_libstr1.o libstr1.o
	gcc -o $@ $^
	./$@

test_libstr2: test_libstr2.o libstr2.o
	gcc -o $@ $^
	./$@

gcov: main.c list.c
	rm *.gc*
	c99 -Wall -Werror -pedantic -O0 -fprofile-arcs -ftest-coverage $^ -o main
	make -i test
	gcov $^

clean:
	rm *.o main moduletest
	rm *.gc*

valgrind: main
	valgrind --tool=memcheck ./main file1 fileout Medvedev Nabere
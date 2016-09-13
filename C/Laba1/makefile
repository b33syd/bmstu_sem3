FLAGS := -std=c99 -Wall -Werror -pedantic

ifeq ($(mode), debug)
FLAGS += -g3 -gdwarf-2
endif

ifeq ($(mode), release)
FLASg += -DNDEBUG -g0
endif

main: main.o  functions.o
	gcc -o $@ $^

%.o: %.c 
	gcc $(FLAGS) -c $<

test:
	./main 
	./main tests/oneparam
	./main tests/does_not_exist tests/outfile
	./main tests/empty_file tests/outfile1
	./main tests/lower_then_limit tests/outfile2
	./main tests/limit tests/outfile3
	./main tests/more_then_limit tests/outfile4
	./main tests/testin tests/blockedfile

moduletest: Test.o functions.o
	gcc -o $@ $^
	./$@

gcov: 
	rm *.gc*
	c99 -Wall -Werror -pedantic -O0 -fprofile-arcs -ftest-coverage main.c functions.c -o main
	make -i test
	gcov main.c functions.c
clean:
	rm *.o main
	rm *.gc*
	rm tests/outfile[0-9]

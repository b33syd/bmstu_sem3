FLAGS1 := -std=gnu99  -ggdb -Wall -Werror -pedantic
FLAGS := -std=c99  -ggdb -Wall -Werror -pedantic

main: main.o  func.o
	gcc -o $@ $^
	./main fileA fileB fileout MULT
#	./main tests/normal tests/temp/file_normal_2 tests/temp/file_normal_3

%.o: %.c 
	gcc   -c $<
FLAGS := -std=c99   -ggdb -Wall -Werror -pedantic 
FLAGS2 := -std=c99

main: main.o  list.o
	gcc -o $@ $^

%.o: %.c
	gcc $(FLAGS) -c $< 

tester: tester.o list.o
	gcc $(FLAGS) -o $@ $^ 
	tester.exe

clean:
	rm *.o *main



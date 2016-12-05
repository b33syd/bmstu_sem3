main: main.o  functions.o
	gcc -o $@ $^
	./main file2


%.o: %.c 
	gcc  -c $<
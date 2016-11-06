main: main.o  functions.o
	gcc -o $@ $^
	./main file1


%.o: %.c 
	gcc  -c $<
main: main.o  functions.o
	gcc -o $@ $^
	valgrind  ./main file2 NO fout
	valgrind ./main file2 YES fout

tester: tester.o functions.o
	gcc $(FLAGS) -o $@ $^
	valgrind ./$@

data: data.o functions.o
	gcc $(FLAGS) -o $@ $^ -lm


%.o: %.c 
	gcc  -c $< -lm


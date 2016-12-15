main: main.o  functions.o
	gcc -o $@ $^
	./main file2 NO fout
	./main file2 YES fout

tester: tester.o functions.o
	gcc $(FLAGS) -o $@ $^
	./$@

data: data.o functions.o
	gcc $(FLAGS) -o $@ $^ -lm


%.o: %.c 
	gcc  -c $< -lm


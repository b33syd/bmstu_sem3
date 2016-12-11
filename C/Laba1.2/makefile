main: main.o  functions.o
	gcc -o $@ $^
	./main file2 NO fout
	./main file2 YES fout

tester: tester.o functions.o
	gcc $(FLAGS) -o $@ $^
	./$@


%.o: %.c 
	gcc  -c $<


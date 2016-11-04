FLAGS := -std=c99  -ggdb -Wall -Werror -pedantic
  
main.exe: main.o  func.o
	gcc -o $@ $^
	

%.o: %.c 
	gcc  $(FLAGS) -c $<


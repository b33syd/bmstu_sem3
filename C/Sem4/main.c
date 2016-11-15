//Правильно ли проиницелизирована строка name и почему?
int main(void)
{
	char name[]={'F','e','s','s'};	//Неправильно
	char name[]={'F','e','s','s','\0'}; //Правильно
	char name1[]="Fess"; //Правильно
	char name2[5]={'F','e','s','s'}; //Правильно

}
//Что напечатает следующая программа?

#include <stdio.h>

int main(void)
{
	char note[]="1234567890 abcd.";

	char* prt=note;
	puts(prt);		//1234567890 abcd.
	puts(++prt);	//234567890 abcd.

	note[7]='\0';	//1234567\0

	puts(note);		//1234567
	puts(++prt);	//34567

	return 0;
}

//Что напечатает следующая програма?
#include <stdio.h>
#include <string.h>

int main(void)
{
	char food[]="Yummy";
	char* prt;
	prt=food+strlen(food);
	
	while (--prt >=food)
	{
		puts(prt);		
	}

	return 0;
}
/*
y
my
mmy
ummy
Yummy
*/



#include <stdio.h>
//Xo Xo Xo!!oX oX oX
char *pr(char *str)
{
	char *pe=str;
	while(*pe)
		putchar(*pe++); 
	do
	{
		putchar(*--pe); 
	}while(pe-str)

	return pe;
}

int main(int argc, char const *argv[])
{
	/* code */
	//Какой тип должна иметь вид переменная x
	char *x;
	x=pr("Xo Xo Xo!");


	//чем отличается 
	//*--pe  
	//--*pe 
	return 0;
}


//Что произойдет с pe если подать ""
//


#include <string.h>
#include <stdio.h>

int main(void)
{
	char  str_a[40]="e is ";
	char  str_b[40]="My nam";
	const char *quote="Ymmy.";
	strcat(str_a,quote); //e is Ymmy. 
	strcat(str_b,str_a); //My name is Ymmy.
	puts(str_b); //My name is Ymmy.
	return 0;
}


#include <stdio.h>

int main(void)
{
	int a[]
}




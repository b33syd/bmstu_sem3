
//#1 Чему будут равны значения переменных после выполнения программы.
int main(void)
{
	int i=10, j =14, k;
	int *p=&i;	//p->i
	int *q=&j;	// q->j
	*p+=1		// i=11
	p=&k;		//p->k
	*p=*q;		// k=14
	p=q;		// p->j
	*p=*q;		//j=14
}
//#2 Пусть задан массив, что тогда означают выражения
//
	int arr[10];

	arr[0] 		//Нулевой элемент массива
	*arr 		//Нулевой элемент массива
	*arr+2 		//Нулевой элемент массива +2
	*(arr+2) 	//Значение arr[2]
	arr			//указатель на 0 эллент
	&arr[2]		//адресс второго элемента
	arr+2		//Указатель на arr[2] 
//#3Дан фрагмент текста программы
	int a[]={0,1,2};
	int *b =a+1;
//чему равны?
	b[-1]=//0
	b[2]=//*(a+3)
//Можно ли написать?
	a++;	//нет
	b++;	//ДА
	b=a;	//Да
	a=b;	//нет
	    	//

//#4 что напечатает следующая программа
#include <stdio.h>
int main(void)
{
	int a[]={0,1,2,3,4};
	int i,*p;
	for (p=&a[0]; p <= &a[4]; p++)
	{
		printf("%d ",*p );	//0 1 2 3 4
	}
	for (p=a+4,i=0;i<=4;i++)
	{
		printf("%d ",p[-i] );	//4 3 2 1 0
	}
	for (p=a,i=0;p++<=a+4; ++i)
	{
		printf("%d ",*(p++) );	//0 1 2 3 4
	}

	for (p=a+4,p>=a;p--)
	{
		printf("%d ",a[p-a] );	//4 3 2 1 0
	}


	return 0;
}	    
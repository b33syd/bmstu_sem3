#include "libstr1.h"

//Функция strcspn выполняет поиск первого вхождения
//в строку string1 любого из символов строки string2, и
//возвращает количество символов до найденного первого вхождения. 
size_t mystrcspn( const char * string1, const char * string2)
{
	int i=0;
	int j=0;	
	
	while(string1[i]!='\0')
	{
		j=0;
		while(string2[j]!='\0')
		{ 
			if(string1[i]==string2[j])
				return i;
			++j;
		}
		++i;
	}

	return i;
}



//Задание 1. Длинна строки для функции mystrndup
size_t mystrnlen(const char *s, size_t maxlen)
{
	int i=0;
	while((s[i]!='\0')&&(maxlen>i))		
		i++;

	return i*sizeof(char);
}

//Задание 1. Создание дубликата строки strndup
char * mystrndup(const char *str, size_t maxlen)
{
	char *copy=NULL;
	size_t len=0;

	len = mystrnlen(str, maxlen);
	copy = (char *) malloc(len+1);

	if (copy != NULL) 
	{
	    copy[len] = '\0';
	    
	    //copy=(char*)memcpy(copy, str, len);
	    for (int i = 0; i < len; ++i)
	    {
	    	copy[i]=str[i];
	    }
	    
	}
	return copy;
}
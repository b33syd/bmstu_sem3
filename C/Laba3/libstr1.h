#ifndef LIBSTR1_H
#define LIBSTR1_H

#include <stdio.h>
#include <stdlib.h>

/*
	Функция strcspn выполняет поиск первого вхождения
	в строку string1 любого из символов строки string2, и
	возвращает количество символов до найденного первого вхождения. 
*/
size_t mystrcspn( const char * string1, const char * string2);

/*
	Создание дубликата строки strndup
*/
char * mystrndup(const char *str, size_t maxlen);

#endif // LIBSTR1_H
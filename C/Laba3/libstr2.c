#include "libstr2.h"
#include <string.h>
#define LENGTH_DELTA 10



void logger(int n)
{
	//printf("DEBUG %d\n", n);
}


int realloc_str(char** string,int cur_len, int new_len)
{	
	char *temp_string;
	int code_error=OK;

	temp_string=malloc(new_len);

	if (temp_string==NULL)
	{			
		code_error=ERROR_MALLOC;
	}
	else
	{
		logger(30);
		memset(temp_string,'\0',new_len);
		memcpy(temp_string, *string, cur_len);
		logger(31);
		if (*string!=NULL)
		{
			//printf("CORRECT5\n");
			//printf("%s\n", *string);
			free(*string);
			//printf("CORRECT5.5\n");
		}
		logger(32);
	//	printf("CORRECT6\n");
		*string=temp_string;
	}
	//printf("CORRECT7\n");

	return code_error;
}

//Задание 2 динамическое чтение строки из файла
int readfromfile2(char **line,size_t *n, FILE *file)
{
	logger(20);
	int code_error=OK;
	int current_length=0;
	//int array_max_length=0;
	char buf[BUF_SIZE];
	*n=0;
	char *string=NULL;
	//чтение 	
	while(fgets(buf, BUF_SIZE, file) != NULL)
	{
		logger(21);
		//узнаем размер считанного
		int readed=strlen(buf);			
		//довыделяем память под считанное		
		code_error = realloc_str(&string,current_length , current_length+readed+1);
		if (code_error!=OK)
			break;
		logger(22);	
		//копируем содержимое буфера в строку
		memcpy(string+current_length,buf,readed+1);

    	//Двигаем позицию
		current_length+=readed;
    	
		if(string[current_length-1] == '\n')
		{
			//string[current_length-1] = 0;
        	break;
  		}
	}


	
	logger(23);
	*line=string;
	*n=current_length;	
	return code_error;
}


char* my_strstr(const char *string,const char *substring)
{
	//printf("STR  s %s r %s\n",string,substring );
	int len_string=strlen(string);
	int len_substring=strlen(substring);
	for (int i = 0; i <len_string; ++i)
	{
		if(string[i]==substring[0])
		{
			int flag=0;
			int j = 0;
			for (; ((j < len_substring) && ((i+j)<len_string)); ++j)
			{
				if(substring[j]!=string[i+j])
				{
					flag=1;
					break;
				}

			}
			if((flag==0)&&(j==len_substring))
			{
				return (char *)string+i;
			}
		}
	}
	return NULL;
}



int onereplace(char **string, const char *replace_what, const char *replace_with, int * index_to_start)
{
	// Указатель на позицию с которой начнется замена
	char* replace_start=NULL;
	int rep_what_len=strlen(replace_what);
 	int rep_with_len=strlen(replace_with); 	
 	int string_len=strlen(*string);

	logger(1);

	if(*index_to_start>string_len)
		return 0;

	if((replace_start=my_strstr(*string+*index_to_start,replace_what))==NULL)
		return 0;
	logger(2);
	

 	logger(3);
 	int len_left_part_for_copy=replace_start - *string;
	logger(4);
 	char *newstring=malloc(sizeof(char)*(string_len+rep_with_len-rep_what_len+1));
 	if(newstring==NULL)
 		return ERROR_MALLOC;
 	logger(5);

 	newstring[string_len+rep_with_len-rep_what_len]='\0';
	logger(6);

	//Копируем часть до замены
	memcpy(newstring, *string, len_left_part_for_copy);	
	logger(7);
	//Копируем в новую строку замену
	memcpy(newstring+len_left_part_for_copy, replace_with, rep_with_len);
	logger(8);
	//Вычисляем указатели 
	char *started_p_to_write=newstring+len_left_part_for_copy+rep_with_len;
	char *started_p_to_read=*string+len_left_part_for_copy+rep_what_len;

	logger(9);
	//printf("%s\n",started_p_to_write);
	//printf("%s\n",started_p_to_read);
	//копируем хвост, оставшийся после замены
	memcpy(started_p_to_write, started_p_to_read, *string+string_len-started_p_to_read+1);
	logger(10);
	//Удаляем старую строку	
	//printf("%s\n",*string );	
	if (*string)
		free(*string);
	logger(11);
	*string=newstring;
	*index_to_start= len_left_part_for_copy+rep_with_len;
	//printf("INDEX %d %s\n",*index_to_start, newstring );
	return 1;

}

char *replace( const char *line,  const char *replace_what, const char *replace_with)
{ 	

	//Клонируем нашу строку на динамическую память,
	//так как при статике нельзя использовать free
	char* linetmp=strdup(line);
	int code_error=OK;
	int index_to_start=0;
 	//printf("IN\n");
 	
 	while((code_error=onereplace(&linetmp,replace_what,replace_with,&index_to_start))!=0);
 	
 	if (code_error==ERROR_MALLOC)
 	{
 		printf("ERROR_MALLOC\n");
 	}
 	//printf("OUT\n");

 	return linetmp;

}

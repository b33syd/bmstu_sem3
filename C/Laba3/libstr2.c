#include "libstr2.h"
#include <string.h>
#define LENGTH_DELTA 10



int reloc_str(char** string,int cur_len, int new_len)
{
	char *temp_string;
	int code_error=OK;

	temp_string=(char*)malloc(new_len*sizeof(char));


	if (temp_string==NULL)
	{			
		code_error=ERROR_MALLOC;
		
	}
	else
	{
		for (int i = 0; i < cur_len; ++i)
		{
			temp_string[i]='\0';
		}

		memcpy(temp_string, *string, cur_len);
		free(*string);
		*string=temp_string;
	}

	return code_error;
}



//Задание 2 динамическое чтение строки из файла
//Аналогично стандарту ssize_t getline(char **lineptr, size_t *n, FILE *stream);

int readfromfile2(char **line,size_t *n, FILE *file)
{

	int code_error=OK;
	int current_length=0;
	int array_max_length=0;
	char buf[BUF_SIZE];
	*n=0;
	char *string=NULL;
	//char *temp_string;

	
	while(fgets(buf, BUF_SIZE, file) != NULL)
	{
		//printf("%s\n",buf );
		int readed=strlen(buf);
		//довыделяем пямять при необходимости
		if(current_length+BUF_SIZE>=array_max_length)
		{
			array_max_length+=LENGTH_DELTA;				

			code_error= reloc_str(&string,current_length , array_max_length);


			if (code_error!=OK)
				break;
		}
		

		memcpy(string+current_length,buf,BUF_SIZE);

		

		


		
    	//Двигаем позицию
		current_length+=readed;
    	
		if(string[current_length-1] == '\n')
		{
			//string[current_length-1]='\0';
			//string[current_length]='\0';
        	break;
  		}
	}


	
	//printf("%s\n",string );
	
	//Обрезаем лишенее
	if (current_length==0)
	{
		free(string);
		*line=NULL;

		return -1;
	}


	
	code_error= reloc_str(&string,current_length , current_length);
	
	

	if (!code_error)	
		string[current_length]='\0';

	string[current_length]='\0';
	

	*line=string;
	*n=current_length;
	
	
	return code_error;
}







int onereplace(char **string, const char *replace_what, const char *replace_with )
{
	// Указатель на позицию с которой начнется замена
	char* replace_start=NULL;
	//printf("	%s\n", replace_start);
	if((replace_start=strstr(*string,replace_what))==NULL)
		return 0;

	int rep_what_len=strlen(replace_what);
 	int rep_with_len=strlen(replace_with); 	
 	int string_len=strlen(*string);
 	int len_left_part_for_copy=replace_start - *string;
	
 	char *newstring=malloc(sizeof(char)*(string_len+rep_with_len-rep_what_len+1));
 	
 	if(newstring==NULL)
 		return ERROR_MALLOC;

 	newstring[string_len+rep_with_len-rep_what_len]='\0';
	

	//Копируем часть до замены
	memcpy(newstring, *string, len_left_part_for_copy);	
	
	//Копируем в новую строку замену
	memcpy(newstring+len_left_part_for_copy, replace_with, rep_with_len);
	
	
	char *started_p_to_write=newstring+len_left_part_for_copy+rep_with_len;
	char *started_p_to_read=*string+len_left_part_for_copy+rep_what_len;

	//копируем хвост, оставшийся после замены
	memcpy(started_p_to_write, started_p_to_read, *string+string_len-started_p_to_read);
	
	//Удаляем старую строку		
	if (*string)
		free(*string);

	*string=newstring;

	return 1;

}

char *replace( const char *line,  const char *replace_what, const char *replace_with)
{ 	

	//Клонируем нашу строку на динамическую память,
	//так как при статике нельзя использовать free
	char* linetmp=strdup(line);
	int code_error=OK;
 	
 	while((code_error=onereplace(&linetmp,replace_what,replace_with))!=0);
 	
 	if (code_error==ERROR_MALLOC)
 	{
 		printf("ERROR_MALLOC\n");
 	}

 	return linetmp;
}


/*
char *onereplace(char *string, char *replace_what, char *replace_with,char *replace_start)
{
	int rep_what_len=strlen(replace_what);
 	int rep_with_len=strlen(replace_with);
 	

	char *newstring=malloc(sizeof(char)*(strlen(string)+(rep_with_len- rep_what_len)));
	char *temp_string=newstring;

	//Копируем часть до замены
	for (; string != replace_start; newstring++, string++)
		*newstring= *string;

	//Копируем в новую строку замену
	for (int i = 0; i < rep_with_len; ++i, newstring++, replace_with++)
		*newstring=*replace_with;

	//Двигаем указатель на хвост который надо скопировать 		
	string+=rep_what_len;
	 //Копируем хвост

	
	for (; *string!='\0'; newstring++, string++)
	{
		*newstring=*string;
	}	
	
	return temp_string;

}
*/

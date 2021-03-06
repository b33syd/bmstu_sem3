#include "func.h"

char *print(char *q, size_t *size,const char ch, int *global_counter)
{
	*global_counter=*global_counter+1;
	if(*size<=1) 
		return q;
	
	*q=ch;
	*size=*size-1;
	q++;
	return q;
}

char *printer3(char *q, size_t *size, const unsigned short toconvert,int *global_counter)
{
	int tmp=toconvert;
	const char hexDigits[] = "0123456789ABCDEF";
	char result[] = "0000\0";
	for (int i = 3; i >=0; i--)
	{
		result[i]=hexDigits[tmp%16]; 
		tmp=tmp/16;
		//printf("%d\n",tmp );
		
	}

	int flag = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (result[i] != '0') flag = 1;
		else if (flag == 0) continue;
		
		q=print(q,size,result[i],global_counter);
		
	}
	//printf("\n");


	if (flag == 0)
	{
		q=print(q,size,'0',global_counter);
	}
	return q;

}




char *printer1(char *q, size_t *size, const char *line,int *global_counter)
{
	for (int i = 0; *line != '\0'; line++)
	{
		q=print(q,size,line[i],global_counter);
	}
	return q;
}

int digit_len(int num)
{
	int num_len = 0;
	if (num == 0)
	{
		num_len = 1;
	} else
	{
		while (abs(num) != 0)
		{
			num = num / 10;
			num_len++;
		}
	}
	return num_len;
}

char get_n_char(int num,int k)
{
	int n = (num / (pow(10,k-1)));
	
	return n%10+'0';
}

char *printer2(char *q, size_t *size, const int toprint,int *global_counter)
{
	
	int num = toprint;
	int num_len = digit_len(toprint);

	if ((num < 0))
	{
		q=print(q,size,'-',global_counter);
	}

	for (int i = 0; i < num_len; ++i)
	{
		q=print(q ,size,get_n_char(abs(num),num_len-i),global_counter);	
	}

	return q;

}


size_t my_vsnprintf(char *buffer, size_t buff_size, const char *format, va_list ap)
{
	size_t n=buff_size;
	const char *p = format;
	char *q = buffer;
	char ch;
	int global_counter=0;

	while ((ch = *p++))
	{
		if (ch == '%')
		{
			if ((ch = *p++))
			{
				switch (ch)
				{
					case 'd':
						//printf("found d\n");
						q = printer2(q, &n, va_arg(ap, int),&global_counter);
						break;
					case 's':
						//printf("found s\n");
						q = printer1(q, &n, va_arg(ap, const char *),&global_counter);
						break;
					case 'h':
						//printf("found h\n");
						if ((ch = *p++))
						{
							if (ch == 'X')
							{
								//printf("found X\n");
								q = printer3(q, &n, (unsigned short) va_arg(ap, unsigned int),&global_counter);

							} 
							else
							{
								q=print(q,&n,'%',&global_counter);
								q=print(q,&n,'h',&global_counter);
								q=print(q,&n,ch,&global_counter);
							}
						}
						break;
				}
			}
		} 
		else
		{
			q=print(q,&n,ch,&global_counter);
		}
	}
	*q = '\0';
	return global_counter;
}


int my_snprintf(char *buffer, size_t n, const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int rv = my_vsnprintf(buffer, n, format, ap);
	va_end(ap);
	return rv;
}
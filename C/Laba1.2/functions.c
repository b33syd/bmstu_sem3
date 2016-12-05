#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"



#define BAD_READ -10
#define OK 0


unsigned long long tick(void)
{
    unsigned long long d;

    __asm__ __volatile__ ("rdtsc" : "=A" (d) );

    return d;
}

void count_file_length(int *array_length, FILE *file)
{   
    *array_length = 0;
    int temp;
    while ((fscanf(file, "%d", &temp) != EOF))
        *array_length = *array_length + 1;
}

int readfromfile(int *array_st, int *array_end, FILE *file)
{
    for (; array_st < array_end; array_st++)
    {
        if (fscanf(file, "%d", array_st) != 1)
        {
            return BAD_READ;
        }
    }
    return OK;
}

//Checked
int filer_summ( const int *array, const int *array_end)
{
    int full_summ=0;

    //printf("filer_summ-->\n");
    
    if((array_end-array )<0)
    {
        //printf("BAD POINTERS in filer_summ exit, %p  %p\n",array,array_end);
        return BAD_POINTERS; 
    }

    while(array!=array_end)
    {
        full_summ+=*array;
        array++;
    }

    //printf("filer_summ exit with: %d\n",full_summ);
    return full_summ;
}

//Checked
int filter_counter( const int *array, const int *array_end, int full_summ)
{
    //printf("filter_counter-->\n");
    int k=0;

    while(array!=array_end)
    {
        full_summ-=*array;
        if(full_summ<*array)
            k++;
        array++;
    }
    
    //printf("filter_counter exit with: %d\n",k);
    return k;
}

//Checked
int filter_newarray(int *array, int *array_end,int *filtered,int *filtered_end,int full_summ)
{

    while((array!=array_end)&&(filtered_end != filtered))
    {
        full_summ-=*array;
        if(full_summ<*array)
        {
            *filtered=*array;
            //printf("COPIED %d , %d\n",*filtered, *array );
            filtered++;    
        }
        array++;
    }
    //printf("ex\n");
    if(filtered_end!=filtered)
        return ERROR_LENGTH;
    else
        return OK;
}

//Checked
int filter(int *array, int *array_end,int **filtered,int **filtered_end)
{
    int status_work=OK;
    int full_summ=filer_summ(array, array_end);
    int k=filter_counter(array, array_end,full_summ);
    
    *filtered = (int*) malloc(k * sizeof(int));


    if (*filtered != NULL) 
    {        
        *filtered_end = *filtered + k;
        filter_newarray(array, array_end,*filtered,*filtered_end,full_summ);
    }
    else 
    {
        status_work = ERROR_MALLOC;
    }
    return status_work;
    
}

//Checked
void printarray(int *array, int *array_end)
{
    //debug("9",6);
    while(array!=array_end)
    {
        printf("%d ", *array);
        array++;
    }
    printf("\n");
}

int compare_int_less(const void *val1, const void *val2)
{
    int *a = (int *) val1;
    int *b = (int *) val2;
    //printf("%d    %d\n ",*b,*a );
    return *b - *a;
}

char* bin_search(char* array, char* array_end, char* val,int size,int (*comparator)(const void *, const void *))
{
    //printf("SEARCH1 %p  %p \n",array,array_end);
    while(array<array_end)
    {
        //printf("SEARCH2\n");
        //printf("                %d          %d\n",(array_end-array),0);
        int n=(array_end-array)/size;
        char *med=array+n/2*size;

        if(comparator(med,val)>0)
            array=med+size;
        else
            array_end=med;
        //printf("SEARCH3 %p  %p \n",array,array_end);
    }
    //printf("SEARCH4\n %p  %p %d %d\n",array,array_end,*array,val);

    return array;
}


void mod_insertion_sort(void *adr,const size_t nmemb,const size_t size_of_el, int (*comparator)(const void*, const void*))
{
    char *array =(char *) adr;
    char *array_tmp =(char *) adr;
    char *tmp=malloc(size_of_el);
    char *array_end=array+size_of_el*nmemb;
    char *cp;

    //void *tmp1=array;
    //void tmp
    while(array!=array_end)
    {
        memcpy(tmp,array,size_of_el);
        
        char *pos=bin_search(array_tmp,array,tmp,size_of_el,comparator);
        //printf("%d  %d  %d\n",array_tmp, pos, array );
        //memmove(pos,array,array-pos);
        cp=array;
       // printf("%d\n", cp);
        while(cp!=pos)
        {
            memcpy(cp,cp-size_of_el, size_of_el);
            cp=cp -size_of_el;
        }

        memcpy(pos,tmp,size_of_el);
        array=array+size_of_el;
    }
    free(tmp);
}
/*
//Checked
void mod_insertion_sort(int *array, int *array_end)
{
    
    int *tmp1=array;
    int tmp;
    int *cp;
    //printf("SORT1\n");
    //printarray(array, array_end);

    while(array!=array_end)
    {   
        tmp=*array;
        cp=array;
        //printf("SORT2\n");
        int *pos=bin_search(tmp1,array,*array);
        
        //printf("SORT3\n");
      //  printarray(array, array_end);
        while(cp!=pos)
        {
            *cp=*(cp-1);
            cp--;
        }
        //printf("SORT4\n");
        *cp=tmp;
        
        array++;
    }

}
*/
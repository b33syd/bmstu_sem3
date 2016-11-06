#include <stdio.h>
#include <stdlib.h>
#include "functions.h"



#define BAD_READ -10
#define OK 0

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

//Проверено
int filer_summ( const int *array, const int *array_end)
{
    int full_summ=0;

    printf("filer_summ-->\n");
    
    if((array_end-array )<0)
    {
        printf("BAD POINTERS in filer_summ exit, %p  %p\n",array,array_end);
        return BAD_POINTERS; 
    }

    while(array!=array_end)
    {
        full_summ+=*array;
        array++;
    }

    printf("filer_summ exit with: %d\n",full_summ);
    return full_summ;
}

//Проверено
int filter_counter( const int *array, const int *array_end, int full_summ)
{
    printf("filter_counter-->\n");
    int k=0;

    while(array!=array_end)
    {
        full_summ-=*array;
        if(full_summ<*array)
            k++;
        array++;
    }
    
    printf("filter_counter exit with: %d\n",k);
    return k;
}

int filter_newarray(int *array, int *array_end,int *filtered,int *filtered_end,int full_summ)
{

    while((array!=array_end)&&(filtered_end != filtered))
    {
        full_summ-=*array;
        if(full_summ<*array)
        {
            *filtered=*array;
            printf("COPIED %d , %d\n",*filtered, *array );
            filtered++;    
        }
        array++;
    }
    printf("ex\n");
    if(filtered_end!=filtered)
        return ERROR_LENGTH;
    else
        return OK;
}

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


int * bin_search(int *array, int *array_end,int val)
{
    //printf("SEARCH1 %p  %p \n",array,array_end);
    while(array!=array_end)
    {
        //printf("SEARCH2\n");
        if(*(array+(array_end-array)/2)<val)
            array=array+(array_end-array)/2+1;
        else
            array_end=array+(array_end-array)/2;
        //printf("SEARCH3 %p  %p \n",array,array_end);
    }
    //printf("SEARCH4\n %p  %p %d %d\n",array,array_end,*array,val);

    return array;
}


void mod_insertion_sort(int *array, int *array_end)
{
    
    int *tmp1=array;
    int tmp;
    int *cp;
    printf("SORT1\n");
    printarray(array, array_end);

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
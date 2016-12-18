//Вариант7 (20 баллов)
//числа положительные
#include "list.h"
#include <stdlib.h>
#include <stdio.h>





struct list * converter( int num)
{
    struct list *list_out=NULL;
    struct list *tmp=NULL;

    while(num>0)
    {

        tmp=create_node(num%10);

        list_out=add_end(list_out,tmp);

        num=num/10;

    }
    return list_out;
}

struct list * summa(struct list *tmp_listA,struct list *tmp_listB)
{
            struct list *list_out=NULL;
            struct list *tmp=NULL;
            int val;
            for(;(tmp_listA!=NULL && tmp_listB!=NULL); )
            {
                val=tmp_listA->value+tmp_listB->value;
                tmp=create_node(val);
                list_out=add_end(list_out,tmp);
                tmp_listA=tmp_listA->next;
                tmp_listB=tmp_listB->next;

            }

            for(;(tmp_listA!=NULL); tmp_listA=tmp_listA->next)
            {
                 tmp=create_node(tmp_listA->value);

                list_out=add_end(list_out,tmp);
                // print(list_out);
            }

             for(;tmp_listB!=NULL; tmp_listB=tmp_listB->next)
             {
                     tmp=create_node(tmp_listB->value);

                    list_out=add_end(list_out,tmp);
                   //  print(list_out);
             }
             print(list_out);
    return list_out;
}


int main(int argc, char const *argv[])
{
    int A,B,C=0;
    A=0;B=0;
    printf("Input A: ");
    scanf("%d",&A);
    struct list *listA=converter(A);
    print(listA);

    printf("Input B: ");
    scanf("%d",&B);


    struct list *listB=converter(B);
    print(listB);
    struct list *listC=summa(listA,listB);


    int i=1;
    while(listC!=NULL)
    {
       C=C+listC->value*i;
       i=i*10;
       listC=listC->next;
    };

    printf("A+B=%d",C);
    print(listC);

    free_all(listA);
    free_all(listB);
    free_all(listC);

}

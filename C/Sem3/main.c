#include <stdio.h>
#include <stdlib.h>

struct list_node
{
    int num;
    struct list_node *next;
    struct list_node *prev;
};

struct list_node* create_node(int n)
{
	//printf("qqqq1\n");
    struct list_node *p=malloc(sizeof(struct list_node));
    if(p)
    {
    	//printf("qqqq2\n");
        p->num=n;
        p->next=NULL;
        p->prev=NULL;
    }
    return  p;
}
struct  list_node * add_node(struct list_node *head,struct list_node * elem)
{
    //printf("qqqq3\n");
    if(!head)
    {
    	//printf("qqqq4\n");
    	head=elem;
        head->next=elem;
        head->prev=elem;
        return head;
    }
    else
    {
    	//printf("qqqq5\n");

        elem->next = head->next;
        head->next = elem;
        elem->prev = head;
        elem->next->prev = elem;
    	return elem;
    }


}

struct  list_node * del_elem(struct list_node *head)
{
    if(head->next==head->prev && head->next==head)
    {
    	free(head);
        return NULL;
    }
    else
    {
    	
        head->next->prev = head->prev;
        head->prev->next = head->next;
        struct list_node *tmp = head->next;
        free(head);
        return tmp;
        
    }
    
}

void list_print(struct  list_node * head)
{
	//printf("qqqq6\n");
    if(head)
    {
        struct  list_node * p=head;
        do{
            printf("%d\n",p->num);
            p=p->next;
        }
        while (p!=head);
    }
    else
        printf("Emply list!\n");
}


int main() {

	int count;
	printf("Количество войнов:");
	scanf("%d",&count);
	struct  list_node *p=NULL;
	struct  list_node *temp;
	//printf("qqqq\n");
	
	//printf("qqqq7\n");
	for (int i = 1; i <=count; ++i)
	{	//printf("qqqq8\n");
		temp=create_node(i);
		//printf("qqqq9\n");
		p=add_node(p,temp);
	}

	int m;
	printf("Удаляем каждого:");
	scanf("%d",&m);

	p=p->next;

	list_print(p);

	do

	{
		for (int i = 1; i <m; ++i)
		{
			p=p->next;
		}
		p=del_elem(p);
		
		count--;
	}
	while(count!=1);

	printf("Ответ: %d\n",p->num);
	list_print(p);
	



	while((p=del_elem(p))!=NULL)
		;


	

    
    return 0;
}
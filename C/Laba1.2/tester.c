#include "functions.h"
#define GOOD 0
#define BAD 11
#define EPS 0.001
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define STR_LEN 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_memcmp(void *p1_st, void *p1_end,void *p2_st,void *p2_end)
{
    if((p1_end-p1_st)!=(p1_end-p1_st))
        return BAD;
    if(memcmp(p1_st, p2_st ,p1_end-p1_st)!=0)
    	return BAD;
    return GOOD;
}

char *answer(int val)
{
    char *answer = "FAIL";
    if (val == GOOD)
    {
        printf("%s", KGRN);
        answer = "OK";
    }
    else
        printf("%s", KRED);
    return answer;   
}


int int_test_filter(int *in, int in_n, int *answer, int ans_n)
{
	int res=GOOD;
	int *ans = NULL;
	int *ans_end = NULL;
    filter(in, in + in_n, &ans, &ans_end);
    res=my_memcmp(ans, ans_end,answer,answer+ans_n);
    free(ans);
	return res;
}

void test_filter()
{
	//test 1
	int in1[] = { 4, 1, 2 };
	int ans1[] = { 4, 2 };
	printf("test_filter_1 \t%s\n", answer(int_test_filter(in1, 3, ans1, 2)));
	//test 2
	int in2[] = { 1, 2, 3 };
	int ans2[] = { 3 };
	
	printf("test_filter_2 \t%s\n", answer(int_test_filter(in2, 3, ans2, 1)));
	//test 3
	int in3[] = { 10, 5, 2 };
	int ans3[] = { 10, 5, 2 };
	
	printf("test_filter_3 \t%s\n", answer(int_test_filter(in3, 3, ans3, 3)));
}

int binary_search(int *in, int in_n,int in_size, void* value, int ans_index)
{
	void* tmp;

	//printf("axxxx\n");

	tmp=bin_search((void*)in, (void*) in+in_n*in_size,  value, in_size,compare_int_less);

	//printf("%d\n",*(int*)tmp );
	//printf("%d %d\n",(int*) (in+ans_index),(int*) tmp);
	if (tmp==in+ans_index)
	{
		return GOOD;
	}
	else
		return BAD;
}

void test_int_binary_search()
{
	int size=sizeof(int);
	void *tmp = malloc(size);
	int t=0;;
	int in1[] = { 0, 1, 2, 3, 4 };
	//test 1
	t=in1[2];
	memcpy(tmp, &t, size);
	printf("int_binary_search_1 \t%s\n", answer(binary_search(in1,5,size,tmp, 2)));

	//test 2
	t=-3;
	memcpy(tmp, &t, size);
	printf("int_binary_search_2 \t%s\n", answer(binary_search(in1,5,size,tmp, 0)));

	//test 3
	
	t=6;
	memcpy(tmp, &t,size);
	printf("int_binary_search_3 \t%s\n", answer(binary_search(in1,5,size,tmp, 5)));

	free(tmp);
}


int int_insert_sort(int *in, int *in2, int in_n)
{

	mod_insertion_sort(in, in_n, sizeof(int), compare_int_less);
	qsort(in2, in_n, sizeof(int), compare_int_less);
	if(memcmp(in, in2, in_n)==0) return GOOD;
	else return BAD;
}

void test_int_insert_sort()
{
	{
		//test 1
		int in11[] = { 5, 4, 2, 3, 1 };
		int in12[] = { 5, 4, 2, 3, 1 };
		int n = sizeof(in11)/sizeof(in11[0]);
		printf("int_insert_sort_1 \t%s\n", answer(int_insert_sort(in11, in12, n)));
	}

	{
		//test 2
		int in11[] = { 0, 1, 2, 3, 4 };
		int in12[] = { 0, 1, 2, 3, 4 };
		int n = sizeof(in11)/sizeof(in11[0]);
		printf("int_insert_sort_2 \t%s\n", answer(int_insert_sort(in11, in12, n)));
	}


	{
		//test 3
		int in11[] = { 0 };
		int in12[] = { 0 };
		int n = sizeof(in11)/sizeof(in11[0]);
		printf("int_insert_sort_3 \t%s\n", answer(int_insert_sort(in11, in12, n)));
	}


	{
		//test 4
		int in11[] = { 1, 3, 2, 5, -9 };
		int in12[] = { 1, 3, 2, 5, -9 };
		int n = sizeof(in11)/sizeof(in11[0]);
		printf("int_insert_sort_4 \t%s\n", answer(int_insert_sort(in11, in12, n)));
	}


	{
		//test 5
		int in11[] = { 1, 3, 2, 5, 2, 2 };
		int in12[] = { 1, 3, 2, 5, 2, 2 };
		int n = sizeof(in11)/sizeof(in11[0]);
		printf("int_insert_sort_5 \t%s\n", answer(int_insert_sort(in11, in12, n)));
	}

	{
		//test 6
		int in11[] = { 1, 2 };
		int in12[] ={ 1, 2 };
		int n = sizeof(in11)/sizeof(in11[0]);
		printf("int_insert_sort_6 \t%s\n", answer(int_insert_sort(in11, in12, n)));
	}

	{
		//test 7
		int in11[] = { 2, 1 };
		int in12[] = { 2, 1 };
		int n = sizeof(in11)/sizeof(in11[0]);
		printf("int_insert_sort_7 \t%s\n", answer(int_insert_sort(in11, in12, n)));
	}
}


int double_insert_sort(double *in, double *in2, double in_n)
{

	//printarrayd(in,in_n);
	mod_insertion_sort(in, in_n, sizeof(double), &compare_double_less);
	//printarrayd(in, in_n);

	//printarrayd(in2,in_n);
	qsort(in2, in_n, sizeof(double), compare_double_less);
	//printarrayd(in2,in_n);
	if(memcmp(in, in2, in_n)==0) return GOOD;
	else return BAD;
}

void test_double_insert_sort()
{
	//test 1
	double in11[] = { 5.0, 4.0, 2.0, 3.0, 1.0 };
	double in12[] = { 5.0, 4.0, 2.0, 3.0, 1.0 };
	int n = sizeof(in11)/sizeof(in11[0]);
	printf("double_insert_sort_1 \t%s\n", answer(double_insert_sort(in11, in12, n)));
	
	//test 2
	double in21[] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
	double in22[] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
	n = sizeof(in21)/sizeof(in21[0]);
	printf("double_insert_sort_2 \t%s\n", answer(double_insert_sort(in21, in22, n)));

	//test 3
	double in31[] = { 1.3 };
	double in32[] = { 1.3 };
	n = sizeof(in31)/sizeof(in31[0]);
	printf("double_insert_sort_3 \t%s\n", answer(double_insert_sort(in31, in32, n)));

	//test 4
	double in41[] = { 1.4, 3.4, 2.4, 5.4, -9.4 };
	double in42[] = { 1.4, 3.4, 2.4, 5.4, -9.4 };
	n = sizeof(in41)/sizeof(in41[0]);
	printf("double_insert_sort_4 \t%s\n", answer(double_insert_sort(in41, in42, n)));

	//test 5
	double in51[] = { 2.5, 5.3, 2.5, 4.5, 2.5 };
	double in52[] = { 2.5, 5.3, 2.5, 4.5, 2.5 };
	n = sizeof(in51)/sizeof(in51[0]);
	printf("double_insert_sort_5 \t%s\n", answer(double_insert_sort(in51, in52, n)));

	//test 6
	double in61[] = { 1.6, 2.6 };
	double in62[] = { 1.6, 2.6 };
	n = sizeof(in61)/sizeof(in61[0]);
	printf("double_insert_sort_6 \t%s\n", answer(double_insert_sort(in61, in62, n)));

	//test 7
	double in71[] = { 2.7, 1.7 };
	double in72[] = { 2.7, 1.7 };
	n = sizeof(in71)/sizeof(in71[0]);
	printf("double_insert_sort_7 \t%s\n", answer(double_insert_sort(in71, in72, n)));

}




struct struct_t 
{
	int int_v;
	double double_v;
	char str[50];
};

struct struct_t *create_struct_array(char str[][STR_LEN],int *int1, double* double1, int n)
{
	
	struct struct_t * arr = malloc(n * sizeof(struct struct_t));
	if (!arr)
		return NULL;

	for (int i = 0; i < n; i++)
	{
		strcpy(arr[i].str, str[i]);
		arr[i].int_v = int1[i];
		arr[i].double_v = double1[i];
	}
	return arr;
}


int struct_double_comparator(const void *val1, const void *val2)
{
    struct struct_t *a = (struct struct_t *) val1;
    struct struct_t *b = (struct struct_t *) val2;
    //printf("EEEEEEEEEEEEEE %lf  %lf\n", *b , *a);
    return (a->double_v) - (b->double_v);
}

int min(int a, int b)
{
	if(a<b) return a;
	else return b;
}

int struct_char_comparator(const void *val1, const void *val2)
{
    struct struct_t *a = (struct struct_t *) val1;
    struct struct_t *b = (struct struct_t *) val2;
    //printf("EEEEEEEEEEEEEE %lf  %lf\n", *b , *a);
    for (int i = 0; i < min(strlen(a->str),strlen(b->str)); ++i)
    {
    	if(a->str[i]!=b->str[i])
    	{

    	if(a->str[i]<b->str[i])
    		return -1;
    	else
    		return 1;

    	}

    }
    return 0;
}

int struct_int_comparator(const void *val1, const void *val2)
{
    struct struct_t *a = (struct struct_t *) val1;
    struct struct_t *b = (struct struct_t *) val2;
    //printf("EEEEEEEEEEEEEE %lf  %lf\n", *b , *a);
    return (a->int_v) - (b->int_v);
}


int struct_insert_sort(struct struct_t in1[], struct struct_t in2[], int in_n, int (*comparator)(const void *, const void *))
{
	mod_insertion_sort(in1, in_n, sizeof(struct struct_t), comparator);
	qsort(in2, in_n, sizeof(struct struct_t), comparator);

	for (int i = 0; i < in_n; ++i)
	{
		if(comparator(&in1[i],&in2[i])!=0)
			return BAD;
	}
	return GOOD;
}


void test_struct_insert_sort()
{
	//array 1
	int int_v1[] = { 2, 1, 3 };
	char str1[][STR_LEN] = { "ac", "ab", "aa" };
	double double_v1[] = { 0.1, -1.1, 0.01 };
	int n1 = sizeof(int_v1) / sizeof(int_v1[0]);
	
	//array 2
	int int_v2[] = { 3 };
	char str2[][STR_LEN] = { "aa" };
	double double_v2[] = { 0.01 };
	int n2 = sizeof(int_v2) / sizeof(int_v2[0]);

	//array 3
	int int_v3[] = { 1, 2, 3 };
	char str3[][STR_LEN] = { "aa", "bb", "cc" };
	double double_v3[] = { 0.1, 0.2, 0.3 };
	int n3 = sizeof(int_v3) / sizeof(int_v3[0]);

	//array 4
	int int_v4[] = { 2, 1 };
	char str4[][STR_LEN] = { "adac", "aba" };
	double double_v4[] = { 0.7, 0.2 };
	int n4 = sizeof(int_v4) / sizeof(int_v4[0]);
	

	struct struct_t *in11 = create_struct_array(str1, int_v1, double_v1, n1);
	struct struct_t *in12 = create_struct_array(str1, int_v1, double_v1, n1);

	struct struct_t *in21 = create_struct_array(str2, int_v2, double_v2, n2);
	struct struct_t *in22 = create_struct_array(str2, int_v2, double_v2, n2);

	struct struct_t *in31 = create_struct_array(str3, int_v3, double_v3, n3);
	struct struct_t *in32 = create_struct_array(str3, int_v3, double_v3, n3);

	struct struct_t *in41 = create_struct_array(str4, int_v4, double_v4, n4);
	struct struct_t *in42 = create_struct_array(str4, int_v4, double_v4, n4);


	printf("struct_int_sort_1 \t%s\n", answer(struct_insert_sort(in11, in12, n1, struct_int_comparator)));
	printf("struct_int_sort_2 \t%s\n", answer(struct_insert_sort(in21, in22, n2, struct_int_comparator)));
	printf("struct_int_sort_3 \t%s\n", answer(struct_insert_sort(in31, in32, n3, struct_int_comparator)));
	printf("struct_int_sort_4 \t%s\n", answer(struct_insert_sort(in41, in42, n4, struct_int_comparator)));
	
	printf("struct_double_sort_1 \t%s\n", answer(struct_insert_sort(in11, in12, n1, struct_double_comparator)));
	printf("struct_double_sort_2 \t%s\n", answer(struct_insert_sort(in21, in22, n2, struct_double_comparator)));
	printf("struct_double_sort_3 \t%s\n", answer(struct_insert_sort(in31, in32, n3, struct_double_comparator)));
	printf("struct_double_sort_4 \t%s\n", answer(struct_insert_sort(in41, in42, n4, struct_double_comparator)));
	
	printf("struct_char_sort_1 \t%s\n", answer(struct_insert_sort(in11, in12, n1, struct_char_comparator)));
	printf("struct_char_sort_1 \t%s\n", answer(struct_insert_sort(in21, in22, n2, struct_char_comparator)));
	printf("struct_char_sort_1 \t%s\n", answer(struct_insert_sort(in31, in32, n3, struct_char_comparator)));
	printf("struct_char_sort_1 \t%s\n", answer(struct_insert_sort(in41, in42, n4, struct_char_comparator)));
	

	free(in11);
	free(in12);
	free(in21);
	free(in22);
	free(in31);
	free(in32);
	free(in41);
	free(in42);
}

int main(int argc, char const *argv[])
{

	test_filter();	
	test_int_binary_search();
	test_int_insert_sort();
	test_double_insert_sort();
	test_struct_insert_sort();
	return 0;
}
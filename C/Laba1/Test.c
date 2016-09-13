#include <stdio.h>
#include "functions.h"
#include <math.h>

#define MAX_ARRAY_LENGTH 10

#define ERROR_ARG -1
#define ERROR_OPEN_INPUT_FILE -2
#define ERROR_OPEN_OUTPUT_FILE -4
#define FILE_IS_NORMAL 0
#define FILE_IS_TOO_LARGE 1

#define OK 0
#define DIVISION_BY_ZERO -3

#define FAILED -10

int TestRead1() {
    int status_test = OK;
    int code = OK;

    double array_of_all_numbers[MAX_ARRAY_LENGTH];
    int length_array_of_all_numbers = 0;


    FILE *file1 = fopen("tests/empty_file", "r+");
    code = ReadDataFromFile(array_of_all_numbers, &length_array_of_all_numbers, file1);
    if ((code != FILE_IS_NORMAL) || (length_array_of_all_numbers != 0))
        status_test = FAILED;

    return status_test;
}

int TestRead2() {
    int status_test = OK;
    int code = OK;

    double array_of_all_numbers[MAX_ARRAY_LENGTH];
    double control_array[MAX_ARRAY_LENGTH] = {1.0, 2.5, 3.7, 4.3, 5.66666, 3.11, 3.22};
    int length_array_of_all_numbers = 0;


    FILE *file1 = fopen("tests/lower_then_limit", "r+");
    code = ReadDataFromFile(array_of_all_numbers, &length_array_of_all_numbers, file1);
    if ((code != FILE_IS_NORMAL) || (length_array_of_all_numbers != 7))
        status_test = FAILED;

    for (int i = 0; i < length_array_of_all_numbers; ++i) {
        if (array_of_all_numbers[i] != control_array[i]) {
            status_test = FAILED;
            break;
        }
    }

    return status_test;
}

int TestRead3() {
    int status_test = OK;
    int code = OK;

    double array_of_all_numbers[MAX_ARRAY_LENGTH];
    double control_array[MAX_ARRAY_LENGTH] = {1.0, 2.5, 3.7, 4.3, 5.66666, 3.11, 3.22, 1.7, 5.75, -2.7};
    int length_array_of_all_numbers = 0;


    FILE *file1 = fopen("tests/limit", "r+");
    code = ReadDataFromFile(array_of_all_numbers, &length_array_of_all_numbers, file1);

    if ((code != FILE_IS_NORMAL) || (length_array_of_all_numbers != MAX_ARRAY_LENGTH))
        status_test = FAILED;

    for (int i = 0; i < length_array_of_all_numbers; ++i) {
        if (array_of_all_numbers[i] != control_array[i]) {
            status_test = FAILED;
        }

    }

    return status_test;
}

int TestRead4() {
    int status_test = OK;
    int code = OK;

    double array_of_all_numbers[MAX_ARRAY_LENGTH];
    const double control_array[MAX_ARRAY_LENGTH] = {1.0, 2.5, 3.7, 4.3, 5.66666, 3.11, 3.22, 1.7, 5.75, -2.7};
    int length_array_of_all_numbers = 0;


    FILE *file1 = fopen("tests/more_then_limit", "r+");
    code = ReadDataFromFile(array_of_all_numbers, &length_array_of_all_numbers, file1);

    if ((code != FILE_IS_TOO_LARGE) || (length_array_of_all_numbers != MAX_ARRAY_LENGTH))
        status_test = FAILED;

    for (int i = 0; i < length_array_of_all_numbers; ++i) {
        if (array_of_all_numbers[i] != control_array[i]) {
            status_test = FAILED;

        }
    }

    return status_test;
}

int TestAverage1() {
    double array_of_all_numbers[MAX_ARRAY_LENGTH];
    int length_array_of_all_numbers = 0;
    double average = 0;
    int code = Average(array_of_all_numbers, length_array_of_all_numbers, &average);
    if ((code != DIVISION_BY_ZERO) && (average != 0))
        return FAILED;

    return OK;
}


int TestAverage2() {
    double array_of_all_numbers[MAX_ARRAY_LENGTH] = {1.0, 2.5, 3.7, 4.3, 5.66666, 3.11, 3.22, 1.7, 5.75, -2.7};
    int length_array_of_all_numbers = 10;
    double average = 0;
    int code = Average(array_of_all_numbers, length_array_of_all_numbers, &average);

    if ((code != DIVISION_BY_ZERO) && (fabs(average - 2.824666) > 0.0001))
        return FAILED;

    return OK;
}


int TestAverage3() {
    double array_of_all_numbers[MAX_ARRAY_LENGTH] = {1.0, 2.5, 3.7, 4.3, 5.66666, 3.11, 3.22};;
    int length_array_of_all_numbers = 7;
    double average = 0;
    int code = Average(array_of_all_numbers, length_array_of_all_numbers, &average);

    if ((code != DIVISION_BY_ZERO) && (fabs(average - 3.356666) > 0.0001))
        return FAILED;

    return OK;
}


int TestCreate1() {
    double array_of_all_numbers[MAX_ARRAY_LENGTH] = {1.0, 2.5, 3.7, 4.3, 5.66666, 3.11, 3.22};
    int length_array_of_all_numbers = 7;

    double array_of_numbers_bigger_average[MAX_ARRAY_LENGTH];
    int length_array_of_numbers_bigger_average = 0;

    double average = 3.356666;

    int status = OK;
    const double control_array_of_numbers_bigger_average[MAX_ARRAY_LENGTH] =
            {3.7, 4.3, 5.66666, 5.75};
    const int control_length_array_of_numbers_bigger_average = 3;

    CreateArrayBiggerAverage(array_of_all_numbers, array_of_numbers_bigger_average,
                             average, length_array_of_all_numbers, &length_array_of_numbers_bigger_average);

    if (length_array_of_numbers_bigger_average == control_length_array_of_numbers_bigger_average) {
        for (int i = 0; i < control_length_array_of_numbers_bigger_average; ++i) {

            if (array_of_numbers_bigger_average[i] != control_array_of_numbers_bigger_average[i]) {
                status = FAILED;
                break;
            }
        }
    }
    else {
        status = FAILED;
    }
    return status;

}

int TestCreate2() {
    double array_of_all_numbers[MAX_ARRAY_LENGTH] = {1.0, 2.5, 3.7, 4.3, 5.66666, 3.11, 3.22, 1.7, 5.75, -2.7};
    int length_array_of_all_numbers = 10;

    double array_of_numbers_bigger_average[MAX_ARRAY_LENGTH];
    int length_array_of_numbers_bigger_average = 0;

    double average = 2.824666;

    int status = OK;
    const double control_array_of_numbers_bigger_average[MAX_ARRAY_LENGTH] =
            {3.7, 4.3, 5.66666, 3.11, 3.22, 5.75};
    const int control_length_array_of_numbers_bigger_average = 6;

    CreateArrayBiggerAverage(array_of_all_numbers, array_of_numbers_bigger_average,
                             average, length_array_of_all_numbers, &length_array_of_numbers_bigger_average);

    if (length_array_of_numbers_bigger_average == control_length_array_of_numbers_bigger_average) {
        for (int i = 0; i < control_length_array_of_numbers_bigger_average; ++i) {

            if (array_of_numbers_bigger_average[i] != control_array_of_numbers_bigger_average[i]) {
                status = FAILED;
                break;
            }
        }
    }
    else {
        status = FAILED;
    }
    return status;

}

char *answer(int val) {
    char *answer = "FAILED";
    if (val == OK)
        answer = "OK";
    return answer;
}

int main() {
    printf("TestRead1 %s\n", answer(TestRead1()));
    printf("TestRead2 %s\n", answer(TestRead2()));
    printf("TestRead3 %s\n", answer(TestRead3()));
    printf("TestRead4 %s\n", answer(TestRead4()));
    printf("TestAverage1 %s\n", answer(TestAverage1()));
    printf("TestAverage2 %s\n", answer(TestAverage2()));
    printf("TestAverage3 %s\n", answer(TestAverage3()));
    printf("TestCreate1 %s\n", answer(TestCreate1()));
    printf("TestCreate2 %s\n", answer(TestCreate2()));

    return 0;
}
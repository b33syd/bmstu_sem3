//
// Created by alexey on 13.11.16.
//

#ifndef TISD4_LIB_H
#define TISD4_LIB_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define START_SIZE 10000
#define MAX_MEMORY 100

struct info_queue {
    int tmp_size = 0;
    int sum_size = 0;
    int count_request = 0;
    int in_request = 0;
    int out_request = 0;
    int sum_time = 0;
};

#endif //TISD4_LIB_H

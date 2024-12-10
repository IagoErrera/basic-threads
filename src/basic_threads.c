#include <stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* task_1(void* arg) {
    int* n = (int*)arg;
    int* j = (int*)(malloc(sizeof(int)));
    *j = 0;
    for (int i = 0; i <= *n; i++) {
        printf("Task 1: %d\r\n", i);
        fflush(stdout);
        *j += i;
        sleep(1);
    }

    return j;
}

void* task_2(void* arg) {
    int* n = (int*)arg;
    int* j = (int*)(malloc(sizeof(int)));
    *j = 0;
    for (int i = 0; i <= *n; i++) {
        printf("Task 2: %d\r\n", i);
        fflush(stdout);
        *j += i;
        sleep(2);
    }

    return j;
}

int main() {
    pthread_t thread_1, thread_2;
    int *task_1_result, *task_2_result;
    int n1 = 5, n2 = 3;

    pthread_create(&thread_1, NULL, task_1, &n1);
    pthread_create(&thread_2, NULL, task_2, &n2);

    pthread_join(thread_1, (void**)&task_1_result);
    pthread_join(thread_2, (void**)&task_2_result);

    printf("Task 1 result: %d\n\r", *task_1_result);
    printf("Task 2 result: %d\n\r", *task_2_result);
    fflush(stdout);

    free(task_1_result);
    free(task_2_result);

    return 0;
}
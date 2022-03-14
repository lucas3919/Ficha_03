#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int X;
int Y, Z;
int qnt_num, total = 0;
int num[0];

void *average() {

    X = total/qnt_num;
}

void *minimum() {
    int minimum = num[0];
    int index;

    for (index = 1; index < qnt_num; index++) {
        
        if (num[index] < minimum) {
            minimum = num[index];
        }
    }

    Y = minimum;
}

void *maximum() {
    int maximum = num[0];
    int index;
    for (index = 1; index < qnt_num; index++) {
        
        if (num[index] > maximum) {
            maximum = num[index];
        }
    }

    Z = maximum;
}

int main () {

    pthread_t thread_1;
    pthread_t thread_2;
    pthread_t thread_3;

    scanf("%d", &qnt_num);
    

    for (int index = 0; index < qnt_num; index++) {
        scanf("%d", &num[index]);
        total += num[index];
    }
    
    pthread_create(&thread_1, NULL, &average, NULL);
    pthread_join(thread_1, NULL);

    pthread_create(&thread_2, NULL, &minimum, NULL);
    pthread_join(thread_2, NULL);

    pthread_create(&thread_3, NULL, &maximum, NULL);
    pthread_join(thread_3, NULL);

    printf("The average value is: %d\n", X);
    printf("The minimum value is: %d\n", Y);
    printf("The maximum value is: %d", Z);

    return 0;
}
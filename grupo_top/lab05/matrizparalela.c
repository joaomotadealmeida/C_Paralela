#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define MAX_M 1000  
#define MAX_N 1000  
#define MAX_THREADS 16  

int m = 1000;  
int n = 1000;  
double A[MAX_M][MAX_N];  
double x[MAX_N];  
double y[MAX_M];
int thread_count = 4;  
void *Ph_math_vect(void *rank) {
    long my_rank = (long)rank;
    int local_m = m / thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (int i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0;
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    long thread;
    clock_t start_time = clock();
    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&threads[thread], NULL, Ph_math_vect, (void *)thread);
    }
    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(threads[thread], NULL);
    }
    clock_t end_time = clock();
    printf("Tempo de execução: %.6lf segundos\n", ((double)(end_time - start_time)) / CLOCKS_PER_SEC);

    return 0;
}

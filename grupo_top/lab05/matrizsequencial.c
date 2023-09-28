#include <stdio.h>
#include <time.h>
void serial_matrix_vector_multiply(int m, int n, double A[m][n], double x[n], double y[m]) {
    int i, j;

    for (i = 0; i < m; i++) {
        y[i] = 0.0;
        for (j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    int m = 1000; 
    int n = 1000;  
    double A[m][n];
    double x[n];
    double y[m];
    clock_t start_time = clock();
    serial_matrix_vector_multiply(m, n, A, x, y);
    clock_t end_time = clock();
    printf("Tempo de execução: %.6lf segundos\n", ((double)(end_time - start_time)) / CLOCKS_PER_SEC);

    return 0;
}

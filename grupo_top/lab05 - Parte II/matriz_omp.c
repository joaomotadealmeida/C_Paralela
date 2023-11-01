#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Omp_mat_vect(double A[], double x[], double y[], int m, int n, int thread_count);
void Gen_matrix(double A[], int m, int n);
void Gen_vector(double x[], int n);

int main(int argc, char* argv[]) {
   int thread_count;
   int m, n;
   double* A;
   double* x;
   double* y;

   if (argc != 2) {
      fprintf(stderr, "usage: %s <number of threads>\n", argv[0]);
      return 1;
   }

   thread_count = strtol(argv[1], NULL, 10);
   printf("Digite o valor de m e n\n");
   scanf("%d", &m);
   scanf("%d", &n);

   A = malloc(m*n*sizeof(double));
   x = malloc(n*sizeof(double));
   y = malloc(m*sizeof(double));

   Gen_matrix(A, m, n); //Gera matriz
   Gen_vector(x, n); // Gera vetor

   Omp_mat_vect(A, x, y, m, n, thread_count);

   free(A);
   free(x);
   free(y);

   return 0;
}

double f(double x) {
   double return_val;

   return_val = x * x;
   return return_val;
}

void Omp_mat_vect(double A[], double x[], double y[],
      int m, int n, int thread_count) {
   int i, j;
   double start, finish, elapsed;

   start = omp_get_wtime();
#  pragma omp parallel for num_threads(thread_count)  \
      default(none) private(i, j)  shared(A, x, y, m, n)
   for (i = 0; i < m; i++) {
      y[i] = 0.0;
      for (j = 0; j < n; j++)
         y[i] += A[i*n+j]*x[j];
   }
   finish = omp_get_wtime();
   elapsed = finish - start;
   printf("Tempo = %e segundos\n", elapsed);
}

void Gen_matrix(double A[], int m, int n) {
   int i, j;
   for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
         A[i*n+j] = random()/((double) RAND_MAX);
}

void Gen_vector(double x[], int n) {
   int i;
   for (i = 0; i < n; i++)
      x[i] = random()/((double) RAND_MAX);
}

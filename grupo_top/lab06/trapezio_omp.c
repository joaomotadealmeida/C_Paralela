#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x);
double calcula_trapezio(double a, double b, int n, int thread_count);

int main(int argc, char* argv[]) {
   double global_result = 0.0;
   double a, b;
   int n;
   int thread_count;

   if (argc != 2) {
      fprintf(stderr, "usage: %s <number of threads>\n", argv[0]);
      return 1;
   }

   thread_count = strtol(argv[1], NULL, 10);
   printf("Digite o valor de a, b e n\n");
   scanf("%lf", &a);
   scanf("%lf", &b);
   scanf("%d", &n);

   double start_time = omp_get_wtime();  // Marca o início do cálculo.

   global_result = calcula_trapezio(a, b, n, thread_count);

   double end_time = omp_get_wtime();    // Marca o fim do cálculo.
   double elapsed_time = end_time - start_time;

   printf("O resultado com %f e %f = %.14e\n", a, b, global_result);
   printf("Tempo de execução: %f segundos\n", elapsed_time);

   return 0;
}

double f(double x) {
   double return_val;

   return_val = exp(x);
   return return_val;
}

double calcula_trapezio(double a, double b, int n, int thread_count) {
   double h, approx;
   int i;

   h = (b - a) / n;
   approx = (f(a) + f(b)) / 2.0;

#pragma omp parallel for num_threads(thread_count) \
      reduction(+: approx)
   for (i = 1; i <= n - 1; i++)
      approx += f(a + i * h);
   approx = h * approx;

   return approx;
}

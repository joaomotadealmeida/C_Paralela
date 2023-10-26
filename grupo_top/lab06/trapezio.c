#include <stdio.h>
#include <time.h>
#include <math.h>

double calcula_trapezio(double a, double b, int n, double h);
double f(double x);

int main(void) {
   double resultado;
   double a, b;
   int n;
   double h;

   printf("Digite o valor de a, b e n\n");
   scanf("%lf", &a);
   scanf("%lf", &b);
   scanf("%d", &n);

   h = (b - a) / n;

   clock_t start_time = clock();  // Marca o início do cálculo.

   resultado = calcula_trapezio(a, b, n, h);

   clock_t end_time = clock();    // Marca o fim do cálculo.
   double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

   printf("Com n = %d\n", n);
   printf("O resultado com %f e %f = %.15f\n", a, b, resultado);
   printf("Tempo de execução: %.6f segundos\n", elapsed_time);

   return 0;
}

double calcula_trapezio(double a, double b, int n, double h) {
   double resultado = (f(a) + f(b)) / 2.0;
   int k;

   for (k = 1; k <= n - 1; k++) {
     resultado += f(a + k * h);
   }

   resultado = resultado * h;

   return resultado;
}

double f(double x) {
   return exp(x);
}

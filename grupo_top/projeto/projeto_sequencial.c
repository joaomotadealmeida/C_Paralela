#include <gmp.h>
#include <stdio.h>

// FUNCAO FATORIAL
void funcfatorial(int n, mpz_t resultado) {
    if (n == 0) {
        mpz_set_ui(resultado, 1);         // Se n = 0, fatorial = 1
    } else {
        mpz_t temp;                       // MPZ representa funções aritméticas inteiras de alto nível de precisão 
        mpz_init(temp);                   // Inicializa uma variável temporária
        funcfatorial(n - 1, temp);        // Chama recursivamente para calcular (n-1)!
        mpz_mul_ui(resultado, temp, n);   // Multiplica o resultado por n
        mpz_clear(temp);                  // Libera a variável temporária
    }
}

// FUNCAO TESTE DE EULER
void EulerTest(int precisao, mpf_t resultado) {
  mpf_t resultado_parcial;                // MPF representa funções aritméticas de ponto flutuante de alto nível de precisão 
  mpf_init2(resultado_parcial, 10000);    // Inicializa a variável para resultado parcial
  mpz_t fatorial;
  mpz_init(fatorial);                     // Inicializa a variável armazenando fatoriais

  mpf_init2(resultado, 10000);             // Inicializa o resultado final

  // Loop
  for (int i = 0; i <= precisao; i++) {
    funcfatorial(i, fatorial);
    mpf_set_z(resultado_parcial, fatorial);
    mpf_ui_div(resultado_parcial, 1, resultado_parcial);
    mpf_add(resultado, resultado, resultado_parcial);
  }

  mpf_clear(resultado_parcial); // Libera a variável para resultado parcial
  mpz_clear(fatorial);          // Libera a variável para os fatoriais
}

int main() {
  int n = 0;
  printf("num : ");
  scanf("%d", &n);

  mpf_t resultado;
  EulerTest(n, resultado);

  gmp_printf("result %.2000Ff\n", resultado);

  mpf_clear(resultado); // Libera a variável do resultado final

  return 0;
}

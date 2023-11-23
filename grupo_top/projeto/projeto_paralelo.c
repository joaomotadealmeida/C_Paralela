#include <stdio.h>
#include <gmp.h>
#include <omp.h>

// FUNCAO FATORIAL
void fatorial(int n, mpz_t resultado) {
    if (n == 0) {
        mpz_set_ui(resultado, 1);  // Se n = 0, fatorial = 1
    } else {
        mpz_t temp; // MPZ representa funções aritméticas inteiras de alto nível de precisão 
        mpz_init(temp);                   // Inicializa uma variável temporária
        fatorial(n - 1, temp);            // Chama recursivamente para calcular (n-1)!
        mpz_mul_ui(resultado, temp, n);   // Multiplica o resultado por n
        mpz_clear(temp);                  // Libera a variável temporária
    }
}

// FUNCAO TESTE DE EULER
void Euler(int precisao, mpf_t resultado, int numero_threads) {
    mpf_t resultado_parcial; // MPF representa funções aritméticas de ponto flutuante de alto nível de precisão 
    mpf_init2(resultado_parcial, 10000);  // Inicializa a variável para resultado parcial

    mpz_t fat;
    mpz_init(fat);  // Inicializa a variável armazenando fatoriais

    mpf_init2(resultado, 10000);  // Inicializa o resultado final
    mpf_set_d(resultado, 0.0);   // Inicializa resultado como 0.0

    // Loop paralelizado usando OpenMP para calcular a série infinita
    #pragma omp parallel for num_threads(numero_threads)
    for (int i = 0; i <= precisao; i++) {
        mpz_t fatorial_local;
        mpf_t resultado_parcial_local;

        mpz_init(fatorial_local);          // Inicializa variável temporária para o fatorial local
        mpf_init2(resultado_parcial_local, 10000);  // Inicializa variável temporária para resultado parcial local

        fatorial(i, fatorial_local);       // Calcula o fatorial para o índice atual
        mpf_set_z(resultado_parcial_local, fatorial_local);  // Converte o fatorial para ponto flutuante
        mpf_ui_div(resultado_parcial_local, 1, resultado_parcial_local);  // Calcula 1/fatorial

        // Seção crítica para evitar condições de corrida ao atualizar o resultado global
        #pragma omp critical
        mpf_add(resultado, resultado, resultado_parcial_local);  // resultado parcial -> resultado final

        mpz_clear(fatorial_local);            // Libera a variável temporária para fatorial local
        mpf_clear(resultado_parcial_local);   // Libera a variável temporária para resultado parcial local
    }

    mpf_clear(resultado_parcial);  // Libera a variável para resultado parcial
    mpz_clear(fat);           // Libera a variável para os fatoriais
}

// MAIN
int main(int argc, char *argv[]) {
    // Verifica se o número correto de argumentos da linha de comando foi fornecido
    if (argc != 3) {
        printf("Uso: %s <precisao> <numero_threads>\n", argv[0]);
        return 1;
    }

    // Converte argumentos da linha de comando para valores inteiros
    int n = 0;
    sscanf(argv[1], "%d", &n);

    int numero_threads = 0;
    sscanf(argv[2], "%d", &numero_threads);

    mpf_t resultado;
    Euler(n, resultado, numero_threads);

    gmp_printf("resultado %.2500Ff\n", resultado);

    mpf_clear(resultado);  // Libera a variável do resultado final

    return 0;
}

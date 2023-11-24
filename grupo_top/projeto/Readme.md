• Como compilar o programa na plataforma disponibilizada:

gcc -o projeto_paralelo projeto_paralelo.c  -fopenmp -lgmp -lm

• Como executar o programa:

./projeto_paralelo 10000 <numero_threads>

• Comprovação de resultados:


• Descrição simples do algoritmo e estratégia de paralelismo adotada:
  Primeiramente a linguagem escolhida foi a linguagem C, pois além de ser a linguagem estudada em aula, ela possui a biblioteca GMP, sendo ela a principal bibliteca para o projeto. A biblioteca GMP  é uma biblioteca livre para aritmética de precisão arbitrária, operando com números inteiros, racionais e de ponto flutuante e sua utilização é necessária uma vez que outras bibliotecas mais simples (como a math.h) não conseguem trabalhar com a divisão de grandes números de ponto flutuante, e utilizando a GMP isso é possivel pois nela não há limite prático para a precisão, exceto os implicados pela memória disponível na máquina. O código possui 3 principais funções sendo uma a Main, fatorial e Euler. A função fatorial realizará o calculo fatorial, recebendo um valor int n que é número para o qual o fatorial está sendo calculado e um mpz que armazenará o resultado do fatorial. A função utiliza uma abordagem recursiva para calcular o fatorial onde se n for zero, a função atribui 1 à variável "resultado", caso contrário a função cria uma variável temporária temp, chama recursivamente a função fatorial para calcular (n-1)! e em seguida, multiplica o resultado pelo valor de n. A função Euler calcula a série de Euler de maneira paralela, usando threads para acelerar o processo, e a precisão dos resultados é mantida usando a biblioteca GMP. Por fim, main é responsável por inicializar o programa, obter e converter os argumentos da linha de comando, calcular a série de Euler chamando a função Euler, imprimir o resultado e liberar os recursos alocados durante a execução do programa.

  




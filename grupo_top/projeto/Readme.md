• Como compilar o programa na plataforma disponibilizada:

gcc -o projeto_paralelo projeto_paralelo.c  -fopenmp -lgmp -lm

• Como executar o programa:

./projeto_paralelo 10000 <numero_threads>

• Comprovação de resultados:
Execução serial:
![image](https://github.com/joaomotadealmeida/C_Paralela/assets/93838303/4639eab0-a37f-4280-9f5c-1419cb82a487)
Execução paralela com 2 threads:
![image](https://github.com/joaomotadealmeida/C_Paralela/assets/93838303/4ba25b50-b62d-4ce4-bec9-c8fbd3112d3d)
Execução paralela com 3 threads:
![image](https://github.com/joaomotadealmeida/C_Paralela/assets/93838303/b0e2481c-1726-47f4-a3a6-026defbaf26a)
Execução paralela com 5 threads:
![image](https://github.com/joaomotadealmeida/C_Paralela/assets/93838303/b29c24b1-182c-462d-91c4-f09116c3f9fa)
Execução paralela com 60 threads:
![image](https://github.com/joaomotadealmeida/C_Paralela/assets/93838303/893b012f-8a48-4851-b3f7-e2b50164fd8b)

Como podemos observar, quando utilizamos 2 e 3 threads obtemos maior speedup em relação a execução serial:
Speedup 2 threads = 1,01488868
Speedup 3 threads = 1,02090234
Porém, ao executarmos com cada vez mais threads, exemplificado acima nas execuções com 5 e 60 threads, o tempo de execução do programa acaba aumentando.

• Descrição simples do algoritmo e estratégia de paralelismo adotada:
  Primeiramente a linguagem escolhida foi a linguagem C, pois além de ser a linguagem estudada em aula, ela possui a biblioteca GMP, sendo ela a principal bibliteca para o projeto. A biblioteca GMP  é uma biblioteca livre para aritmética de precisão arbitrária, operando com números inteiros, racionais e de ponto flutuante e sua utilização é necessária uma vez que outras bibliotecas mais simples (como a math.h) não conseguem trabalhar com a divisão de grandes números de ponto flutuante, e utilizando a GMP isso é possivel pois nela não há limite prático para a precisão, exceto os implicados pela memória disponível na máquina. O código possui 3 principais funções sendo uma a Main, fatorial e Euler. A função fatorial realizará o calculo fatorial, recebendo um valor int n que é número para o qual o fatorial está sendo calculado e um mpz que armazenará o resultado do fatorial. A função utiliza uma abordagem recursiva para calcular o fatorial onde se n for zero, a função atribui 1 à variável "resultado", caso contrário a função cria uma variável temporária temp, chama recursivamente a função fatorial para calcular (n-1)! e em seguida, multiplica o resultado pelo valor de n. A função Euler calcula a série de Euler de maneira paralela, utilizando a biblioteca openmp. Esta biblioteca nos possibilita realizar o calculo de 1/n! paralelamente, e posteriormente, ao utilizar a diretriz critical podemos realizar o somatório destas divisões de modo que as threads não "apaguem" os calculos realizados por outras threads. A precisão dos resultados é mantida usando a biblioteca GMP. Por fim, main é responsável por inicializar o programa, obter e converter os argumentos da linha de comando, calcular a série de Euler chamando a função Euler, imprimir o resultado e liberar os recursos alocados durante a execução do programa.


  




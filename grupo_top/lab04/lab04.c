
#include <stdio.h>//Biblioteca padrÃ£o do C
#include <stdlib.h>//Biblioteca pra usar exit()
#include <unistd.h>//biblioyeca para usar fork()
#include <sys/types.h>//biblioteca para usar funÃ§Ãµes do fork()
#include <sys/ipc.h>//biblioteca para para criaÃ§Ã£o e gerenciamento de chaves para uso em memÃ³ria compartilhada.
#include <sys/shm.h>// biblioteca que contÃ©m funÃ§Ãµes relacionadas Ã  manipulaÃ§Ã£o de memÃ³ria compartilhada
#include <sys/wait.h>


int main() {
    int shmid;
    key_t key = 1969;  // Chave para a memÃ³ria compartilhada
    int *shared_value;

    // CriaÃ§Ã£o da memÃ³ria compartilhada
    shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);//mascara 0666 convensÃ£o de read e write
    shared_value = (int *)shmat(shmid, NULL, 0);
    if ((intptr_t)shared_value == -1) {
        perror("shmat");// funÃ§Ã£o que imprime uma mensagem de erro correspondente ao Ãºltimo erro encontrado durante uma chamada de sistema.
        exit(1);
    }

    // Inicializa a variÃ¡vel compartilhada com 1
    *shared_value = 1;

    printf("Valor inicial (processo pai): %d\n", *shared_value);

    // CriaÃ§Ã£o do processo filho
    pid_t pid = fork();

    if (pid == 0) {
        printf("Processo filho: Valor antes da operaÃ§Ã£o: %d\n", *shared_value);
        *shared_value += 2;  
        printf("Processo filho: Valor apÃ³s a operaÃ§Ã£o: %d\n", *shared_value);

        // Libera a memÃ³ria compartilhada e encerra o processo filho
        shmdt(shared_value);
        exit(0);
    } else {  // Processo pai
        // Espera pelo processo filho
        wait(NULL);

        printf("Processo pai: Valor antes da operaÃ§Ã£o: %d\n", *shared_value);
        *shared_value *= 4;  
        printf("Processo pai: Valor apÃ³s a operaÃ§Ã£o: %d\n", *shared_value);

        // Libera a memÃ³ria compartilhada
        shmdt(shared_value);

        // Remove a memÃ³ria compartilhada
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}

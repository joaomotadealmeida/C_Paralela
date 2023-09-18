
#include <stdio.h>
#include <sys/types.h>//Biblioteca do fork
#include <unistd.h> //biblioteca para usar as funções pipe
#include <sys/wait.h>//Biblioteca do fork para usar a função wait
int main (){
int fd[2];
int i, num;
int start, end;
printf("Digite o número: ");
scanf("%d", &num);
int id = fork();
if ( id == 0){
  start = num;
  end = num/2;
 } else {
  start = num/2;
  end = 1; }

for( int i = 0; start > end ; start = start -1){
   i = i * start;
}
printf("%d\n", i);
if( id == 0){
  close(fd[0]);
  write(fd[1],&i,sizeof(i));
  close(fd[1]);

 }else {
  int multChild;
  close(fd[1]);
  read(fd[0], &multChild, sizeof(multChild));
  close(fd[0]);

  int final = i * multChild;
  printf("O fatorial de %d é %d", num, final);
  wait(NULL);

 }
  return 0;
 }

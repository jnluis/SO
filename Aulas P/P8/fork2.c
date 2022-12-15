#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0) { 
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }
    if (ret > 0) sleep(1);
    if (ret== 0)
        printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d PAI\n",getpid(), getppid(), ret);
    else
        printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d FILHO\n",getpid(), getppid(), ret);
    return EXIT_SUCCESS;
}
// Podemos distinguir os 2 processos, porque o return do filho dá 0.
// Já o return do pai dá o ID do filho  
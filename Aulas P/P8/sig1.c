#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    unsigned int i;

    printf("PID = %u\n", getpid());
    i = 0;
    while (i <= 10) { 
        printf("\r%08u ", i++);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
// depois de carregar no control+ Z, o processo fica em background, sendo retomado com o comando fg
// Já o comando bg retoma, mas mostra o número do contador a seguir, e depois é que faz a contagem
// o jobs mostra o estado dos processos em background
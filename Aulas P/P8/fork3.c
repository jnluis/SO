#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      //Filho
      case 0:  /* processo filho */
                  //path -> ./child
                  //argv[0] -> ./child
                  //NULL -> Terminator
                  //argc = 0 (o NULL nao conta!!)
               if (execl ("/bin/ls", "./ls","-l",".", NULL) < 0) { 
                  //$./ls -l . -> ./ls = argv[0] ; -l = argv[1] ; . = argv[2]
                   perror ("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }

               printf ("Porque é que eu não apareço?\n");
               //Porque o processo da child e terminado quando o exec terminar!
               break;
      default: /* processo pai */
               sleep(1);
               printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    }
    return EXIT_SUCCESS;
}

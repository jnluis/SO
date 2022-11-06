#include <stdio.h>
#include <stdlib.h>
// Pergunta 3
// Não se pergunta ao utilizador os intervalos de valores, eles são passados logo como argumento aquando da execução do ficheiro

int main(int argc, char *argv[]){
    int minimum_number = atoi(argv[1]); // Não esquecer de converter!!
    int max_number = atoi(argv[2]);
    int counter = 0;
    //int valor_secreto = rand() % (max_number + 1 - minimum_number) + minimum_number; 
    // gera um valor random na gama de valores
    // desejada entre os 2 valores passados como argumento
    int valor_secreto = (rand() % (max_number -minimum_number +1)) + minimum_number ; // usando só rand, o valor é gerado entre o intervalo, mas exlusivamente entre ammbos os limites.
    // Parece que para ser inclusivo, teríamos de fazer com o srand, incluindo a livraria time.h 
    printf("O número secreto é %4d\n",valor_secreto);
    int val; // valor inserido pelo utilizador
    printf("Insira um número dentro do intervalo\n");
    scanf("%d", &val);
    counter++;
    while (val != valor_secreto){
        if (val > valor_secreto)
        {
            printf("O valor que inseriu é mais alto que o valor secreto!\n");
            printf("Insira um novo número\n");
            scanf("%d", &val);
            counter++;
        }
        else if (val < valor_secreto)
        {
            printf("O valor que inseriu é mais baixo que o valor secreto!\n");
            printf("Insira um novo número\n");
            scanf("%d", &val);
            counter++;
        }
    }
    printf("Parabéns, encontrou o número secreto!\n");
    printf("Demorou %d tentativa(s)\n", counter);
    return 0;
}
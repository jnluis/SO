#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int i;
    char str[1000];
    strcpy(str, argv[1]);
    for (i = 2; i < argc; i++) // começa em 2 porque o 0 é o executável, ou seja, ./joinWords, e o 1 é copiado fora do loop para não dar uma cegada
    // inexplicável no print
    {
        strcat(str, " ");
        if(isalpha(argv[i][0]) != 0){ // o isalpha precisa de comparar com um valor 0 ou !=0. Se for !=0, o paramtro é alfabético, e por isso pode ser posto
        // na variável. No argv, juntou-se o segundo argumento [0], porque só não queremos as palavras que não começam por letra (ou seja, ir verificar para [0])
        // Se for passado, por exmemplo, o valor l2, quremos juntá-lo à nossa variável str
            strcat(str, argv[i]);
        }
       
    }
    printf("String num só argumento em que não aparecem números: %s\n", str);
    return EXIT_SUCCESS;
}

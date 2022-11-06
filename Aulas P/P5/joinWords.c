#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    char str[1000];
    strcpy(str, argv[1]);
    for (i = 2; i < argc; i++) // começa em 2 porque o 0 é o executável, ou seja, ./joinWords, e o 1 é copiado fora do loop para não dar uma cegada
    // inexplicável no print
    {
        strcat(str, " ");
        strcat(str, argv[i]);
    }
    printf("String num só argumento: %s\n", str);
    return EXIT_SUCCESS;
}

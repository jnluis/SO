#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    char *endarg;
    float resultado = 0;
    float numero_1;
    float numero_2;

    if (argc == 4)
    {
        numero_1 = strtod(argv[1], &endarg);
        if (endarg == argv[1] || *endarg != '\0') // arg vazio ou não estritamente numérico
        {
            printf("1º operando invalido\n");
            return EXIT_FAILURE;
        }
        numero_2 = strtod(argv[3], &endarg);

        if (endarg == argv[3] || *endarg != '\0')
        {
            printf("2º operando invalido\n");
            return EXIT_FAILURE;
        }
    }
    else return EXIT_FAILURE;

    if (*argv[2] == '+')
    {
        resultado = numero_1 + numero_2;
        printf("O resultado é %0.2f\n", resultado);
        return EXIT_SUCCESS;
    }
    if (*argv[2] == '-')
    {
        resultado = numero_1 - numero_2;
        printf("O resultado é %0.2f\n", resultado);
        return EXIT_SUCCESS;
    }
    if (*argv[2] == 'x')
    {
        resultado = numero_1 * numero_2;
        printf("O resultado é %0.2f\n", resultado);
        return EXIT_SUCCESS;
    }
    if (*argv[2] == '/')
    {
        resultado = numero_1 + numero_2;
        printf("O resultado é %0.2f\n", resultado);
        return EXIT_SUCCESS;
    }
    if (*argv[2] == 'p')
    {
        resultado = pow(numero_1, numero_2);
        printf("O resultado é %0.2f\n", resultado);
        return EXIT_SUCCESS;
    }
    else
    {
        printf("Operador Inválido!\n");
    }
}
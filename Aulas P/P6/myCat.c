#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line[LINEMAXSIZE];

    /* Validate number of arguments */
    if (argc == 1)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0; // global variable indicating the error ocuured during any fucnction
    for (int i = 0; i < argc - 1; i++)
    {
        fp = fopen(argv[i + 1], "r");
        if (fp == NULL)
        {
            perror("Error opening file!");
            return EXIT_FAILURE;
        }

        int j = 1;
        int complete = 1;
        /* Read all the lines of the file */
        int numberLines = 0;
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            if (complete) // nova linha
            {
                printf("%d-> ", j);
                j++;
            }
            printf("%s -> ", line);
            int linesize = strlen(line);
            if (line[linesize - 1 != '\n'])
            {
                complete = 0; // linha incompleta
            }
            else
            {
                complete=1;
            }
        }

        fclose(fp);
    }

    return EXIT_SUCCESS;
}
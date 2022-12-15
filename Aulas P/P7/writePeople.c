#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    int i,pessoas;
    char c;
    int MAXLENNAME = 100;
    Person p = {35, 1.65, "xpto"};

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    printf("Insira o numero de pessoas a considerar\n");
    scanf("%d", &pessoas);
    /* Write 10 itens on a file */
    for(i = 0 ; i < pessoas ; i++)
    {    
        while((c=getchar()) != EOF && c!='\n'); // limpa stdin 
            printf("Pessoa %d\nNome: ", i);
            fgets(p.name,MAXLENNAME+1,stdin);
        if((strlen(p.name) > 0) && (p.name[strlen (p.name) - 1] == '\n'))
                                    p.name[strlen (p.name) - 1] = '\0'; // remove trailing nweline
        printf("Idade: ");
        scanf("%d", &(p.age));

        while((c=getchar()) != EOF && c!='\n'); // limpa stdin 
        printf("Altura: ");
        scanf("%lf", &(p.height));

        
        printf("%d ", i);printPersonInfo(&p);
        fwrite(&p, sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}

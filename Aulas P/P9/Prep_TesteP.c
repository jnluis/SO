#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
    printf("# args: %d\n", argc);
    printf("l1 %s\n", argv[2]);
    printf("l2 %d\n", atoi(argv[3]));
/*
    for (int i = 1; i < argc; i++)
    {
        
        char *ptr;
        long num =strtol(argv[i], &ptr, 10);
        if ( num>= 100){
            printf("%s\n", argv[i]);
        }
       

    } */
int opt;
int min=0;
int max=0;
      
    // put ':' in the starting of the
    // string so that program can 
    //distinguish between '?' and ':' 
    while((opt = getopt(argc, argv, ":n:m:")) != -1) 
    { 
        switch(opt) 
        { 
            case 'n': 
                min=atoi(optarg);
                break;
            case 'm': 
                max=atoi(optarg);
                break;
            case ':': 
                printf("option needs a value\n"); 
                break; 
            case '?': 
                printf("unknown option: %c\n", optopt);
                break; 
        } 
    } 
    
    for (int i = 2; i < argc; i++)
    {
        
        char *ptr;
        long num =strtol(argv[i], &ptr, 10);
        if ( num>= min && num<= max){
            printf("%s\n", argv[i]);
        }
       

    } 
      
    return EXIT_SUCCESS;
}
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char **argv){

    if(argv[1] == NULL){
        printf("Give a file as an argument.");
        exit(0);
    }
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int last_value = 0;
    int increased = 0;
    int current_value = 0;
    int decreased = 0;

    fp = fopen(argv[1], "r");
    while((read = getline(&line, &len, fp)) != -1){
        printf("Retrieved line of length %zu:\n", read);
        printf("%s\n", line);
        current_value = atoi(line);
        if(last_value != 0){
            int sum = current_value - last_value;
            if(sum > 0){
                printf("Increased\n");
                increased += 1;
            }
            else if (sum < 0)
            {
                printf("Decreased\n");
                decreased += 1;
            }
            
        }
        last_value = current_value;
    }

    fclose(fp);
    if(line){
        free(line);
    }

    printf("Increased: %d\n", increased);
    printf("Decreased: %d\n", decreased);

    exit(0);
}
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void part_one(char * input){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int horizontal = 0;
    int depth = 0;
    
    fp = fopen(input, "r");
    while((read = getline(&line, &len, fp)) != -1){
        printf("\nRetrieved line of length %zu:\n", read);
        printf("%s\n", line);

        for(int i = 0; i < read; i++){
            if(line[i] == ' '){
                printf("i: %d\n", i);
                printf("num: %c\n", line[i+1]);
                if(i == 2){

                    int num = line[i+1] - '0';
                    depth -= num;
                }
                else if (i == 4)
                {
                    int num = line[i+1] - '0';
                    depth += num;
                }
                else if (i == 7)
                {
                    int num = line[i+1] - '0';
                    horizontal += num;
                }
                printf("horizontal: %d\n", horizontal);
                printf("Depth: %d\n", depth);
                break;
            }
        }

    }

    fclose(fp);
    if(line){
        free(line);
    }

    printf("\nHorizontal: %d\n", horizontal);
    printf("Depth: %d\n", depth);
    printf("Product: %d\n", (horizontal * depth));
}

void main(int argc, char **argv){

    if(argv[1] == NULL){
        printf("Give a file as an argument.");
        exit(0);
    }

    printf("Part one:\n");
    part_one(argv[1]);

    exit(0);
}
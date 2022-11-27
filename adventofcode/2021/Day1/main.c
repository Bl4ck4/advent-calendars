#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void part_one(char * input){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int last_value = 0;
    int increased = 0;
    int current_value = 0;
    int decreased = 0;

    fp = fopen(input, "r");
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
}

void part_two(char * input){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int second_value = 0;
    int increased = 0;
    int first_value = 0;
    int decreased = 0;
    int third_value = 0;
    int sum1 = 0;
    int sum2 = 0;

    fp = fopen(input, "r");
    while((read = getline(&line, &len, fp)) != -1){
        printf("Retrieved line of length %zu:\n", read);
        printf("%s\n", line);
        first_value = atoi(line);
        if(second_value != 0 && third_value != 0){
            printf("F: %d\nS: %d\nT: %d\n", first_value, second_value, third_value);
            sum1 = first_value + second_value + third_value;
            if(sum2 != 0){
                printf("S1: %d\nS2: %d\n", sum1, sum2);
                if((sum1 - sum2) > 0){
                    printf("Increased\n");
                    increased += 1;
                }
                else if ((sum1 - sum2) < 0){
                    printf("Decreased\n");
                    decreased += 1;
                }
            }
            sum2 = sum1;
        }
        third_value = second_value;
        second_value = first_value;
    }

    fclose(fp);
    if(line){
        free(line);
    }

    printf("Increased: %d\n", increased);
    printf("Decreased: %d\n", decreased);
}

void main(int argc, char **argv){

    if(argv[1] == NULL){
        printf("Give a file as an argument.");
        exit(0);
    }

    printf("Part one:\n");
    part_one(argv[1]);

    printf("\n\nPart two:\n");
    part_two(argv[1]);

    exit(0);
}
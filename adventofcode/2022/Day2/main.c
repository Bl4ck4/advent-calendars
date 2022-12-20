#include <stdio.h>
#include <stdlib.h>

void part_one(char * filename){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int opt1 = 0;
    int opt2 = 0;
    int op1_points = 0;
    int op2_points = 0;

    int lost = 0;
    int draw = 3;
    int win = 6;

    int rock = 1;
    int paper = 2;
    int scissors = 3;

    fp = fopen(filename, "r");
    while((read = getline(&line, &len, fp)) != -1){
        printf("Retrieved line of length %zu:\n", read);
        printf("%s\n", line);

        printf("Op 1: %c\n", line[0]);
        printf("Op 2: %c\n", line[2]);

        if(line[0] == 'A'){
            opt1 = rock;
        }
        else if (line[0] == 'B')
        {
            opt1 = paper;
        }
        else if(line[0] == 'C'){
            opt1 = scissors;
        }

        if(line[2] == 'X'){
            opt2 = rock;
        }
        else if (line[2] == 'Y')
        {
            opt2 = paper;
        }
        else if(line[2] == 'Z'){
            opt2 = scissors;
        }

        if(opt1 == opt2){
            op1_points += opt1 + draw;
            op2_points += opt2 + draw;
        }
        else if((opt1 - opt2) == 1){
            op1_points += opt1 + win;
            op2_points += opt2 + lost;
        }
        else if((opt2 - opt1) == 1){
            op1_points += lost + opt1;
            op2_points += win + opt2;
        }
        else if((opt1 - opt2) == 2){
            op1_points += lost + opt1;
            op2_points += win + opt2;
        }
        else if((opt2 - opt1) == 2){
            op1_points += win + opt1;
            op2_points += lost + opt2;
        }
        else{
            printf("Unknown: op1 %d op2 %d\n", opt1, opt2);
        }
        
        
    }
    fclose(fp);

    printf("\nOp 1: %d\n", op1_points);
    printf("Op2: %d\n", op2_points);
}

void part_two(char * filename){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int opt1 = 0;
    int opt2 = 0;
    int op1_points = 0;
    int op2_points = 0;

    int lost = 0;
    int draw = 3;
    int win = 6;

    int rock = 1;
    int paper = 2;
    int scissors = 3;

    fp = fopen(filename, "r");
    while((read = getline(&line, &len, fp)) != -1){
        printf("Retrieved line of length %zu:\n", read);
        printf("%s\n", line);

        printf("Op 1: %c\n", line[0]);
        printf("Op 2: %c\n", line[2]);

        if(line[0] == 'A'){
            opt1 = rock;
        }
        else if (line[0] == 'B')
        {
            opt1 = paper;
        }
        else if(line[0] == 'C'){
            opt1 = scissors;
        }

        if(line[2] == 'X'){ // lose
            if((3 - opt1) == 2){
                opt2 = scissors;
            }
            else if((3 - opt1) == 1){
                opt2 = rock;
            }
            else if((3 - opt1) == 0){
                opt2 = paper;
            }
        }
        else if (line[2] == 'Y') // draw
        {
            opt2 = opt1;
        }
        else if(line[2] == 'Z'){ // win
            if((3 - opt1) == 2){
                opt2 = paper;
            }
            else if((3 - opt1) == 1){
                opt2 = scissors;
            }
            else if((3 - opt1) == 0){
                opt2 = rock;
            }
        }

        if(opt1 == opt2){
            op1_points += opt1 + draw;
            op2_points += opt2 + draw;
        }
        else if((opt1 - opt2) == 1){
            op1_points += opt1 + win;
            op2_points += opt2 + lost;
        }
        else if((opt2 - opt1) == 1){
            op1_points += lost + opt1;
            op2_points += win + opt2;
        }
        else if((opt1 - opt2) == 2){
            op1_points += lost + opt1;
            op2_points += win + opt2;
        }
        else if((opt2 - opt1) == 2){
            op1_points += win + opt1;
            op2_points += lost + opt2;
        }
        else{
            printf("Unknown: op1 %d op2 %d\n", opt1, opt2);
        }
        opt1 = 0;
        opt2 = 0;
        
        
    }
    fclose(fp);

    printf("\nOp 1: %d\n", op1_points);
    printf("Op2: %d\n", op2_points);
}

int main(int argc, char * argv[]){

    //part_one(argv[1]);
    part_two(argv[1]);

    return 0;
}
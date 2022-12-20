#include <stdio.h>
#include <stdlib.h>

void part_one(char * filename){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int elf = 0;
    int most_calories = 0;

    fp = fopen(filename, "r");
    while((read = getline(&line, &len, fp)) != -1){
        //printf("Retrieved line of length %zu:\n", read);
        //printf("%s\n", line);
        if(read > 1){
            printf("%d\n", atoi(line));
            elf += atoi(line);
        }
        else{
            printf("\n\n");
            printf("Elf: %d", elf);
            printf("\nMost cals: %d\n\n", most_calories);
            if (elf > most_calories){
                most_calories = elf;
            }
            elf = 0;
        }
    }
    printf("\n\n");
    printf("Elf: %d", elf);
    printf("\nMost cals: %d\n", most_calories);
    if (elf > most_calories){
        most_calories = elf;
    }
    fclose(fp);
}

void part_two(char * filename){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int elf = 0;
    int cals1 = 0;
    int cals2 = 0;
    int cals3 = 0;

    fp = fopen(filename, "r");
    while((read = getline(&line, &len, fp)) != -1){
        //printf("Retrieved line of length %zu:\n", read);
        //printf("%s\n", line);
        if(read > 1){
            printf("%d\n", atoi(line));
            elf += atoi(line);
        }
        else{
            printf("\n\n");
            printf("Elf: %d", elf);
            if (elf > cals1){
                cals3 = cals2;
                cals2 = cals1;
                cals1 = elf;
            }
            else if (elf > cals2)
            {
                cals3 = cals2;
                cals2 = elf;
            }
            else if (elf > cals3)
            {
                cals3 = elf;
            }
            elf = 0;
        }
    }
    printf("\n\n");
    printf("Elf: %d", elf);
    if (elf > cals1){
        cals3 = cals2;
        cals2 = cals1;
        cals1 = elf;
    }
    else if(elf > cals2){
        cals3 = cals2;
        cals2 = elf;
    }
    else if(elf > cals3){
        cals3 = elf;
    }

    printf("Top three calories:\n1. %d\n2. %d\n3. %d\n", cals1, cals2, cals3);
    printf("Total: %d\n", cals1 + cals2 + cals3);

    fclose(fp);
}

int main(int argc, char * argv[]){

    part_one(argv[1]);
    part_two(argv[1]);

    return 0;
}
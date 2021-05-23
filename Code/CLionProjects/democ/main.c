#include <stdio.h>

int main() {
    int num = 3;
    int Num;
    //printf("Hello, World!\n");
    FILE *file = fopen("/home/liukanglai/1.txt", "r+");


    while(fscanf(file, "%d", &Num) != -1) {
        printf("%d", Num);
    }

    fclose(file);
    return 0;
}
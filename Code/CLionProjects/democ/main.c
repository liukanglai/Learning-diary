#include <stdio.h>

int main() {
    int num;
    char Num;
    //printf("Hello, World!\n");
    FILE *file = fopen("/home/liukanglai/1.txt", "r");

    while(fscanf(file, "%d", &num) != -1) {
        printf("%c", num);
    }

    fclose(file);
    return 0;
}
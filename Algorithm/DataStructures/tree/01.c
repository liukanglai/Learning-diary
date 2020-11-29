#include<stdio.h>
#include<string.h>

typedef struct Tnode{
    char HuffmanCode[100];
}Tnode;

void function(int a)
{
    a++;
    if(a == 3){
        goto v;
    }
}

int main(void)
{
    int a = 0;
    goto v;
    function(a);
v:;
  printf("%d", a);
    return 0;
}

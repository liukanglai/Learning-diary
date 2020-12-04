#include<stdio.h>

#define Maxsize 100

int Stack[Maxsize];
int Ls1 = 0, Ls2 = 0;

void s1push(int a)
{
    Stack[Ls1++] = a;
}

int s1pop()
{
    return Stack[--Ls1];
}


void s2push(int a)
{
    Stack[Maxsize - (Ls2++)] = a;
}

int s2pop()
{
    return Stack[Maxsize - (--Ls1)];
}

int main(void)
{
    return 0;
}

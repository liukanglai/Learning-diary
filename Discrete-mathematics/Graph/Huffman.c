#include<stdio.h>
#include<stdlib.h>

int n;

int compare(const void* a,const void* b)
{
    return (*(int*)a - *(int*)b);
}

void select(int *a)
{

}

int main(void)
{
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++){
        scanf("%d",a+i);
    }
    qsort(a,n,sizeof(int),compare);
    for(int j = 1;j < n;j++){
        select(a);
        for(int i = 0;i < n;i++){
            if(a[i] < 1000) printf("%d\t",a[i]);
            else printf(" \t");
        }
        printf("\n");
    }
    return 0;
}

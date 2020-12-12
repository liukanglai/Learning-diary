#include<stdio.h>
#define Maxsize 100


int S[Maxsize], P[Maxsize], next[Maxsize];
int lp = 0, ls = 0;


void Findnext()
{
    int i = 0, flag = 1, next1 = 0;

    while(i < lp){
        for(int j = 0; j < i-1; j++){
            for(int k = 0; k <= j; k++){
                if(P[k] != P[i-j+k-1]){
                    flag = 0;
                    break;
                }
            }
            if(flag) next1 = j+1;
            flag = 1;
        }
        next[i] = next1;
        if(!i) next[i] = -1;
        i++;
    }
}

void KMP()
{
    int i = 0, j = 0;
    for(; i < ls; i++){
        while(S[i] != P[j]){
            if(j == -1){
                break;
            }
            j = next[j];
        }
        j++;
        if(j == lp){
            printf("Find P in S!\n");
            return ;
        }
    }
    printf("Can't find P in S!\n");
}

int main(void)
{

    return 0;
}

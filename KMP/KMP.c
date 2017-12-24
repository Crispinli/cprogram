#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef char * String;

// 获取KMP算法的next[j]
void get_next(String T, int *next){
    int i, j;
    i = 1;
    j = 0;
    next[i] = j;
    while(i < T[0]){
        if(j == 0 || T[i] == T[j]){
            ++j;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

// 获取KMP改进算法的nextval[j]
void get_nextval(String T,int *nextval){
    int i, j;
    i = 1;
    j = 0;
    nextval[1] = 0;
    while(i < T[0]){
        if(j == 0 || T[i] == T[j]){
            ++i;
            ++j;
            if(T[i] == T[j]){
                nextval[i] = nextval[j];
            }else{
                nextval[i] = j;
            }
        }else{
            j = nextval[j];
        }
    }
}

// KMP算法
int index_KMP(String S, String T, int pos){
    int i, j;
    i = pos;
    j = 0;
    int next[MAXSIZE];
    get_next(T, next);
    while(i <= S[0] && j <= T[0]){
        if(j == 0 || S[i] == T[j]){
            ++i;
            ++j;
        }else{
            j = next[j];
        }
    }
    if(j > T[0]){
        return i - T[0];
    }else{
        return 0;
    }
}

int main(){
    print("%s", "Hello World!");          
    return 0;
}
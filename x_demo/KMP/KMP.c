#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Maxsize 


void getNext(char *p, int *next);


int KMP(char* t, char* p)
{
    int i = 0;
    int j = 0;
    int *next = (int*)malloc(strlen(p)*sizeof(int));
    getNext(p,next);

    while(i<strlen(t) && j<(int)strlen(p))
    {
        if(j == -1 || t[i] == p[j])
        {
            i++;
            j++;

        }
        else {
            j = next[j];
        }
    }
    free(next);
    if(j == strlen(p))
        return i-j;
    else
        return -1;
}



void getNext(char *p, int *next)
{
    int i = 0;
    int j = -1;
    next[0] = -1;

    while(i<strlen(p))
    {
        if(j == -1 || p[i] == p[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

int main(){
    char * t = "ababac";
    char * p = "bac";
    int i = KMP(t,p);
    printf("%d",i);
    return 0;
}


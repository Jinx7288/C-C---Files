#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
    int a = 100;
    char s[a];
    scanf("%s",s);
    char *delim = " ";
    char *p;
    printf("%s", strtok(s, delim));
    while((p = strtok(NULL, delim)))
    {
        printf("%s ", p);
        printf("\n");
    }
    return 0;
}
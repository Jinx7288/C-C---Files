#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
    char s[100];
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
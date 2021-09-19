#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char StackItem;
typedef int StackItemValue;
typedef struct snode *slink;
typedef struct snode{
    StackItem element[2];
    StackItemValue value;
    slink next;
} StackNode;
typedef struct lstack *Stack;
typedef struct lstack
{
    slink top;
}Lstack;
void StackShow(StackItem x[])
{
    printf("%s", x);
}
slink NewStackNode() {
    return (slink)malloc(sizeof(StackNode));
}
Stack StackInit()
{
    Stack S = (Stack)malloc(sizeof *S);
    S->top = 0;
    return S;
}
int StackEmpty(Stack S) {
    return S->top == 0;
}
// int StackFull(Stack S) {    
// }
StackItemValue StackTop(Stack S) {
    if (StackEmpty(S))
        return 0;
    return S->top->value;
}
void Push(StackItem x[],StackItemValue v,Stack S) {
    slink p = NewStackNode();
    strcpy(p->element, x);
    // p->element = x;
    p->value = v;
    p->next = S->top;
    S->top = p;
}
char *Pop(Stack S) {
    if(StackEmpty(S))
        return 0;
    // printf("%s", x);
    slink p = S->top;
    S->top = p->next;
    // free(p);
    return p->element;
}
void StackFree(Stack S) { free(S); }
int main() {
    char inlstr[220]="";
    char laterstr[220]="";
    Stack sk = StackInit();
    // Push("#",-1, sk);
    gets(inlstr);
    int n = strlen(inlstr);
    for (int i = 0; i < n; i++)
    {
        if (inlstr[i]==' ')
        {
            inlstr[i] = '_';
        }
    }
    // printf("%s", inlstr);
    char *delim = "_";
    char *p;
    char firststr[20]="";
    char temp2[10]="";
    char cache[20] = "";
    p = strtok(inlstr, delim);
    strcpy(firststr,p);
    strcat(firststr, " ");
    strcat(laterstr, firststr);
    // printf("%s\n", firststr);
    while((p = strtok(NULL, delim)))
    {
        strcpy(cache, p);
        // printf("%s\n", p);
        if (strcmp(cache, "+") != 0 && strcmp(cache, "-") != 0 && strcmp(cache, "*") != 0 && strcmp(cache, "/") != 0)
        {
            strcat(cache, " ");
            strcat(laterstr, cache);
        }
        // printf("%s", cache);
        if (strcmp(cache,"+")==0 || strcmp(cache,"-")==0)
        {
            if (!StackEmpty(sk) && StackTop(sk)==2)
            {
                strcpy(temp2, Pop(sk));
                strcat(temp2, " ");
                strcat(laterstr, temp2);
            }
            Push(cache, 1, sk);
        }
        if (strcmp(cache,"*")==0 || strcmp(cache,"/")==0)
        {
            if (!StackEmpty(sk) && StackTop(sk)==2)
            {
                strcpy(temp2, Pop(sk));
                strcat(temp2, " ");
                strcat(laterstr, temp2);
            }
            Push(cache, 2, sk);
        }
    }
    char temp[2];
    while (!StackEmpty(sk))
    {
        char *d = Pop(sk);
        strcpy(temp,d);
        strcat(temp," ");
        // strcat(instr, Pop(sk));
        strcat(laterstr, temp);
    }
    printf("%s", laterstr);
    return 0;
}
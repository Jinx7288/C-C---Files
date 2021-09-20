#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char StackItem;
typedef int StackItemValue;
typedef struct snode *slink;
typedef struct snode{
    StackItem element[7];
    StackItemValue value;
    slink next;
} StackNode;
typedef struct lstack *Stack;
typedef struct lstack
{
    slink top;
}Lstack;
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
    slink p = S->top;
    S->top = p->next;
    return p->value;
}
int dig2str(char *s)
{
    int i, j, n, sum = 0;
    n = strlen(s);
    for ( i = 0,j=10; i < n; i++)
    {
        sum = sum * j + *s - 48;
        s++;
    }
    return sum;
}
void StackFree(Stack S) { free(S); }
char inlstr[240]="";
char laterstr[240]="";
char firststr[20]="";
char *cache;
int main() {
    
    Stack digs = StackInit();
    Stack ops = StackInit();
    gets(inlstr);
    int n = strlen(inlstr);
    for (int i = 0; i < n; i++)
    {
        if (inlstr[i]==' ')
        {
            inlstr[i] = '_';
        }
    }
    char *delim = "_";
    char *p;
    p = strtok(inlstr, delim);
    cache = p;
    Push("num", dig2str(cache), digs);
    while((p = strtok(NULL, delim)))
    {
        
    }
    return 0;
}
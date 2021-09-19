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
void Push(StackItem *x,StackItemValue v,Stack S) {
    slink p = NewStackNode();
    strcpy(p->element, x);
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
    Stack ss = StackInit();
    Push("#", -1, ss);
    char incache[20] = "";
    char laterstr[420] ="";
    char *temp;
    // char temp[20] = "";
    while (scanf("%s",incache))
    {
        // printf("%s\n",incache);
        if (strcmp(incache, "+") != 0 && strcmp(incache, "-") != 0 && strcmp(incache, "*") != 0 && strcmp(incache, "/") != 0)
        {
            strcat(incache, " ");
            strcat(laterstr, incache);
            // printf("%s\n", laterstr);
        }
        // printf("%s", incache);
        if (strcmp(incache,"+")==0 || strcmp(incache,"-")==0)
        {
            // if (!StackEmpty(ss) && StackTop(ss)==2)
            // {
            //     temp = Pop(ss);
            //     strcat(temp, " ");
            //     strcat(laterstr,temp);
            // }
            Push(incache, 1, ss);
        }
        if (strcmp(incache,"*")==0 || strcmp(incache,"/")==0)
        {
            // if (!StackEmpty(ss) && StackTop(ss)==2)
            // {
            //     temp = Pop(ss);
            //     strcat(temp, " ");
            //     strcat(laterstr,temp);
            // }
            // printf("%s", incache);
            Push(incache, 2, ss);
        }
    }
    while (!StackEmpty(ss))
    {
        strcat(laterstr, " ");
        strcat(laterstr, Pop(ss));
    }
    return 0;
}
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
    // char *x = S->top->element;
    slink p = S->top;
    S->top = p->next;
    // printf("%s", p->element);
    // free(p);
    return p->element;
}
void StackFree(Stack S) { free(S); }
int main()
{
    // char inlstr[220]="";
    // char laterstr[220];
    // Stack sk = StackInit();
    // Push("#",-1, sk);
    // gets(inlstr);
    // int n = strlen(inlstr);
    // for (int i = 0; i < n; i++)
    // {
    //     if (inlstr[i]==' ')
    //     {
    //         inlstr[i] = '_';
    //     }
    // }
    // printf("%s", inlstr);
    Stack ss = StackInit();
    char plus[3] = "+";
    Push("+", 1, ss);
    Push("-", 1, ss);
    Push(plus, 2, ss);
    Push("/", 2, ss);
    printf("%s\n", Pop(ss));
    printf("%s\n", Pop(ss));
    printf("%s\n", Pop(ss));
    // printf("%d\n", StackEmpty(ss));
    // printf("%d\n", StackTop(ss));
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char StackItem;
typedef int StackItemValue;
typedef struct snode *slink;
typedef struct snode{
    StackItem element[4];
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
    // p->element = x;
    p->value = v;
    p->next = S->top;
    S->top = p;
}
char *Pop(Stack S) {
    if(StackEmpty(S))
        return 0;
    char *x = S->top->element;
    // printf("%s", x);
    slink p = S->top;
    S->top = p->next;
    free(p);
    return x;
}
void StackFree(Stack S) { free(S); }
int main()
{
    
}


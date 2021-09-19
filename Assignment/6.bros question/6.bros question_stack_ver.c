#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define eq(A,B) (A==B)
typedef int StackItem;
typedef struct snode *slink;
typedef struct snode{
    StackItem element;
    StackItem index;
    slink next;
} StackNode;
typedef struct lstack *Stack;
typedef struct lstack
{
    slink top;
}Lstack;
void StackShow(StackItem x)
{
    printf("%d", x);
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
StackItem StackTop(Stack S) {
    if (StackEmpty(S))
        return 0;
    return S->top->element;
}
void Push(StackItem x,StackItem ind,Stack S) {
    slink p = NewStackNode();
    p->element = x;
    p->index = ind;
    p->next = S->top;
    S->top = p;
}
StackItem Pop(Stack S) {
    if(StackEmpty(S))
        return 0;
    StackItem x = S->top->index;
    slink p = S->top;
    S->top = p->next;
    free(p);
    return x;
}
void StackFree(Stack S) {
    free(S);
}
int ans[601000];
int main()
{
    Stack ss = StackInit();
    int n,temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        if (StackEmpty(ss))
        {
            Push(temp,i,ss);
        } else
        {
            while (StackTop(ss)<temp)
            {
                ans[Pop(ss)] = i;
            }
            Push(temp, i, ss);
        }
    }
    while (!StackEmpty(ss))
    {
        ans[Pop(ss)] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}
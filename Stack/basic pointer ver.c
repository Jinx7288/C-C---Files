#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define eq(A,B) (A==B)
typedef int StackItem;
typedef struct snode *slink;
typedef struct snode{
    StackItem element;
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
void Push(StackItem x,Stack S) {
    slink p = NewStackNode();
    p->element = x;
    p->next = S->top;
    S->top = p;
}
StackItem Pop(Stack S) {
    if(StackEmpty(S))
        return 0;
    StackItem x = S->top->element;
    slink p = S->top;
    S->top = p->next;
    free(p);
    return x;
}
void StackFree(Stack S) {
    free(S);
}
int main() {
    char str[100];
    scanf("%s", str);
    slink ss = StackInit(51);
    int n = strlen(str);
    for (int i = 0; i <= n; i++)
    {
        if (str[i-1]=='(') 
        {
            Push(i, ss);
        } else if (str[i-1]==')')
        {
            if(StackEmpty(ss))
                printf("位置%d 处的右括号不匹配\n", i);
                else
                    printf("%d %d \n", Pop(ss), i);
        }
    }

    while (!StackEmpty(ss))
    {
        printf("位置%d 处的左括号不匹配\n",Pop(ss));
    }
}
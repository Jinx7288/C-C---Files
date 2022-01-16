#include<stdio.h>
#include<stdlib.h>
typedef int StackItem;
typedef StackItem *addr;
typedef struct astack *Stack;
typedef struct astack 
{
    int top,
        maxtop;
    StackItem *data;
}Astack;
Stack StackInit(int size)
{
    Stack S = (Stack)malloc(sizeof *S);
    S->data = (StackItem *)malloc(size * sizeof(StackItem));
    S->maxtop = size;
    S->top = -1;
    return S;
}
int StackEmpty(Stack S) {
    if (S->top<0)
    {
        return 1;
    } else
    {
        return 0;
    }
}
int StackFull(Stack S) {
    if (S->top>= S->maxtop)
    {
        return 1;
    } else
    {
        return 0;
    }
}
StackItem StackTop(Stack S) {
    if (StackEmpty(S))
        return 0;
    return S->data[S->top];
}
void Push(StackItem x,Stack S) {
    if(StackFull(S))
        return;
    S->data[++S->top] = x;
}
StackItem Pop(Stack S) {
    if(StackEmpty(S))
        return 0;
    return S->data[S->top--];
}
void StackFree(Stack S) {
    free(S->data);
    free(S);
}
void AddQ(StackItem item,Stack stk1,Stack stk2)
{   
    if (!StackFull(stk1))
    {
        Push(item, stk1);
    } else
    {
        if (StackEmpty(stk2))
        {
            while (!StackEmpty(stk1))
            {
                Push(Pop(stk1), stk2);
            }
            Push(item, stk1);
        } else
        {
            printf("ERROR:Full\n");
        }
     }
}
StackItem DeleteQ(Stack stk1,Stack stk2)
{   
    if (!StackEmpty(stk2))
    {
        return Pop(stk2);
    } else
    {
        if (!StackEmpty(stk1))
        {
            while (!StackEmpty(stk1))
            {
                Push(Pop(stk1), stk2);
            }
            return Pop(stk2);
        } else
        {
            printf("ERROR:Empty\n");
            return 0;
        }
    }
}
int s1, s2;
Stack stk1;
Stack stk2;
int main()
{
    int intemp;
    char t;
    scanf("%d %d", &s1, &s2);
    if (s2>=s1)
    {
        stk1 = StackInit(s1);
        stk2 = StackInit(s2);
    } else
    {
        stk2 = StackInit(s1);
        stk1 = StackInit(s2);
    }
    while (scanf("%c",&t) && t!='T')
    {
        if (t=='A')
        {
            // scanf("%d\n",&intemp);
            scanf(" %d ", &intemp);
            // printf("%d\n", intemp);
            AddQ(intemp,stk1,stk2);
            // printf("decet a A");
        }
        else if (t=='D')
        {
            // printf("received a D\n");
            printf("%d\n",DeleteQ(stk1,stk2));
            // printf("decet a D");
        }
    }
}
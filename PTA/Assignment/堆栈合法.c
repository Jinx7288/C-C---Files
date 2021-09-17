#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int StackItem;
typedef struct astack *Stack;
typedef struct astack 
{
    int top,
        maxtop;
    StackItem *data;
}Astack;
void StackShow(StackItem x)
{
    printf("%d", x);
}
Stack StackInit(int size)
{
    Stack S = (Stack)malloc(sizeof *S);
    S->data = (StackItem *)malloc(size * sizeof(StackItem));
    S->maxtop = size;
    S->top = -1;
    return S;
}
int StackEmpty(Stack S) {
    return S->top < 0;
}
int StackFull(Stack S) {
    return S->top>= S->maxtop;
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
int main()
{
    int m, size;
    scanf("%d %d", &m, &size);
    Stack ss = StackInit(size-1);
    for (int i = 0; i < m; i++)
    {
        char str[103];
        scanf("%s", str);
        int flag = 1;
        int n = strlen(str);
        // printf("%s", str);
        for (int j = 0; j < n; j++)
        {
            if (str[j]=='S')
            {
                if (StackFull(ss))
                {
                    printf("NO\n");
                    flag = 0;
                    break;
                }
                Push(j, ss);
            } else if(str[j]=='X')
            {
                if (StackEmpty(ss))
                {
                    printf("NO\n");
                    flag = 0;
                    break;
                } else
                {
                    Pop(ss);
                }
            }
        }
        if (StackEmpty(ss) && flag==1)
        {
            printf("YES\n");
        }  else if (!StackEmpty(ss) && flag==1)        
        {
            printf("NO\n");
        }
        while (!StackEmpty(ss))
        {
            Pop(ss);
        }
    }
    return 0;
}
// int main() {
//     int m,size;
//     char now;
//     Stack s1 = StackInit(55);
//     scanf("%d %d", &m, &size);
//     for (int i = 0; i < m; i++)
//     {
//         Stack s1 = StackInit(55);
//         for (int j = 0; j < size; j++)
//         {
//             scanf("%c", &now);
//             if (j == 0 && now == 'X')
//             {
//                 printf("NO\n");
//                 break;
//             }
//             if (now=='S')
//             {
//                 Push(j, s1);
//             } else if (now=='X')
//             {
//                 if (StackEmpty(s1))
//                 {
//                     printf("NO\n");
//                     break;
//                 }
//                 Pop(s1);
//             }
//        }
//     }
//     if (StackEmpty(s1))
//     {
//         printf("YES\n");
//     } else
//     {
//         printf("NO\n");
//     }
// }
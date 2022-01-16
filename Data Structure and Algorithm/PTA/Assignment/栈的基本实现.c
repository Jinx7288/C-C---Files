#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct
{
    ElemType elem[MaxSize];
    int top;                      //栈指针
} SqStack;
void InitStack(SqStack **s)   //初始化栈s
{
    *s=(SqStack *)malloc(sizeof(SqStack));
    (*s)->top=-1;
}
void ClearStack(SqStack *s)   //释放栈s
{
    free(s);
}
int StackLength(SqStack *s)   //求栈s长度
{
    int len=0;
    while(s->top!=-1)
    {
        len++;
        s->top--;
    }
    s->top+=len;
    return len;
}
int StackEmpty(SqStack *s)    //判断栈s是否为空栈
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int Push(SqStack *s,ElemType e)  //进栈元素e
{
    if(s->top==MaxSize-1)    return 0;
    s->top+=1;
    s->elem[s->top]=e;
    return 1;
}
int Pop(SqStack *s,ElemType* e)   //出栈一个元素
{
    if(s->top==-1) return 0;
    else
    {
        s->elem[s->top];
        s->top--;
    }
    return 1;
}
int GetTop(SqStack *s,ElemType *e)   //取栈顶元素
{
    if(s->top==-1)
        return 0;
    else
    {
        *e=s->elem[s->top];
    }
return 1;
}
void DispStack(SqStack *s)         //从栈顶到栈底输出元素
{
    while(s->top!=-1)
    {
        printf("%c\n",Pop(s,s->top));
        s->top--;
    }
}
int main() {

    return 0;
}
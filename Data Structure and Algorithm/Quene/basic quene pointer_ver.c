#include<stdio.h>
#include<stdlib.h>
typedef int QItem;
typedef struct qnode *qlink;
typedef struct qnode {
    QItem element;
    qlink next;
} Qnode;
typedef int Qitem;
typedef Qitem *Qaddr;
void QItemShow(Qitem x) {
    printf("%d", x);  
    // 需更改
}
qlink NewNode()
{
    return (qlink)malloc(sizeof(Qnode));
}
typedef struct lque *Quene;
typedef struct lque{
    // int maxsize;
    QItem *quene;
    qlink front,
        rear;
}Lquene;
// Quene QueneInit(int size)
Quene QueneInit()
{
    Quene Q = (Quene)malloc(sizeof *Q);
    // Q->maxsize = size;
    Q->front =Q->rear= 0;
    return Q;
}
int QueneEmpty(Quene Q)
{
    return Q->front == 0;
}
QItem QueneFirst(Quene Q)
{
    if (QueneEmpty(Q))
    {
        return 0;
    }
    // ! 书上印错了
    // return Q->quene[(Q->front + 1) % Q->maxsize];
    return Q->front->element;
}
QItem QueneLast(Quene Q)
{
    if (QueneEmpty(Q))
    {
        return 0;
    }
    // return Q->quene[Q->rear];
    return Q->rear->element;
}
void EnterQuene(QItem x,Quene Q)
{
    qlink p = NewNode();
    p->element = x;
    p->next = 0;
    if (Q->front)
    {
        Q->rear->next = p;
    } else
    {
        Q->front = p;
    }
    Q->rear = p;
}
QItem DeleteQuene(Quene Q)
{
    if (QueneEmpty(Q))
    {
        return 0;
    }
    QItem x = Q->front->element;
    qlink p = Q->front;
    Q->front = Q->front->next;
    free(p);
    return x;
}
int main()
{
    Quene qq = QueneInit();
    printf("%d\n", QueneEmpty(qq));
    for (int i = 0; i < 10; i++)
    {
        EnterQuene(i, qq);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", DeleteQuene(qq));
    }
    printf("%d\n", QueneEmpty(qq));
    printf("%d\n", QueneFirst(qq));
    printf("%d\n", QueneLast(qq));
    return 0;
}
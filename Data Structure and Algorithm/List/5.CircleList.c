#include<stdio.h>
#include<stdlib.h>
typedef int ListItem;
typedef struct node *link;
typedef struct node {
    ListItem element;
    link next;
} Node;

link NewNode()
{
    return (link)malloc(sizeof(Node));
}
typedef struct clist *List;
typedef struct clist{
    int n;
    link last;
} Llist;
List ListInit()
{
    List L = (List)malloc(sizeof *L);
    link y = NewNode();
    y->next = y;
    L->last = y;
    L->n = 0;
    return L;
}
int ListEmpty(List L)
{
    return L->n == 0;
}
int ListLength(List L)
{
    return L->n;
}
ListItem ListRetrieve(int k,List L)
{
    if (k<1 || k>L->n)
    {
        return 0;
    }
    link p = L->last->next->next;
    int i = 1;
    while (i<k)
    {
        p = p->next;
        i++;
    }
    return p->element;
}
int ListLocate(ListItem x,List L)
{
    int i = 1;
    link p = L->last->next->next;
    while (p->element!=x)
    {
        p = p->next;
        i++;
    }
    return( (p==L->last->next) ? i : 0);
}
void ListInsert(int k,ListItem x,List L)
{
    if (k<0 || k>L->n) return;
    link p = L->last->next;
    for (int i = 0; i < k && p; i++)
    {
        p = p->next;
    }
    link y = NewNode();
    y->element = x;
    y->next = p->next;
    p->next = y;
    if(k==L->n)    L->last = y;
    L->n++;
}
ListItem ListDelete(int k,List L)
{
    if (k<1 || k>L->n) 
    {
        return 0;
    }
    link q = L->last->next;
    for (int i = 1; i < k - 1;i++) q = q->next;
    link p = q->next;
    q->next = p->next;
    if (k==L->n)
    {
        L->last = q;
    }
    ListItem x = p->element;
    free(p);
    L->n--;
    return x;
}
void ItemShow(ListItem x)
{
    printf("%d \n", x);
}
void PrintList(List L)
{
    for (link p=L->last->next->next; p!=L->last->next; p=p->next)
    {
        ItemShow(p->element);
    }
}
int main()
{
    List p1 = ListInit();
    printf("%d \t", ListEmpty(p1));
    printf("%d \t", ListLength(p1));
    for (int i = 0; i < 10; i++)
    {
        ListInsert(0, i, p1);
    }
    printf("%d \t", ListEmpty(p1));
    printf("%d \t", ListLength(p1));
    
    printf("%d \t", ListLocate(3, p1));
    printf("%d \n", ListRetrieve(4, p1));

    PrintList(p1);
    ListDelete(4, p1);
    PrintList(p1);
    return 0;
}
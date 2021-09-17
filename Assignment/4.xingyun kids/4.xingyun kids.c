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
int ListLength(List L)
{
    return L->n;
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
    // List p1 = ListInit();
    int n;
    scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     ListInsert(i, i, p1);
    // }
    
    // if (ListLength(p1)%2==0)
    // {
    //     printf("%d", ListLength(p1) / 2);
    // } else
    // {
    //     printf("%d", ListLength(p1));
    // }
    if (n%2==0)
    {
        printf("%d", n / 2);
    } else
    {
        printf("%d", n);
    }
    
    
        
   return 0;
}
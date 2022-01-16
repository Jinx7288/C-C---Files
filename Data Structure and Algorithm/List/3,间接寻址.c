#include<stdio.h>
#include<stdlib.h>
typedef int ListItem;
typedef ListItem *addr;
typedef struct node {
    ListItem element;
    addr next;
} Node;

addr NewNode()
{
    return (addr)malloc(sizeof(Node));
}
typedef struct indlist *List;
typedef struct indlist{
    int n,
        curr;
    int maxsize;
    addr *table;
} Llist;
List ListInit(int size)
{
    List L = (List)malloc(sizeof *L);
    L->n = 0;
    L->maxsize = size;
    L->table = (addr *)malloc(size * sizeof(addr));
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
    return *L->table[k-1];
}
int ListLocate(ListItem x,List L)
{
    for (int i = 0; i < L->n; i++)
    {
        if (*L->table[i]==x)
        {
            return ++i;
        }
    }
    return 0;
}
void ListInsert(int k,ListItem x,List L)
{
    if (k<0 || k>L->n)
        return;
    for(int i = L->n-1; i>=k; i--)
    {
        L->table[i + 1] = L->table[i];
    }
    L->table[k] = NewNode();
    *L->table[k] = x;
    L->n++;
}
ListItem ListDelete(int k,List L)
{
    if (k<1 || !L->n) 
    {
        return 0;
    }
    addr p = L->table[k-1];
    ListItem x = *p;
    for (int i = k; i < L->n; i++)
    {
        L->table[i - 1] = L->table[i];
    }
    L->n--;
    free(p);
    return x;
}
void ItemShow(ListItem x)
{
    printf("%d \n", x);
}
void PrintList(List L)
{
    for (int i = 0; i < L->n; i++)
    {
        ItemShow(*L->table[i]);
    }
}
int main()
{
    List p1 = ListInit(20);
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
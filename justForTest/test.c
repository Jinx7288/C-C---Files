#include <stdio.h>
#include <stdlib.h>
typedef struct li

{
    int data;
    struct li *next;
} L;
int main()
{
    int i, M;
    L *header, *p1, *p2;
    while (~scanf("%d", &M))
    {
        for (i = 1; i <= M; i++) //循环写入链表
        {
            p2 = (L *)malloc(sizeof(L));
            p2->data = i;
            p2->next = NULL;
            if (i == 1)
                header = p1 = p2;
            else
            {
                p1->next = p2;
                p1 = p2;
            }
        }
        p1->next = header;
        while (M > 2)
        {
            p1 = p1->next;
            p2 = p1->next;
            if (p2->data != 1)
            {
                printf("%d ", p2->data);
                p1->next = p2->next;
                free(p2);
                M--;
            }
        }
        printf("\n");
        p2 = p1->next;
        if (p1->data > p2->data)
            printf("%d %d\n", p2->data, p1->data);
        else
            printf("%d %d\n", p1->data, p2->data);
        free(p1);
        free(p2);
    }
    return 0;
}
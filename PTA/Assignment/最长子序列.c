#include<stdio.h>
typedef struct Node
{
    int ele[100000];
    int size;
} Node,*List;

void process(List L)
{
      int left, right, maxlen, l, r, len;
        int i;
        if(L->size==0)
            return;
        else{
            left=right=0;
            maxlen = 1;
        }
        l=r=0;
        len = 1;
        for(i=1; i<L->size; i++){
            if(L->ele[i]>L->ele[i-1]){
                r++;
                len++;
            }
            else{ 
                if(len>maxlen){
                    left = l;
                    right = r;
                    maxlen = len;
                }
                l=r=i;
                len = 1;
            }
        }
        if(len>maxlen){
            left = l;
            right = r;
            maxlen = len;
        }
    
        for(i=left; i<=right; i++){
            if(i==left)
                printf("%d", L->ele[i]);
            else
                printf(" %d", L->ele[i]);
        }
}
int main()
{
    int n;
    Node node;
    List L = &node;
    scanf("%d", &n);
    L->size = n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &L->ele[i]);
    }
    process(L);
}

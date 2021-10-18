#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct node {
    int left;
    int right;
} Node;
Node ns[100100];
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &ns[i].left, &ns[i].right);
    }
    
}
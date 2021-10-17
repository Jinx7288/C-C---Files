#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
int m, n;
typedef struct score
{
    int index;
    int data[110];
    bool operator==(const score &b)const{
        for (int i = 0; i < n; i++)
        {
            if(data[i]!=b.data[i])
                return false;
        }
        return true;
    }
}Score;
bool cmp(Score a,Score b) 
{
    for (int i = 0; i < n; i++)
    {   
        if (a.data[i]==b.data[i])
        {
            i++;
        } else
        {
            return a.data[i] > b.data[i];
        }   
    }
    return true;
}
Score sce[10010];
int ans[10001]={0};
int main()
{
    char temp;
    scanf("%d %d", &m, &n);
    // printf("%d %d", m, n);
    scanf("%c", &temp);
    for (int i = 0; i < m; i++)
    {
        sce[i].index = i;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &sce[i].data[j]);
        }
        scanf("%c",&temp);
    }
    sort(sce, sce + m, cmp);
    // ! 未完成
    int k; 
    for (int i = 0; i < m; i++)
    {
        printf("%d ", ans[sce[i].index]);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", sce[i].data[j]);
        }
        printf("\n");
    }
}
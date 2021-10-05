#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct score
{
    int de;
    int cai;
    int xuehao;
    short type;
};
struct score sce[100010];
bool cmp(struct score a,struct score b) {    
    if (a.type!=b.type)
    {
        return a.type < b.type;
    } else
    {
        if (a.de + a.cai == b.de + b.cai)
        {
            if (a.de!=b.de)
            {
                return a.de > b.de;
            } else
            {
                return a.xuehao < b.xuehao;
            }
        } else
        {
            return a.de + a.cai > b.de + b.cai;
        }
        if (a.de==b.de && a.cai == b.cai)
        {
            return a.xuehao > b.xuehao;
        }
        return a.de + a.cai > b.de + b.cai;    
    }
}
int main()
{
    int n,k, jigexian, youxian;
    k = 0;
    int temp1, temp2, temp3;
    // Score* link = score;
    scanf("%d %d %d", &n, &jigexian, &youxian);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &temp1, &temp2, &temp3);
        if (temp2>=jigexian && temp3>=jigexian)
        {
            sce[k].xuehao = temp1;
            sce[k].de = temp2;
            sce[k].cai = temp3;
            if (temp2>=youxian)
            {
                if (temp3>=youxian)
                {
                    sce[k].type = 1;
                } else
                {
                    sce[k].type = 2;
                }
            } else
            {
                if (temp3<youxian && temp2>=temp3)
                {
                    sce[k].type = 3;
                } else
                {
                    sce[k].type = 4;
                }
            }
            k++;
        }
    }
    sort(sce, sce+k, cmp);
    printf("%d\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d %d %d\n", sce[i].xuehao, sce[i].de, sce[i].cai);
    }
    return 0;
}
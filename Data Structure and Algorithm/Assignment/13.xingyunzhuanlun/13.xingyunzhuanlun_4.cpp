#include<bits/stdc++.h>
using namespace std;
int td[4][1020];
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
    int n;
    int ans = 0;
    scanf("%d", &n);
    map<int, int> map1;
    map<int, int> map2;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // scanf("%d", &td[i][j]);
            td[i][j] = read();
        }
    }
    for (int i = n-1; i >=0; i--)
    {
        for (int j = n-1; j>=0 ; j--)
        {
            int da, bc;
            da = td[3][i] - td[0][j];
            bc = td[2][i] * td[1][j];
            // printf("%d %d\n", da, bc);
            if(!map1.count(da))
            {
                map1[da] = 1;
            } else {
                map1[da]++;
            }
            if(!map2.count(bc))
            {
                map2[bc] = 1;
            } else {
                map2[bc]++;
            }
        }
    }
    map<int, int>::iterator iter;
    // for ( iter = map1.begin(); iter != map1.end(); iter++)
    // {
    //     cout << iter->first << " " << iter->second << endl;
    // }
    // for ( iter = map2.begin(); iter != map2.end(); iter++)
    // {
    //     cout << iter->first << " " << iter->second << endl;
    // }
    for ( iter = map1.begin(); iter != map1.end(); iter++)
    {
        if (map2[iter->first])
        {
            int c = iter->second * map2[iter->first];
            ans += iter->second * map2[iter->first];
        }
    }
    printf("%d\n", ans);
}
#include<bits/stdc++.h>
using namespace std;
vector<int> store;
vector<int> sale;
typedef struct ele{
    int storev;
    int salev;
    float rate;
} Ele;
vector<Ele> rates;
bool cmp(Ele a,Ele b) {
    return a.rate > b.rate;
}
int main()
{
    int m, n,temp;
    
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        store.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        sale.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        Ele t;
        t.salev = sale[i];
        t.storev = store[i];
        t.rate = (float)(sale[i]) / (float)store[i];
        rates.push_back(t);
    }
    sort(rates.begin(), rates.end(),cmp);
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%.2f\n", rates[i].rate);
    // }
    int ca = 0;
    float ans = 0.0;
    int j;
    for (j = 0; j < m; j++)
    {
        if (ca+rates[j].storev<n)
        {
            ans += (float)rates[j].salev;
            ca += rates[j].storev;
        } else
        {
            break;
        }
    }
    ans = ans + (float)rates[j].rate * (n - ca);
    printf("%.2f", ans);
}
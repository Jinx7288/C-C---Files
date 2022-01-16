#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int heap[10001], n = 0, num, m;
void upAdjust(int low, int high)
{
    int i = high, j = i / 2;
    while (j >= low)
    {
        if (heap[j] > heap[i]) ///注意只有这个地方与大顶堆的upAdjust函数不一样，函数的其他部分一模一样
        {
            swap(heap[j], heap[i]);
            i = j;
            j = i / 2;
        }
        else
            break;
    }
}
void insert(int x)
{
    heap[++n] = x;
    upAdjust(1, n);
}
int main()
{
    int e, a, b;
    cin >> num >> m;
    for (int i = 0; i < num; i++)
    {
        cin >> e;
        insert(e);
    }
    map<int, int> Map;
    for (int i = 1; i <= num; i++)
        Map[heap[i]] = i;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> a >> str;
        if (str == "and")
        {
            cin >> b >> str >> str;
            int f = 0;
            for (int i = 1; i <= n; i++)
                if (2 * i <= n && 2 * i + 1 <= n && (heap[2 * i] == a && heap[2 * i + 1] == b || heap[2 * i] == b && heap[2 * i + 1] == a))
                    f = 1;
            if (f == 1)
                cout << "T" << endl;
            else
                cout << "F" << endl;
            continue;
        }
        cin >> str;
        if (str == "a")
        {
            cin >> str >> str >> b;
            if (Map[b] == Map[a] / 2)
                cout << "T" << endl;
            else
                cout << "F" << endl;
            continue;
        }
        cin >> str;
        if (str == "root")
        {
            if (heap[1] == a)
                cout << "T" << endl;
            else
                cout << "F" << endl;
            continue;
        }
        cin >> str >> b;
        if (Map[a] == Map[b] / 2)
            cout << "T" << endl;
        else
            cout << "F" << endl;
    }
    return 0;
}
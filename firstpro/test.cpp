#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct arr
{
    int num;
    int de, cai, sum;
    int clas;
} stu[1001];
bool cmp(struct arr a,struct arr b)
{
    if (a.clas != b.clas)
        return a.clas < b.clas;
    else if (a.num != b.num)
        return a.num > b.num;
    else if (a.de != b.de)
        return a.de > b.de;
    else
        return a.num < b.num;
}
int main()
{
    int N, L, H;
    scanf("%d %d %d\n", &N, &L, &H);
    int temp = N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d\n", &stu[i].num, &stu[i].de, &stu[i].cai);
        stu[i].sum = stu[i].de + stu[i].de;
        if (stu[i].de < L || stu[i].cai < L)
        {
            stu[i].clas = 5;
            temp--;
        }
        else if (stu[i].de >= H && stu[i].cai >= H)
        {
            stu[i].clas = 1;
        }
        else if (stu[i].de >= H && stu[i].cai < H)
        {
            stu[i].clas = 2;
        }
        else if (stu[i].de < H && stu[i].cai < H && stu[i].de > stu[i].cai)
        {
            stu[i].clas = 3;
        }
        else
        {
            stu[i].clas = 4;
        }
    }
    sort(stu, stu + N, cmp);
    printf("%d\n", temp);
    for (int i = 0; i < temp; i++)
    {
        printf("%d   %d   %d\n", stu[i].num, stu[i].de, stu[i].cai);
    }
    return 0;
}

//#define CRT_SECURE_NO_WARNING
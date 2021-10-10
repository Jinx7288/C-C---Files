#include<cstdio>
#include<algorithm>
using namespace std;
int cot[1000010];
typedef struct point {
    int number;
    int no;
} Point;
Point leftgo(Point pit)
{
    int c = pit.number;
    if (pit.no!=1)
    {
        pit.no -= 1;
    } else
    {
        while (true)
        {
            if (cot[c-1]!=0)
            {
                pit.number = c - 1;
                break;
            } else
            {
                c += 1;
            }
        }
        pit.no = cot[pit.number];
    }
    return pit;
}
Point rightgo(Point pit)
{
    int c = pit.number;
    if (pit.no!=cot[pit.number])
    {
        pit.no += 1;
    } else
    {
        while (true)
        {
            if (cot[c+1]!=0)
            {
                pit.number = c +1;
                break;
            } else
            {
                c -= 1;
            }
        }
        pit.no = cot[pit.number];
    }
    return pit;
}
int main()
{
    Point left,right;
    int n, d, temp, sum,mid,odd,tempsum,cache;
    sum = 0;
    tempsum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cot[i]);
        sum += cot[i];
    }
    odd = sum % 2 == 0 ? 0 : 1;
    mid = sum % 2 == 0 ? sum / 2 : (sum + 1) / 2 ;
    for (int i = 1; i <= n; i++)
    {
        if (tempsum+cot[i]>=mid)
        {
            if(odd) {
                left.number = i;
                right.number = i;
                left.no = mid - tempsum;
                right.no = mid - tempsum;
            } else
            {
                left.number = i;
                left.no = mid - tempsum;
                if (left.no==cot[i])
                {
                    right.no = 1;
                    cache = i;
                    while (true)
                    {
                        if (cot[cache+1]!=0)
                        {
                            right.number = cache+1;
                            break;
                        } else
                        {
                            cache += 1;
                        }
                    }
                } else
                {
                    right.number = i;
                    right.no = mid - tempsum + 1;
                }
            }
            break;
        }
        tempsum += cot[i];
    }
    // printf("%d %d", left.number, left.no);
    // printf("%d %d", right.number, right.no);
    scanf("%d", &d);
    for (int j = 0; j < d; j++)
    {
        scanf("%d", &temp);
        while (true)
        {
            if (cot[n-temp]!=0)
            {
                if (odd)
                {
                    cot[n - temp] -= 1;
                    if (n-temp==left.number)
                    {
                        left = leftgo(left);
                        right = rightgo(right);
                    }
                    if(n-temp>left.number) 
                        left = leftgo(left);
                    if(n-temp<left.number)
                        right = rightgo(right);
                } else
                {
                    cot[n - temp] -= 1;
                    if (n-temp==left.number)
                    {
                        left = leftgo(left);
                        right = rightgo(right);
                    }
                    if(n-temp<left.number) 
                        left = rightgo(left);
                    if(n-temp>right.number)
                        right = leftgo(right);
                }
                odd = odd == 1 ? 0 : 1;
                break;
            } else
            {
                temp += 1;
            }
        }
        if (odd)
        {
            printf("%.1f", (float)left.number);
        } else
        {
            printf("%.1f", ((float)left.number + (float)right.number) / 2.0);
        }
    }   
}
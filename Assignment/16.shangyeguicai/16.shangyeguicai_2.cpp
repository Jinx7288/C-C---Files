#include<iostream>
#include<algorithm>

using namespace std;

int n1[10005],n2[10005];

int main()
{
    int n;
    long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>n1[i];
    sort(n1,n1+n);
    for(int i=n-1;i>=0;i--)
        n2[n-1-i]=n1[i];
    for(int i=0;n1[i]<n2[i];i++)
        sum+=n2[i]-n1[i];
    cout<<sum<<endl;
    return 0;
}
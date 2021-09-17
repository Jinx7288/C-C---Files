#include<stdio.h>
int l[1000010];
int main()
{
	int a,b;
	int temp=0;
	int ans=0;
	scanf("%d %d",&a,&b);
	for(int i=0;i<a;i++)
	{
		scanf("%d",&l[i]);
	}
	for (int i = 0; i < b; i++)
	{
		temp += l[i];
	}
	ans = temp;
	for(int i=0;i<a-b;i++)
	{
		temp += l[b + i]*b;
		temp -= l[i];
		for (int j = 0; j < b-1; j++)
		{
			temp -= l[i + j + 1];
		}
		if (temp>ans)
		{
			ans = temp;
		}
	}
	printf("%d",ans);
    return 0;
}
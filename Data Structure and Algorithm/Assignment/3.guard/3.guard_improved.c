#include<stdio.h>
int l[1000010];
int main()
{
	int a,b;
	int anstemp = 0;
	int ans=0;
	scanf("%d %d",&a,&b);
	for(int i=0;i<b;i++)
	{
		scanf("%d",&l[i]);
		ans += l[i] * (i + 1);;
		anstemp += l[i] * (i + 1);;
	}
	for(int i=0;i<a-b;i++)
	{
		scanf("%d",&l[b+i+1]);
		anstemp += l[b+i] * b;
		anstemp -= l[i];
		for (int j = 0; j < b-1; j++)
		{
			anstemp -= l[i + j + 1];
		}
		if(anstemp>ans)
		{
			ans=anstemp;
		}
	}
	printf("%d",ans);
    return 0;
}
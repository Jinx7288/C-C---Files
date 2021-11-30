#include<bits/stdc++.h>
using namespace std;
#define int long long
map<pair<int,int>,int> Map1;
map<int,int> a;
map<int,int> b;
signed main()
{
	int q,n,i,sum,e,x,y;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++){
			scanf("%d %d",&x,&y);
			Map1[make_pair(x,y)]++;

            sum += a[x];
            a[x]++;
            sum+=b[y];
            b[y]++;
        }
		map<pair<int,int>,int>::iterator it;
		for(it=Map1.begin();it!=Map1.end();it++){
			if(it->second>1){
				e=(it->second)*(it->second -1)/2;
				sum-=e;
			}
		}
		Map1.clear();
		a.clear();
		b.clear();
		printf("%lld\n",sum);
	}
	return 0;
}
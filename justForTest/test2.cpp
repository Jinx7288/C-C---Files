#include<iostream>
#include<algorithm>
#include<set>
#include<functional>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<stack>
#include<array>
#include<map>
using namespace std;
const int maxn = 1e4 + 5;
int n, m;
struct node {
	vector<int> fun;
	bool operator==(const node &a)const {
		for (int i = 0; i < a.fun.size(); i++) {
			if (fun[i] != a.fun[i]) return false;
		}
		return true;
	}
	bool operator<(const node &a)const {
		for (int i = 0; i < a.fun.size(); i++) {
			if (fun[i] == a.fun[i]) continue;
			return (fun[i] < a.fun[i]);
		}
		return false;
	}
	bool operator>(const node &a)const {
		for (int i = 0; i < a.fun.size(); i++) {
			if (fun[i] == a.fun[i]) continue;
			return (fun[i] > a.fun[i]);
		}
		return false;
	}
};//我tm直接重载>、<、==。
struct ANS {
	int num;
	node a;
	bool operator<(const ANS &b)const {
		if (num != b.num) return num > b.num;
		else if (!(a == b.a)) return a < b.a;
		return false;
	}
}ans[maxn];
multiset<node> st;//不去重
int co = 0;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		node mynode;
		for (int j = 0; j < m; j++) {	
			cin >> num;
			mynode.fun.push_back(num);
		}
		st.insert(mynode);
	}
	ans[co] = { 0,*st.begin() };
	for (auto it : st) {
		if (it == ans[co].a) ans[co].num++;
		else  ans[++co] = { 1,it };
	}
	printf("%d\n", ++co);
	sort(ans, ans + co);
	for (int i = 0; i < co; i++) {
		
        printf("%d ",ans[i]. num);
		int sz = ans[i].a.fun.size();
		for (int j = 0; j < sz; j++) {
printf("%d", ans[i].a.fun[j]);
if (j < sz - 1) printf(" ");
		}
		putchar(10);
	}
	return 0;
}
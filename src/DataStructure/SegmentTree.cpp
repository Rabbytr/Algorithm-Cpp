#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC diagnostic error "-std=c++11"
//#pragma comment(linker, "/STACK:102400000,102400000")
#define REP(i, a, b) for(int i = a; i < b; ++i)
#define debug(o_o) { cerr << #o_o << '=' << o_o << "\n"; }
#define Arr(a, l, r) { cerr << #a << " = {"; REP(_, l, r) cerr << ' ' << a[_]; cerr << " }\n"; }
#define mset(a,b) memset(a,b,sizeof(a))
#define mkpr make_pair
#define ll long long
#define print(x) cout<<x<<"\n"

using namespace std;

// 单点修改，区间查询线段树

const int N = 1e5;  // limit for array size
int n;  // array size
int tree[2 * N];

inline void maintain(int x) {
    tree[x] = tree[x<<1] + tree[x<<1|1];
}
void build(){  // build the tree
	for (int i=n-1;i;--i)maintain(i);
}
void modify(int p, int value) {  // set value at position p
	for (tree[p+=n]=value;p>1;p>>=1)maintain(p>>1);
}
int query(int l,int r) {  // sum on interval [l, r)
	int res = 0;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1) {
		if (l&1) res += tree[l++];
		if (r&1) res += tree[--r];
	}
	return res;
}

int main() {
	cin>>n;
	REP(i,0,n)cin>>*(tree+n+i);
	build();
    modify(1, 100);
	print(query(1, 3)); // query [1,3)
	Arr(tree,0,2*n);
	return 0;
}
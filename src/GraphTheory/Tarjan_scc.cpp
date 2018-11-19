#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC diagnostic error "-std=c++11"
//#pragma comment(linker, "/STACK:102400000,102400000")
#define REP(i, a, b) for(int i = a; i < b; ++i)
#define debug(x) { cerr << #x << '=' << x << "\n"; }
#define Arr(a, l, r) { cerr << #a << " = {"; REP(_, l, r) cerr << ' ' << a[_]; cerr << " }\n"; }
#define mset(a,b) memset(a,b,sizeof(a))
#define mkpr make_pair
#define ll long long

using namespace std;

const int maxn = 100;
int n,pre[maxn],low[maxn],scc[maxn],cur,scccnt;
struct Edge{int fro,to;};
vector<Edge> edges;
vector<int> G[maxn];
stack<int> S;

void addEdge_(int fro,int to){ //有向图
  edges.push_back((Edge){fro,to});
  int m = edges.size();
  G[fro].push_back(m-1);
}

void dfs(int u){  //Tarjan算法,注意是否连通
  pre[u] = low[u] = ++cur;
  S.push(u);
  REP(i,0,G[u].size()){
    Edge e = edges[G[u][i]];
    if(!pre[e.to]){
      dfs(e.to);
      low[u] = min(low[u],low[e.to]);
    }else if(!scc[e.to]){
      low[u] = min(low[u],pre[e.to]);
    }
  }
  if(low[u]==pre[u]){
    scccnt++;
    for(;;){
      int x = S.top();S.pop();
      scc[x] = scccnt;
      if(x==u)break;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  n = 7;
  addEdge_(1,2);
  addEdge_(2,3);
  addEdge_(3,4);
  addEdge_(4,2);
  addEdge_(3,5);

  cur = scccnt = 0;
  REP(i,1,n+1)if(!pre[i])dfs(i);

  REP(i,1,n+1)cout<<scc[i]<<" ";
  return 0;
}

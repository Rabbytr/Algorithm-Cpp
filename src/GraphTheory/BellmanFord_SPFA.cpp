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
const int INF = 1<<30;

struct Edge{int fro,to,w;};
vector<Edge> edges;
vector<int> G[maxn];
int n,u,d[maxn],p[maxn],cnt[maxn];
bool inq[maxn];
queue<int> Q;

void addEdge_(int fro,int to,int w){ //有向图
  edges.push_back((Edge){fro,to,w});
  int m = edges.size();
  G[fro].push_back(m-1);
}

bool BellmanFord(int s){
  REP(i,1,n+1)d[i]=INF;
  d[s] = 0;inq[s] = true;Q.push(s);
  while(!Q.empty()){
    u = Q.front();Q.pop();debug(u);
    inq[u] = false;
    REP(i,0,G[u].size()){
      Edge e = edges[G[u][i]];
      if(d[u]+e.w<d[e.to]){
        d[e.to] = d[u] + e.w;
        p[e.to] = G[u][i];
        if(!inq[e.to]){
          inq[e.to] = true;
          Q.push(e.to);
          if(++cnt[e.to]>n)return false;
        }
      }
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  n = 4;
  addEdge_(1,2,9);
  addEdge_(1,3,2);
  addEdge_(2,4,-7);
  addEdge_(3,4,3);

  cout<<BellmanFord(1)<<endl;
  REP(i,1,n+1)cout<<d[i]<<" ";
  return 0;
}

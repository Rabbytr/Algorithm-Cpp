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

struct Node{
  int d,u;
  bool operator < (const Node& rhs) const{
    return rhs.d<d;
  }
};
struct Edge{int fro,to,w;};
vector<Edge> edges;
vector<int> G[maxn];
priority_queue<Node> Q;
int n,u,d[maxn],p[maxn];
bool vis[maxn];

void addEdge(int fro,int to,int w){ //无向图
  edges.push_back((Edge){fro,to,w});
  edges.push_back((Edge){to,fro,w});
  int m = edges.size();
  G[fro].push_back(m-2);
  G[to].push_back(m-1);
}

void Dijkstra(int s){
  REP(i,1,n+1){d[i] = INF;p[i] = i;}
  Q.push((Node){0,s});
  d[s] = 0;
  while(!Q.empty()){
    Node x = Q.top();Q.pop();
    u = x.u;
    if(vis[u])continue;
    vis[u] = true;
    REP(i,0,G[u].size()){
      Edge e = edges[G[u][i]];
      if(e.w+d[u]<d[e.to]){
        d[e.to] = d[u] + e.w;
        p[e.to] = G[u][i]; // u
        Q.push((Node){d[e.to],e.to});
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  n = 4;
  addEdge(1,2,2);
  addEdge(1,3,4);
  addEdge(2,3,1);
  addEdge(2,4,6);
  addEdge(3,4,1);
  Dijkstra(1);
  REP(i,1,n+1)cout<<d[i]<<" ";
  return 0;
}

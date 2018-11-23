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
struct Edge{int fro,to,w;};
vector<Edge> edges;
vector<int> G[maxn];
int n,ans,p[maxn];

void addEdge(int fro,int to,int w){ //无向图
  edges.push_back((Edge){fro,to,w});
  edges.push_back((Edge){to,fro,w});
  int m = edges.size();
  G[fro].push_back(m-2);
  G[to].push_back(m-1);
}

int find(int x){return !p[x]?x:p[x]=find(p[x]);}

int Kruskal(){
  sort(edges.begin(),edges.end(),[](Edge i,Edge j){return i.w<j.w;});
  REP(i,0,edges.size()){
    int x = find(edges[i].fro);int y = find(edges[i].to);
    if(x!=y){
      ans += edges[i].w;
      p[y] = x;
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  n = 6;
  addEdge(1,2,6);
  addEdge(1,4,5);
  addEdge(1,3,1);
  addEdge(2,3,5);
  addEdge(3,4,5);
  addEdge(2,5,3);
  addEdge(3,5,6);
  addEdge(3,6,4);
  addEdge(4,6,2);
  addEdge(5,6,6);

  cout<<Kruskal()<<"\n";
  Arr(p,1,n+1);
  return 0;
}

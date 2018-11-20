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

int n,win;
int Map[3][3] = {  // 局势
  {0,2,0},
  {0,1,0},
  {0,0,0}
};

int countzero(){
  int count = 0;
  REP(i,0,3)REP(j,0,3)if(Map[i][j]==0)count++;
  return count;
}

int whoWin(){ // 检查是否已经赢
  REP(i,0,3){
    if((Map[i][0]==Map[i][1])&&(Map[i][1]==Map[i][2])&&Map[i][1]>0)return Map[i][0];
    if((Map[0][i]==Map[1][i])&&(Map[1][i]==Map[2][i])&&Map[1][i]>0)return Map[0][i];
  }
  if((Map[0][0]==Map[1][1])&&(Map[1][1]==Map[2][2])&&Map[1][1]>0)return Map[1][1];
  if((Map[2][0]==Map[1][1])&&(Map[1][1]==Map[0][2])&&Map[1][1]>0)return Map[1][1];
  return 0; // 无人赢
}

int dfs(int player,int cur,int alpha,int beta){
  win = whoWin();
  if(win==1)return cur; // 考虑输入棋局是否规范 if(win==1&&3-player==1)
  if(win==2)return -cur;
  if(cur==0)return 0;
  REP(i,0,9){
    int x=i/3,y=i%3;
      if(!Map[x][y]){
        Map[x][y] = player;
        int v = dfs(3-player,cur-1,alpha,beta);
        if(player==1)alpha = max(alpha,v);
        if(player==2)beta = min(beta,v);
        Map[x][y] = 0;
        if(beta<=alpha)break; // alpha&beta剪枝
      }
    }
  return player==1?alpha:beta;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int ans = dfs(1,countzero(),-1<<30,1<<30);// 输出为正则棋手1赢，0为平局
  if(ans>0)cout<<"Player 1 win at the "<<9-ans<<" step\n";
  else if(ans<0)cout<<"Player 2 win at the "<<9+ans<<" step\n";
  else cout<<"No one win\n";
  return 0;
}

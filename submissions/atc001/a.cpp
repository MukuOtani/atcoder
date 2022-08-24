#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <deque>
#include <tuple>
#include <map>
#include <sstream>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort(ALL(x))
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

const int lim = 505;
int h, w;
string c[lim];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int sx, sy;
bool visited[lim][lim];

bool dfs(int x, int y){
  visited[y][x] = true;
  rep(i,4){
    int nx=x+dx[i], ny=y+dy[i]; // それぞれ1移動した方向にDFS
    if(nx<0||nx>=w||ny<0||ny>=h) continue; // 場外は考えない
    if(c[ny][nx]=='.'){ // もし隣が道なら
      if(visited[ny][nx]) continue; // すでに探索済みならスルー
      visited[ny][nx] = true;
      if(dfs(nx, ny)) return true; // 初めて訪れるならその座標に対してDFS
    }
    if(c[ny][nx]=='g') return true; // goalに到達したらtrue
  }
  return false; // 探索し終えてしまったらfalse
}

signed main(){
  cin>>h>>w;
  rep(i,h) cin>>c[i];
  rep(i,h){
    rep(j,w){
      if(c[i][j]=='s') sy=i,sx=j;
      visited[i][j] = false;
    }
  }

  bool ans = dfs(sx,sy);
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

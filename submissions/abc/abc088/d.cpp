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

int h,w;
string s[50];
int visited[50][50];
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int dfs(int x, int y){
  // visited[y][x] = cnt;
  int cnt = visited[y][x]+1;
  rep(i,4){
    int nx=x+dx[i], ny=y+dy[i];
    if(nx<0||nx>=w||ny<0||ny>=h) continue;
    if(s[ny][nx]=='.'){
      if(visited[ny][nx]<=cnt) continue;
      visited[ny][nx] = cnt;
      dfs(nx,ny);
    }
    // if(nx==w-1&&ny==h-1){
    //   visited[h-1][w-1] = cnt;
    //   return visited[h-1][w-1];
    // }
  }
  return visited[h-1][w-1];
}

signed main(){
	cin>>h>>w;
  rep(i,h) cin>>s[i];
  int sub = 0;
  rep(i,h){
    rep(j,w){
      if(s[i][j]=='.') sub++;
      visited[i][j] = INF;
    }
  }
  visited[0][0] = 1;
  int ans = dfs(0,0);
  if(ans!=INF) cout << sub-ans << endl;
  else cout << -1 << endl;
	return 0;
}

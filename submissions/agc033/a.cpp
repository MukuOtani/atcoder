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


char A[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

signed main(){
  int h,w; cin>>h>>w;
  rep(i,h){
    rep(j,w) cin>>A[i][j];
  }
  VVI d(h, VI(w,-1));
  queue<PII> q;

  rep(i,h){ // 黒のマスを全部queueに入れる
    rep(j,w){
      if(A[i][j] == '#'){
        d[i][j] = 0; q.push(PII(i,j));
      }
    }
  }

  // BFS
  while(!q.empty()){ // queueを使うなら必須
    auto now = q.front(); q.pop();
    rep(i,4){ // めっちゃ使う座標の変え方
      int nx = now.first + dx[i];
      int ny = now.second + dy[i];
      if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
      if(d[nx][ny] == -1){
        d[nx][ny] = d[now.first][now.second] + 1;
        q.push(PII(nx,ny));
      }
    }
  }
  int ans = 0;
  rep(i,h){
    rep(j,w) ans = max(ans, d[i][j]);
  }
  cout << ans << endl;


  return 0;
}

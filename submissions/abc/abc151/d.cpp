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
#define chmax(a, b) a = (((a)<(b))?(b):(a))

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


signed main(){
  int r,c; cin>>r>>c;
  int sy,sx,gy,gx;
  // cin>>sy>>sx>>gy>>gx;
  // sy--; sx--; gy--; gx--;
  string C[r];
  rep(i,r) cin>>C[i];
  int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
  int visited[r][c];
  // Fill(visited, false):

  // rep(i,r) rep(j,c) visited[i][j]=INF;
  int ans = 0;
  rep(i,r){
    rep(j,c){
      // rep(k,r){
      //   rep(l,c){
          // if(C[i][j]=='#'||C[k][l]=='#') continue;
          if(C[i][j]=='#') continue;
          memset(visited, INF, sizeof(visited));
          sy = i; sx = j;
          // gy = k; gx = l;
          queue<VI> q;
          VI s; s.PB(sy); s.PB(sx); s.PB(0);
          q.push(s);
          visited[sy][sx]=0;

          while(!q.empty()){
            VI p = q.front();
            int y=p[0], x=p[1], cnt=p[2];
            // cerr << y SP x SP cnt << endl;
            q.pop();
            cnt++;
            rep(m,4){
              int ny=y+dy[m], nx=x+dx[m];
              if(nx<0||nx>=c||ny<0||ny>=r) continue;
              if(visited[ny][nx]<=cnt) continue;
              if(C[ny][nx]=='.'){
                VI ad; ad.PB(ny); ad.PB(nx); ad.PB(cnt); q.push(ad);
                visited[ny][nx]=cnt;
                chmax(ans,visited[ny][nx]);
              }
              // if(nx==gx&&ny==gy){
              //   chmax(ans,cnt); break;
              // }
            }
          }
      //   }
      // }
    }
  }
  cout << ans << endl;


  return 0;
}

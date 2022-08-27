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

const int lim = 100100;
int n, a;
int visited[lim], g[lim];

int dfs(int to, int s, int cnt){
  if(visited[to]!=-1){
    cerr << s SP ':' SP visited[s] SP to SP ':' SP visited[to] SP cnt << endl;
    if(!visited[to] == (visited[s]+1)%2) return -1;
    else return cnt;
  }
  visited[to] = (visited[s]+1)%2;
  int t = g[to];
  int ret = dfs(t, to,cnt+1);
  if(ret==-1) return -1;
  cerr << ret << endl;
  return ret;
}

signed main(){
  cin>>n;
  rep(i,n) cin>>g[i], g[i]--, visited[i]=-1;
  int ans = 0;
  rep(i,n){
    if(visited[i]!=-1) continue;
    visited[i] = 0;
    int f = dfs(g[i],i,1);
    if(f==-1) return cout<<-1<<endl, 0;
    ans += (f-1)/2+1;
  }
  cout << ans << endl;
  //
  // bool flg = dfs(g[0],0);
  // cerr << "SEARCH DONE" << endl;
  // cerr << endl;
  // rep(i,n){
  //   cerr << i SP "->" SP g[i] SP ':' SP visited[i] << endl;
  // }
  // cerr << endl;
  // if(!flg) return cout<<-1<<endl, 0;
  // int cnt = 0;
  // rep(i,n) if(visited[i]) cnt++;
  // cout << max(cnt,n-cnt) << endl;

  return 0;
}

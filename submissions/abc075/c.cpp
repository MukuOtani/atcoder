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

const int lim = 50;
int n,m;
int a[lim], b[lim];
bool G[lim][lim], visited[lim];

void dfs(int v){
  visited[v] = true;
  for(int v2 = 0; v2 < n; v2++){
    if(G[v][v2]==false) continue;
    if(visited[v2]==true) continue;
    dfs(v2);
  }
}

signed main(){
	cin>>n>>m;
  rep(i,m){
    cin>>a[i]>>b[i]; a[i]--; b[i]--;
    G[a[i]][b[i]] = G[b[i]][a[i]] = true;
  }
  int ans = 0;
  rep(i,m){
    G[a[i]][b[i]] = G[b[i]][a[i]] = false;
    rep(j,n) visited[j] = false;
    dfs(0);

    bool bridge = false;
    rep(j,n) if(visited[j]==false) bridge = true;
    if(bridge) ans += 1;

    G[a[i]][b[i]] = G[b[i]][a[i]] = true;
  }

  cout << ans << endl;

  return 0;
}

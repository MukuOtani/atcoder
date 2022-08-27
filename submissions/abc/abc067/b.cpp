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

const int lim = 100100;
// using edge = struct{int to; int col;};
VI G[lim];
int d[2][lim], id;

void dfs(int c, int p = -1){
  // if(~p) d[id][c] = d[id][p] + 1;
  d[id][c] = d[id][p] + 1;
  for(auto &to : G[c]){
    if(to != p) dfs(to, c);
  }
}

signed main(){
  int n; cin>>n;
  rep(i,n-1){
    int a,b; cin>>a>>b; a--; b--;
    // G[a].PB({b,-1}); G[b].PB({a,-1});
    G[a].PB(b); G[b].PB(a);
  }
  id = 0; dfs(0);
  id = 1; dfs(n-1);

  int ans = 0;
  rep(i,n){
    if(d[0][i] <= d[1][i]) ans++;
    else ans--;
  }
  if(ans>0) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;

  return 0;
}

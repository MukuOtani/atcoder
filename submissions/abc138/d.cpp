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
const int N = 100100;
vector<bool> flag(N);
VVI G(N); vector<ll> X(N); VI cnt(N);

void bfs(int now, int x){
  if(flag[now]) return;
  flag[now] = true;
  cnt[now] =  X[now] + x;
  rep(i, G[now].size()){
    int next = G[now][i];
    bfs(next, cnt[now]);
  }
}

signed main(){
	int n,q; cin>>n>>q;
  // VVI G; VI C;
  // vector<bool> flag(n);
  rep(i,n){
    VI g; G.PB(g);
  }
  rep(i,n-1){
    int a,b; cin>>a>>b;
    a--; b--;
    G[a].PB(b); G[b].PB(a);
    X.PB(0); flag.PB(false); cnt.PB(0);
  }
  X.PB(0); flag.PB(false); cnt.PB(0);
  rep(i,q){
    int p,x; cin>>p>>x; p--;
    X[p] += x;
  }
  // sort(ALL(C));

  bfs(0,0);
  rep(i,n) cout << cnt[i] << ' ';
  cout << endl;
  return 0;
}

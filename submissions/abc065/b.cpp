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

// UnionFind
struct UnionFind{
  VI par,sizes; // par[i]:iの親の番号
  UnionFind(int n) : par(n), sizes(n,1){ // 最初は全てが根であるとして初期化
    rep(i,n) par[i] = i;
  }
  int root(int x){
    if(par[x]==x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y){
    int rx = root(x); int ry = root(y);
    if(rx==ry) return;
    if(sizes[rx]<sizes[ry]) swap(rx,ry);
    par[ry] = rx;
    sizes[rx] += sizes[ry];
  }
  bool same(int x, int y){
    return root(x)==root(y);
  }
  int size(int x){
    return sizes[root(x)];
  }
};


signed main(){
  int n; cin>>n;
  VVI x, y;
  rep(i,n){
    int a,b; cin>>a>>b;
    VI x0, y0; x0.PB(a); x0.PB(i); y0.PB(b); y0.PB(i);
    x.PB(x0); y.PB(y0);
  }
  sort(ALL(x)), sort(ALL(y));

  using edge = pair<int, PII>;
  vector<edge> edges;
  rep(i,n-1){
    int s = x[i][1], t = x[i+1][1];
    edges.PB(edge(x[i+1][0]-x[i][0], PII(s,t)));
    int u = y[i][1], v = y[i+1][1];
    edges.PB(edge(y[i+1][0]-y[i][0], PII(u,v)));
  }
  sort(ALL(edges));
  // cerr << edges[0].first SP edges[0].second.first SP edges[0].second.second << endl;
  // ここまでは動作確認済み

  UnionFind uf(n);
  ll ans = 0;
  for(auto e : edges){
    int u = e.second.first, v = e.second.second;
    ll cost = e.first;
    if(uf.same(u,v)) continue;
    uf.unite(u,v);
    ans += cost;
  }
  cout << ans << endl;



  return 0;
}

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

struct UnionFind{
  VI par,sizes; // par[i]:i‚Ìe‚Ì”Ô†
  UnionFind(int n) : par(n), sizes(n,1){ // Å‰‚Í‘S‚Ä‚ªª‚Å‚ ‚é‚Æ‚µ‚Ä‰Šú‰»
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
  ll n,m; cin>>n>>m;
  UnionFind tree(n);
  int a[m],b[m];
  ll ans[m];
  rep(i,m){cin>>a[i]>>b[i]; a[i]--; b[i]--;}

  ans[m-1] = n*(n-1)/2;
  REPS(i,m-1){
    int l,r; l=a[i]; r=b[i];
    ans[i-1] = ans[i];
    if(tree.same(l,r)) continue;
    ans[i-1] -= tree.size(l)*tree.size(r);
    tree.unite(l,r);
  }
  rep(i,m) cout << ans[i] << endl;
  return 0;
}

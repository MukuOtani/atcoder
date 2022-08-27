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
#include <string>
#include <queue>
#include <deque>
#include <tuple>
#include <map>
#include <sstream>
#include <bits/stdc++.h>
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
const long double PI  = acos(-1.0L);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
#define chmax(a,b) a = (((a)<(b))?(b):(a))
#define chmin(a,b) a = (((a)>(b))?(b):(a))

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

// UnionFind
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
	int n,m,k; cin>>n>>m>>k;
	vector<set<int> > rel(n);
	UnionFind uf(n);
	rep(i,m){
		int a,b; cin>>a>>b; a--; b--;
		rel[a].insert(b); rel[b].insert(a);
		uf.unite(a,b);
	}
	rep(i,k){
		int c,d; cin>>c>>d; c--; d--;
		if(!uf.same(c,d)) continue;
		rel[c].insert(d); rel[d].insert(c);
	}
	rep(i,n){
		int ans = uf.size(i)-1;
		ans -= rel[i].size();
		cout << ans << ' ';
	}
	cout << endl;
  return 0;
}

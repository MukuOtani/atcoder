#include <bits/stdc++.h>
using namespace std;
#define MOD (long long int)(998244353)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const long double PI  = acos(-1.0L);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<double,double> PDD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
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
	int n,m,e; cin>>n>>m>>e;
	vector<PII> l(e);
	
	rep(i,e){
		int u,v;
		cin>>u>>v; u--; v--;
		l[i]={chmin(u,n), chmin(v,n)};
	}
	int q; cin>>q;
	VI x(q); rep(i,q) cin>>x[i], x[i]--;
	VI ans(q);
	vector<bool> con(n, false);
	
	vector<bool> valid(e, true);
	rep(i,q) valid[x[i]]=false;

	UnionFind uf(n+1);
	int cnt = 0;
	rep(i,e){
		if(valid[i]){
			int u=l[i].first, v=l[i].second;
			uf.unite(u,v);
		}
	}
	REP(i,q){
		ans[i]=uf.size(n)-1;
		int u=l[x[i]].first, v=l[x[i]].second;
		uf.unite(u,v);
	}

	rep(i,q) cout<<ans[i]<<endl;

	return 0;
}

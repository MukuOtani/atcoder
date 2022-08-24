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
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
const long double PI  = acos(-1.0L);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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

double x[40], y[40], c[40];
int n,m;

double kruskal(vector<pair<double, PII>> edges, int V){
  // sort(es,es+E,comp); // edge.costが小さい順にソートする
  UnionFind uf(V);
  double res = 0;
  for(auto &e: edges){
    double cost=e.first;
		int a=e.second.first, b=e.second.second;
    if(!uf.same(a,b)){
      uf.unite(a,b); res+=cost;
    }
  }
  return res;
}

signed main(){
	cin>>n>>m;
	rep(i,n) cin>>x[i]>>y[i]>>c[i];
	rep(i,m) cin>>x[i+n]>>y[i+n]>>c[i+n];
	double ans=1e30;
	rep(b,1<<m){
		VI p; rep(i,n) p.PB(i); rep(i,m)if(b&(1<<i)) p.PB(i+n);
		int l=p.size();
		vector<pair<double, PII>> edges;
		rep(i,l)for(int j=i+1;j<l;j++){
			int a=p[i], b=p[j];
			double dx=x[a]-x[b], dy=y[a]-y[b];
			double d=sqrt(dx*dx+dy*dy);
			if(c[a]!=c[b]) d*=10.0;
			edges.PB({d,{i,j}});
		}
		sort(ALL(edges));
		double res=kruskal(edges,l);
		cerr<<res<<' ';
		chmin(ans,res);
	}
	cerr<<endl;
	cout<<ans<<endl;

	return 0;
}

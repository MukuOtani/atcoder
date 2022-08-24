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
#define chmax(a,b) a = (((a)<(b))?(b):(a))
#define chmin(a,b) a = (((a)>(b))?(b):(a))

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

vector<ll> g[200100];
ll n, root=0, parent[200100], depth[200100];
ll q;
ll sum, ans[200100], tmp[200100];

void dfs(ll v, ll p, ll d){
	depth[v] = d;
	rep(i,g[v].size()){
		if(g[v][i]==p) continue;
		dfs(g[v][i], v, d+1);
	}
}

void dfs2(ll v, ll p, ll t){
	ans[v] = t+tmp[v];
	rep(i,g[v].size()){
		if(g[v][i]==p) continue;
		dfs2(g[v][i], v, ans[v]);
	}
}


void add_edge(ll u, ll v){
	g[u].PB(v); g[v].PB(u);
}

signed main() {
	cin>>n;
	VI a(n-1), b(n-1);
	rep(i,n-1){
		ll u,v; cin>>u>>v; u--; v--;
		a[i]=u; b[i]=v;
		add_edge(u,v);
	}
	dfs(root,-1,0);

	cin>>q;
	sum = 0LL;
	rep(i,q){
		ll t,e,x; cin>>t>>e>>x;
		e--;
		if(t==1){
			if(depth[a[e]]<depth[b[e]]){
				sum+=x;
				tmp[b[e]]-=x;
			}else{
				tmp[a[e]]+=x;
			}
		}else{
			if(depth[b[e]]<depth[a[e]]){
				sum+=x;
				tmp[a[e]]-=x;
			}else{
				tmp[b[e]]+=x;
			}
		}
	}

	rep(i,n) ans[i]=0LL;
	// cerr<<sum<<endl;
	// rep(i,n) cerr<<tmp[i]<<' ';
	// cerr<<endl;


	ans[0] = sum;
	dfs2(root,-1,sum);

	rep(i,n) cout<<ans[i]<<endl;

	return 0;
}

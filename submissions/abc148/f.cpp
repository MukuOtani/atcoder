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

struct HLDecomposition {
	vector<set<int>> g; vector<int> vid, head, heavy, parent, depth, inv, in, out;
	HLDecomposition() {} HLDecomposition(int n) { init(n); }
	void init(int n) {
		g.resize(n); vid.resize(n, -1); head.resize(n); heavy.resize(n, -1);
		parent.resize(n); depth.resize(n); inv.resize(n); in.resize(n); out.resize(n);
	}
	void add(int u, int v) { g[u].insert(v); g[v].insert(u); }
	void build(int root) { dfs(root, -1); t = 0; dfs_hld(root); }

	int dfs(int curr, int prev) {
		parent[curr] = prev; int sub = 1, max_sub = 0;
		heavy[curr] = -1;
		for (int next : g[curr]) if (next != prev) {
			depth[next] = depth[curr] + 1;
			int sub_next = dfs(next, curr); sub += sub_next;
			if (max_sub < sub_next) max_sub = sub_next, heavy[curr] = next;
		}return sub;
	}

	int t = 0;
	void dfs_hld(int v = 0)
	{
		vid[v] = in[v] = t;
		t++;
		inv[in[v]] = v;
		if (0 <= heavy[v]) {
			head[heavy[v]] = head[v];
			dfs_hld(heavy[v]);
		}
		for (auto u : g[v]) if (depth[v] < depth[u])  if (u != heavy[v]) {
			head[u] = u;
			dfs_hld(u);
		}
		out[v] = t;
	}


	void foreach(int u, int v, function<void(int, int)> f) { // [x,y]
		if (vid[u] > vid[v]) swap(u, v); f(max(vid[head[v]], vid[u]), vid[v]);
		if (head[u] != head[v]) foreach(u, parent[head[v]], f);
	}
	int ancestor(int from, int times) {
		while (true) {
			if (depth[head[from]] > depth[from] - times) {
				times -= depth[from] - depth[head[from]] + 1; if (head[from] == 0)return -1; from = parent[head[from]];
			}
			else return inv[vid[from] - times];
		}
	}
	int lca(int u, int v) {
		if (vid[u] > vid[v]) swap(u, v); if (head[u] == head[v]) return u;
		return lca(u, parent[head[v]]);
	}
	int distance(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
	int child(int parent, int child, int times) {
		assert(depth[parent] < depth[child]);
		int d = distance(parent, child); assert(times - 1 <= d); return ancestor(child, d - times);
	}
	int go(int from, int to, int times) {
		int d = distance(from, to); assert(0 <= times and times <= d);
		int lc = lca(from, to); if (lc == to)return ancestor(from, times); if (lc == from)return child(from, to, times);
		int dd = distance(from, lc); if (dd <= times)return go(lc, to, times - dd); return ancestor(from, times);
	}
};


signed main(){
	int n,u,v; cin>>n>>u>>v; u--; v--;
	HLDecomposition hld(n);
	rep(i,n-1){
		int a,b; cin>>a>>b; a--; b--; hld.add(a,b);
	}
	hld.build(u);

	int ans=0;
	rep(i,n){
		if(hld.g[i].size()==1){
			int lc=hld.lca(i,v);
			int tak=hld.distance(lc,u);
			int aok=hld.distance(lc,v);
			if(aok<=tak) continue;
			int tak2=hld.distance(u,i);
			int aok2=hld.distance(v,i);
			int cnt=aok2-1;
			chmax(ans,cnt);
		}
	}
	cout<<ans<<endl;
	return 0;
}

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
#define EPS (1e-10)
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

int a[220000];
int ans[220000];
VI dp(220000,INF);
VI edge[220000];

void dfs(int x, int last=-1){
	int lis_idx = lower_bound(ALL(dp),a[x])-dp.begin();
	int last_val = dp[lis_idx];
	dp[lis_idx] = a[x];
	ans[x] = lower_bound(ALL(dp),INF)-dp.begin();
	for(auto to:edge[x]){
		if(to==last) continue;
		dfs(to,x);
	}
	dp[lis_idx] = last_val;
}



signed main(){
	int n,u,v; cin>>n;
	rep(i,n) cin>>a[i];
	rep(i,n-1){
		cin>>u>>v; u--; v--;
		edge[u].PB(v); edge[v].PB(u);
	}
	dfs(0);
	rep(i,n) cout<<ans[i]<<endl;

	return 0;
}

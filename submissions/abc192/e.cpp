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

signed main() {
	ll n,m,x,y; cin>>n>>m>>x>>y; x--; y--;
	vector<vector<vector<ll>>> g;
	rep(i,n){
		VVL f; g.PB(f);
	}
	rep(i,m){
		ll a,b,t,k; cin>>a>>b>>t>>k;
		a--; b--;
		VL f; f.PB(b); f.PB(t); f.PB(k);
		g[a].PB(f);
		f[0]=a;
		g[b].PB(f);
	}
	vector<bool> visited(n,false);
	// visited[x] = true;
	priority_queue<PLL,vector<PLL>, greater<PLL>> q;
	q.push(MP(0,x));
	ll ans = LINF;
	while(q.size()){
		PLL p = q.top(); q.pop();
		ll now=p.second, time=p.first;
		if(now==y){
			ans=time; break;
		}
		if(visited[now]){
			continue;
		}
		visited[now] = true;
		rep(i,g[now].size()){
			if(!visited[g[now][i][0]]){
				ll k = g[now][i][2], t = g[now][i][1];
				ll next = k*(time/k)+t;
				if(time%k){
					next+=k;
				}
				q.push(MP(next,g[now][i][0]));
			}
		}
	}
	if(ans==LINF){
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}

	return 0;
}

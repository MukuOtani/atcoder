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

signed main(){
	int n; cin>>n;
	vector<PLL> a(n);
	for(ll i=1;i<=n;i++){
		ll c; cin>>c; a.PB(MP(c,i));
	}
	sort(RALL(a));
	ll dp[n+1][n+1]; rep(i,n+1)rep(j,n+1)dp[i][j]=-1;
	dp[0][0]=0LL;
	for(ll idx=0;idx<n;idx++){
		for(ll i=0;i<=idx;i++){
			if(dp[i][idx-i]==-1) continue;
			chmax(dp[i+1][idx-i],dp[i][idx-i]+a[idx].first*abs(i+1-a[idx].second));
			chmax(dp[i][idx-i+1],dp[i][idx-i]+a[idx].first*abs(n-(idx-i)-a[idx].second));
		}
	}
	ll ans=0LL;
	rep(i,n+1) chmax(ans,dp[i][n-i]);
	cout<<ans<<endl;
	return 0;
}

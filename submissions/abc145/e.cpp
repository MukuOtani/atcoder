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

ll dp1[3300][3300];
ll dp2[3300][3300];

signed main(){
	ll n,t; cin>>n>>t;
	VL a(n),b(n); rep(i,n) cin>>a[i]>>b[i];
	// memset(dp1,-1,sizeof(dp1));
	// memset(dp2,-1,sizeof(dp2));
	dp1[0][0]=0LL; dp2[n+1][0]=0LL;
	reps(i,n){
		rep(j,t){
			dp1[i][j]=dp1[i-1][j];
			if(j-a[i-1]>=0) chmax(dp1[i][j],dp1[i-1][j-a[i-1]]+b[i-1]);
		}
	}
	REPS(i,n){
		rep(j,t){
			dp2[i][j]=dp2[i+1][j];
			if(j-a[i-1]>=0) chmax(dp2[i][j],dp2[i+1][j-a[i-1]]+b[i-1]);
		}
	}
	ll ans=max(dp1[n][t-1],dp2[1][t-1]);
	rep(i,n){
		rep(j,t){
			chmax(ans,dp1[i][j]+b[i]+dp2[i+2][t-1-j]);
		}
	}
	cout<<ans<<endl;

	return 0;
}

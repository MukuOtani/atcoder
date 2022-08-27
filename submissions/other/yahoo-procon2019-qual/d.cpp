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

ll cost(int i, int s, VL &a){
	if(s==0||s==4) return a[i];
	else if(s==1||s==3){
		if(a[i]%2==0&&a[i]>0) return 0LL;
		else if(a[i]>0) return 1LL;
		else return 2LL;
	}else{
		if(a[i]%2LL==0LL) return 1LL;
		else return 0LL;
	}
}

signed main() {
	ll n; cin>>n;
	VL a(n); rep(i,n)cin>>a[i];
	ll dp[n+1][5];
	rep(i,n+1)rep(j,5) dp[i][j]=LINF;
	dp[0][0]=0LL;

	rep(i,n){
		rep(j,5){
			for(int k=j; k<5; k++){
				chmin(dp[i+1][k], dp[i][j]+cost(i,k,a));
			}
		}
	}
	ll ans=LINF;
	rep(j,5) chmin(ans,dp[n][j]);
	cout<<ans<<endl;

	return 0;
}

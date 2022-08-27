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
	int n,m; cin>>n>>m;
	VL a(m),b(m),c(m,0L);
	rep(i,m){
		cin>>a[i]>>b[i];
		rep(j,b[i]){
			int t; cin>>t; t--;	c[i]+=(1<<t);
		}
	}
	ll dp[m+5][(1<<n)+5]; memset(dp,INF,sizeof(dp));
	dp[0][0]=0;

	rep(i,m){
		rep(j,1<<n){
		  chmin(dp[i+1][j],dp[i][j]);
			chmin(dp[i+1][j|c[i]],dp[i][j]+a[i]);
		}
	}

	cout<<(dp[m][(1<<n)-1]<INF ? dp[m][(1<<n)-1] : -1)<<endl;
	
	return 0;
}

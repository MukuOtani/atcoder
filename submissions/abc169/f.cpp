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

// a‚Ìpæ‚ð‹‚ß‚éŠÖ”
ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==0){
		ll memo = mpow(a,b/2);
		return memo*memo%MOD;
	}else{
		return mpow(a,b-1)*a%MOD;
	}
}

signed main() {
	int n,s; cin>>n>>s;
  ll dp[n+5][s+5]; rep(i,n+5)rep(j,s+5) dp[i][j]=0LL;
	dp[0][0]=1LL;
	VL a(n);
	rep(i,n)cin>>a[i]; sort(ALL(a));
	
	rep(i,n){
      rep(j,s+1){
        dp[i+1][j]+=2*dp[i][j];
        dp[i+1][j]%=MOD;
        if(j+a[i]<=s){
          dp[i+1][j+a[i]]+=dp[i][j];
          dp[i+1][j+a[i]]%=MOD;
        }
      }
	}
  cout<<dp[n][s]<<endl;
	
	return 0;
}

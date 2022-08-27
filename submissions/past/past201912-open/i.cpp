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




signed main(){
	int n,m; cin>>n>>m;
	ll dp[m+5][1<<n];
	string s[m]; ll c[m]; rep(i,m) cin>>s[i]>>c[i];
	rep(i,m+5)rep(j,1<<n)	dp[i][j]=LINF;
	dp[0][0]=0LL;
	int bits[m]; CLR(bits);
	rep(i,m){
		rep(j,n){
			bits[i]*=2;
			if(s[i][j]=='Y') bits[i]++;
		}
	}
	rep(i,m){
		int bit = bits[i];
		rep(j,1<<n){
			if(dp[i][j]!=LINF){
				chmin(dp[i+1][j], dp[i][j]);
				chmin(dp[i+1][j|bit], dp[i][j]+c[i]);
			}
		}
	}
	if(dp[m][(1<<n)-1]!=LINF) cout<<dp[m][(1<<n)-1]<<endl;
	else cout<<-1<<endl;
	return 0;
}

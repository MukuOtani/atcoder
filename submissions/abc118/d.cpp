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
	const int need[10]={0,2,5,5,4,5,6,3,7,6};
	VI a(m); rep(i,m) cin>>a[i]; sort(RALL(a));
	int dp[n+5]; fill(dp,dp+n+5,-INF); dp[0]=0;
	rep(i,n){
		if(dp[i]==-INF) continue;
		rep(j,m){
			if(i+need[a[j]]>n) continue;
			chmax(dp[i+need[a[j]]],dp[i]+1);
		}
	}
	// rep(i,n+1) cerr<<dp[i]<<' ';
	// cerr<<endl;
	int keta=dp[n];
	int cnt=n;
	REP(i,keta){
		rep(j,m){
			if(cnt-need[a[j]]<0) continue;
			if(dp[cnt-need[a[j]]]==i){
				cout<<a[j]; cnt-=need[a[j]]; j=m;
			}
		}
	}
cout<<endl;


	return 0;
}

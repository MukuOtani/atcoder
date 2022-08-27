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

ll n,m,ans;
VL a;

bool check(ll x){
	ll cnt=0LL;
	rep(i,n){
		ll pos=lower_bound(ALL(a), x-a[i])-a.begin();
		cnt+=n-pos;
	}
	return cnt<m;
}



signed main(){
	cin>>n>>m;
	a.resize(n); rep(i,n) cin>>a[i]; sort(ALL(a));

	ll ng=0, ok=LINF;
	while(abs(ok-ng)>1){
		ll mid=(ok+ng)/2;
		if(check(mid)) ok=mid;
		else ng=mid;
	}
	VL s(n+1,0LL); rep(i,n) s[i+1]=s[i]+a[i];
	rep(i,n){
		ll pos=upper_bound(ALL(a), ng-a[i])-a.begin();
		ll cnt=n-pos;
		ans+=cnt*a[i]+(s[n]-s[pos]);
		m-=cnt;
	}
	ans+=m*ng;
cout<<ans<<endl;


	return 0;
}

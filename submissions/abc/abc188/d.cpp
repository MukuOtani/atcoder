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


signed main() {
	ll n,p; cin>>n>>p;
	// VVL d(n);
	// rep(i,n){
	// 	VL a(3); rep(j,3) cin>>a[j];
	// 	d.PB(a);
	// }
	// sort(ALL(d));
	// ll ans = 0LL, now = 0LL;
	// priority_queue<PLL,vector<PLL>,greater<PLL>> que;
	// ll today = 0LL;
	// ll yesterday = 0LL;
	// rep(i,n){
	// 	today = a[i];
	// 	if(now>p){
	// 		ans += p*(today-yesterday);
	// 	}else{
	// 		ans += now*(today-yesterday);
	// 	}
	// 	now += c[i]; que.push({b[i],c[i]});
	// 	while(que.top().first<today){
	// 		now -= que.top().second;
	// 		que.pop();
	// 	}
	// }
	vector<PLL> d;
	rep(i,n){
		ll a,b,c; cin>>a>>b>>c;
		d.PB({a,+c}); d.PB({b+1,-c});
	}
	sort(ALL(d));
	ll now=0LL, last=0LL;
	ll cost=0LL, ans=0LL;
	rep(i,n*2){
		now=d[i].first;
		// cerr<<d[i].first SP d[i].second SP now SP last SP cost SP ans <<endl;
		if(d[i].second>0){
			ans+=min(cost,p)*(now-last);
			cost+=d[i].second;
		}else{
			ans+=min(cost,p)*(now-last);
			cost+=d[i].second;
		}
		last=now;
	}
	cout<<ans<<endl;
	return 0;
}

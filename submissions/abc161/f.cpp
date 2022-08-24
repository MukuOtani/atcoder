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

VL rem1;
VL rem2;

VL soinsu(ll n){
	// ll ret = 2;
	VL ret;
	for(ll i=2; i*i<=n; i++){
		if(n%i==0){
			ret.PB(i);
			if(n/i!=i) ret.PB(n/i);
		}
	}
	// sort(ALL(rem));
	return ret;
}


signed main(){
	ll n; cin>>n;
	if(n==2) return cout<<1<<endl,0;
	int ans = soinsu(n-1).size()+2;
	cerr<<ans<<endl;
	VL ret = soinsu(n);
	rep(i,ret.size()){
		ll tmp = n;
		while(tmp%ret[i]==0) tmp/=ret[i];
		if(tmp%ret[i]==1) ans++;
	}
	cout<<ans<<endl;
	return 0;
}

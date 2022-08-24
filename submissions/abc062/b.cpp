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


signed main(){
	int n; cin>>n;
	VL a(3*n); rep(i,3*n) cin>>a[i];
	priority_queue<ll, VL, greater<ll>> q;
	priority_queue<ll> r;
	VL s(3*n), t(3*n);
	ll sum=0LL;
	rep(i,n){
		sum+=a[i]; q.push(a[i]);
		s[i]=sum;
		// cerr<< i SP sum <<endl;
	}
	rep(i,n){
		q.push(a[n+i]);
		sum+=a[n+i]-q.top(); q.pop();
		s[n+i]=sum;
	}

	sum=0LL;
	rep(i,n){
		sum+=a[3*n-i-1]; r.push(a[3*n-i-1]);
		t[3*n-i-1]=sum;
		// cerr<< i SP sum <<endl;
	}
	rep(i,n){
		r.push(a[2*n-i-1]);
		sum+=a[2*n-i-1]-r.top(); r.pop();
		t[2*n-i-1]=sum;
	}
	// rep(i,3*n){
	// 	cerr<<i SP s[i] SP t[i]<<endl;
	// }
	ll ans=-LINF;
	for(int i=n-1;i<2*n;i++){
		chmax(ans,s[i]-t[i+1]);
	}
	cout<<ans<<endl;

	return 0;
}

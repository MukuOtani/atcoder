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

signed main() {
	int n; cin>>n;
	VL a(n), b(n); rep(i,n) cin>>a[i]>>b[i];
	sort(ALL(a)); sort(ALL(b));
	if(n%2==1){
		cout<<b[(n-1)/2]-a[(n-1)/2]+1<<endl;
	}else{
		ll ans;
		if(b[n/2-1]<a[n/2]){
			ans=(b[n/2]+b[n/2-1])-(a[n/2-1]+a[n/2])+1;
		}else{
			ans=(b[n/2]+b[n/2-1])-(a[n/2]+a[n/2-1])+1;
		}
		// ll ans=(b[n/2]-a[n/2-1])*2-1;
		// if(b[n/2-1]<a[n/2]) ans-=(a[n/2]-b[n/2-1])*2
		// if(a[n/2]==a[n/2-1]) ans++;
		// if(b[n/2]==b[n/2-1]) ans++;
		cout<<ans<<endl;
	}

	return 0;
}

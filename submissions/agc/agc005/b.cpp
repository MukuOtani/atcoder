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
	ll idx[n];
	for(ll i=1;i<=n;i++){
		ll a; cin>>a; a--; idx[a]=i;
	}
	set<ll> s{0LL,n+1};
	ll ans=0LL;
	for(ll i=0;i<n;i++){
		ll next=idx[i];
		s.insert(next);
		auto itr_next=s.lower_bound(next);
		// int idx_next=distance(s.begin(),itr_next);
		itr_next--;
		ll a=*itr_next; itr_next++;
		ll b=*itr_next; itr_next++;
		ll c=*itr_next;
		// cerr<<a SP b SP c<<endl;
		ans+=(i+1)*(c-b)*(b-a);
		// cerr<<i SP ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

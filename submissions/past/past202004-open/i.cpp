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
#define EPS (1e-10)
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

int n;
VI ans(1<<16,0);

vector<PII> battle(vector<PII> a){
	vector<PII> ret;
	int m=a.size();
	for(int i=0; i<m; i+=2){
		// cerr<<a[i].first SP a[i].second SP a[i+1].first SP a[i+1].second<<endl;
		if(a[i].first>a[i+1].first){
			ret.PB(a[i]); ans[a[i+1].second]=n-log2(m)+1;
		}else{
			ret.PB(a[i+1]); ans[a[i].second]=n-log2(m)+1;
		}
	}
	if(ret.size()==1) ans[ret[0].second]=n-log2(m)+1;
	// rep(i,1<<n) cerr<<ans[i]<<' ';
	cerr<<endl;
	return ret;
}


signed main(){
	cin>>n;
	vector<PII> a;
	// VI ans(1<<n,0);
	rep(i,1<<n){
		PII p; cin>>p.first; p.second=i; a.PB(p);
	}
	rep(i,n) a=battle(a);
	rep(i,1<<n) cout<<ans[i]<<endl;

	return 0;
}

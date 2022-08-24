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
	int n,k,c; cin>>n>>k>>c;
	string s; cin>>s;
	int f[k],b[k];
	int fwd=0, bwd=n-1, cnt=0;
	while(cnt<k){
		if(s[fwd]=='o') f[cnt]=fwd+1, cerr<<fwd+1<<' ', fwd+=c, cnt++;
		fwd++;
	}
	cerr<<endl;
	cnt=0;
	while(cnt<k){
		if(s[bwd]=='o') b[k-cnt-1]=bwd+1, cerr<<bwd+1<<' ', bwd-=c, cnt++;
		bwd--;
	}
	cerr<<endl;
	rep(i,k)if(f[i]==b[i]) cout<<f[i]<<endl;

	return 0;
}

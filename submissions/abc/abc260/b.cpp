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
typedef vector<VL> VVL;
#define chmax(a,b) a = (((a)<(b))?(b):(a))
#define chmin(a,b) a = (((a)>(b))?(b):(a))

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

signed main(){
	int n,x,y,z; cin>>n>>x>>y>>z;
	vector<bool> g(n,false);
	VL p(n),q(n),s(n);
	rep(i,n){
		cin>>p[i];
		s[i]=p[i];
		p[i]=p[i]*10000+1000-i;
	}
	rep(i,n){
		cin>>q[i];
		s[i]=(s[i]+q[i])*10000+1000-i;
		q[i]=q[i]*10000+1000-i;
	}
	sort(RALL(p)); sort(RALL(q)); sort(RALL(s));
	rep(i,x){
		int c=1000-(p[i]%10000);
		g[c]=true;
	}
	int cnt=0, pass=0;
	while(pass<y){
		int c=1000-(q[cnt]%10000);
		if(!g[c]){
			g[c]=true;
			pass++;
		}
		cnt++;
	}
	cnt=0; pass=0;
	while(pass<z){
		int c=1000-(s[cnt]%10000);
		if(!g[c]){
			g[c]=true;
			pass++;
		}
		cnt++;
	}
	cerr<<endl;
	rep(i,n){
		if(g[i]) cout<<i+1<<endl;
	}

	return 0;
}

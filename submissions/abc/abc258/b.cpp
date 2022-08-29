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
	int n; cin>>n;
	VVI a(n, VI(n)); 
	rep(i,n)rep(j,n){
		char c; cin>>c;
		a[i][j] = c-'0';
	}
	vector<int> dx={1,1,1,0,0,-1,-1,-1}, dy={1,0,-1,1,-1,1,0,-1};
	ll ans=0LL;
	rep(i,n){
		rep(j,n){
			rep(k,8){
				ll val=0LL;
				ll x=i, y=j;
				rep(l,n){
					val=10*val+a[x][y];
					x=(x+dx[k]+n)%n;
					y=(y+dy[k]+n)%n;
				}
				chmax(ans,val);
			}
		}
	}
	cout<<ans<<endl;	
	return 0;
}

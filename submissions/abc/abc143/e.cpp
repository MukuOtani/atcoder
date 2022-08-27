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


signed main(){
	int n,m; ll l; cin>>n>>m>>l;
	ll d[n+5][n+5], c[n+5][n+5];
	rep(i,n)rep(j,n) d[i][j]=LINF;
	rep(i,n) d[i][i]=0LL;

	rep(i,m){
		int a,b; ll cost; cin>>a>>b>>cost; a--; b--;
		d[a][b]=cost; d[b][a]=cost;
	}

	rep(k,n)rep(i,n)rep(j,n) chmin(d[i][j],d[i][k]+d[k][j]);

	rep(i,n){
		rep(j,n){
			if(d[i][j]<=l) c[i][j]=1LL;
			else c[i][j]=LINF;
		}
	}
	rep(i,n) c[i][i]=0LL;

	rep(k,n)rep(i,n)rep(j,n) chmin(c[i][j],c[i][k]+c[k][j]);

	int q; cin>>q;
	rep(i,q){
		int s,t; cin>>s>>t; s--; t--;
		if(c[s][t]>=n+5) cout<<-1<<endl;
		else cout<<c[s][t]-1<<endl;
	}



	return 0;
}

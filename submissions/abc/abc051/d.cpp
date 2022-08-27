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

const int MAX_V = 105;
ll d[MAX_V][MAX_V];
int V;

void warshall_floyd(){
	rep(k,V)rep(i,V)rep(j,V) chmin(d[i][j],d[i][k]+d[k][j]);
}

signed main(){
	int n,m; cin>>n>>m;	V=n;
	int a[m], b[m]; ll c[m];
	memset(d,INF,sizeof(d));
	rep(i,n) d[i][i]=0LL;
	rep(i,m){
		cin>>a[i]>>b[i]>>c[i]; a[i]--; b[i]--;
		chmin(d[a[i]][b[i]],c[i]); chmin(d[b[i]][a[i]],c[i]);
	}
	warshall_floyd();
	int ans=m;
	rep(i,m){
		bool flg=false;
		rep(j,n){
			if(d[j][a[i]]+c[i]==d[j][b[i]]) flg=true;
		}
		if(flg) ans--;
	}
	cout<<ans<<endl;
	return 0;
}

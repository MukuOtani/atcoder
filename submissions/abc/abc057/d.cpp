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

ll c[51][51];

void comb_table(int n){
	rep(i,n+1){
		rep(j,i+1){
			if(j==0||j==i){
				c[i][j]=1LL;
			}else{
				c[i][j]=(c[i-1][j-1]+c[i-1][j]);
			}
		}
	}
}

signed main(){
	int n,a,b; cin>>n>>a>>b;
	vector<double> v(n); rep(i,n) cin>>v[i]; sort(RALL(v));
	double ave=0.0;	rep(i,a) ave+=v[i];	ave/=a;
	int is_a=0, cnt=0; comb_table(n);
	rep(i,n){
		if(v[i]==v[a-1]){
			is_a++;
			if(i<a) cnt++;
		}
	}
	ll ans=0LL;
	cerr<<is_a SP cnt<<endl;
	if(cnt==a){
		for(int i=a;i<=b;i++) ans+=c[is_a][i];
	}else{
		ans=c[is_a][cnt];
	}
	cout<<ave<<endl<<ans<<endl;
	return 0;
}

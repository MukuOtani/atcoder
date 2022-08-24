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
	int n,k; cin>>n>>k;
	VL x(n),y(n),xs(n),ys(n);
	rep(i,n){
		cin>>x[i]>>y[i]; xs[i]=x[i]; ys[i]=y[i];
	}
	sort(ALL(xs)); sort(ALL(ys));
	ll ans=(xs[n-1]-xs[0])*(ys[n-1]-ys[0]);
	for(int x1=0; x1<n; x1++){
		for(int y1=0; y1<n; y1++){
			for(int x2=x1+1; x2<n; x2++){
				for(int y2=y1+1; y2<n; y2++){
					ll l=xs[x1], r=xs[x2], b=ys[y1], u=ys[y2];
					int cnt=0;
					rep(i,n){
						if(l<=x[i]&&x[i]<=r&&b<=y[i]&&y[i]<=u) cnt++;
					}
					if(cnt>=k) chmin(ans,1LL*(r-l)*(u-b));
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

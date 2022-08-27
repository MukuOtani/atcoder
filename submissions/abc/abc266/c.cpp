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

bool hantei(int ox, int oy, int ax, int ay, int bx, int by){
	int oax = ax-ox, oay = ay-oy, obx = bx-ox, oby = by-oy;
	cerr << oax*oby-oay*obx << endl;
	return ((oax*oby-oay*obx)>0) ? true : false;
}

signed main(){
	VI x(4,0), y(4,0); rep(i,4) cin>>x[i]>>y[i];
	bool ans = true;
	reps(i,4){
		ans &= hantei(x[i%4], y[i%4], x[(i+1)%4], y[(i+1)%4], x[(i-1)%4], y[(i-1)%4]);
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}

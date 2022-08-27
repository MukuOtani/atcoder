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
	int h1,h2,w1,w2;
	cin>>h1>>w1;
	VVI a(h1,VI(w1)); rep(i,h1)rep(j,w1) cin>>a[i][j];
	cin>>h2>>w2;
	VVI b(h2,VI(w2)); rep(i,h2)rep(j,w2) cin>>b[i][j];

	rep(i,1<<h1)rep(j,1<<w1){
		VI h,w;
		rep(k,h1) if((i&(1<<k))==0) h.PB(k);
		rep(k,w1) if((j&(1<<k))==0) w.PB(k);
		if(h.size()!=h2 || w.size()!=w2) continue;

		bool hantei = true;
		rep(k,h2)rep(l,w2){
			if(a[h[k]][w[l]]!=b[k][l]){
				hantei = false;
				break;
			}
		}
		if(hantei) return cout<<"Yes"<<endl,0;
	}
	cout<<"No"<<endl;
	return 0;
}

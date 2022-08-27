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
#define INF (1<<29)
#define LINF (1LL<<60)
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

int n,m;

bool check(vector<PDD> opt, double mid){
	vector<double> monster;
	rep(i,opt.size()) monster.PB(opt[i].second-mid*opt[i].first);
	sort(RALL(monster));
	double magic=0;
	rep(i,5) magic+=monster[i];
	if(magic>=0) return true;
	return false;
}

signed main(){
	cin>>n>>m;
	vector<PDD> ab(n),cd(m);
	rep(i,n){
		double a,b; cin>>a>>b; ab[i]=MP(a,b);
	}
	rep(i,m){
		double c,d; cin>>c>>d; cd[i]=MP(c,d);
	}
	double ans=-1;
	rep(i,m+1){
		auto opt = ab;
		if(i>0) opt.PB(cd[i-1]);

		double ok=0, ng=1e20;
		int c=200;
		while(abs(ok-ng)>1e-16&&c>=0){
			double mid=(ok+ng)/2.0;
			if(check(opt,mid)) ok=mid;
			else ng=mid;
			c--;
		}
		chmax(ans,ok);
	}
	cout<<ans<<endl;

	return 0;
}

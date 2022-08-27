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
	int n; cin>>n;
	vector<PII> p,z,m;
	rep(i,n){
		string s; cin>>s;
		int u=0, b=0, now=0;
		rep(j,s.size()){
			if(s[j]=='(') now++;
			else now--;
			chmax(u,now); chmin(b,now);
		}
		if(now>0) p.PB(MP(b,now));
		else if(now<0) m.PB(MP(b-now,now));
		else z.PB(MP(b,now));
	}
	sort(RALL(p)); sort(ALL(m)); sort(ALL(z));

	int now=0;
	bool flg=true;
	rep(i,p.size()){
		if(now+p[i].first<0) flg=false;
		now+=p[i].second;
		// cerr<<p[i].first<<' ';
	}
	cerr<<endl;
	if(z.size())if(now+z[0].first<0) flg=false;
	// if(z.size())cerr<<z[0].first<<endl;
	rep(i,m.size()){
		now+=m[i].second;
		if(now+m[i].first<0) flg=false;
		// cerr<<m[i].first<<' ';
	}
	cerr<<endl;
	if(now!=0) flg=false;
	if(flg) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}

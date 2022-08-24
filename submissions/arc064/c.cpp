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

double xs,ys,xt,yt;
int n;
double x[1010], y[1010], r[1010];
double d[1010];

signed main(){
	cin>>x[0]>>y[0]>>x[1]>>y[1]; r[0]=r[1]=0; cin>>n;
	rep(i,n){
		cin>>x[i+2]>>y[i+2]>>r[i+2];
	}
	n+=2;
	reps(i,n-1) d[i]=1e15;

	priority_queue<PDD> p; p.push({0,0});
	while(!p.empty()){
		double cost=-p.top().first;
		int cur=p.top().second;
		p.pop();
		if(cost!=d[cur]) continue;
		rep(i,n) if(i!=cur){
			double dist=max(pow(pow(x[i]-x[cur],2)+pow(y[i]-y[cur],2),0.5)-r[i]-r[cur],0.0);
			if(d[i]>d[cur]+dist){
				d[i]=d[cur]+dist; p.push({-d[i],i});
			}
		}
	}
	cout<<d[1]<<endl;
	return 0;
}

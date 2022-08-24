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

signed main(){
	int n,m; cin>>n>>m;
	map<int,int> y;
	rep(i,n){
		int x; cin>>x; y[x]+=1;
	}
	VI cnt(m,0), p(m,0);
	for(auto it: y){
		int x,k; tie(x,k)=it;
		cnt[x%m]+=k;
		p[x%m]+=k/2*2;
	}
	int ans=0;
	rep(i,m){
		int j=(m-i)%m;
		if(i==j){
			ans+=cnt[i]/2;
		}else if(i<j){
			int k=min(cnt[i],cnt[j]);
			ans+=k;
			ans+=min(cnt[i]-k,p[i])/2;
			ans+=min(cnt[j]-k,p[j])/2;
		}
	}
	cout<<ans<<endl;
	return 0;
}

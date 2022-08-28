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
	int n,k; cin>>n>>k;
	VI under(n+5,-1), pile(n+5,0), ans(n+5,-1);
	set<int> s;

	reps(i,n){
		int p; cin>>p;
		auto it=s.upper_bound(p);
		if(it==s.end()){
			pile[p]=1;
			s.insert(p);
		}else{
			under[p]=(*it);
			pile[p]=pile[(*it)]+1;
			s.erase(it);
			s.insert(p);
		}

		if(pile[p]==k){
			s.erase(p);
			rep(j,k){
				ans[p]=i;
				p=under[p];
			}
		}
	}
	
	reps(i,n){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}

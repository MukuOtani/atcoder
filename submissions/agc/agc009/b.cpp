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

int n;
int cost[100005];
VVI g(100005, VI());

void dfs(int s){
	if(cost[s]) return;
	VI candi;
	for(auto v : g[s]){
		dfs(v);
		candi.PB(cost[v]);
	}
	sort(ALL(candi));
	rep(i,candi.size()){
		chmax(cost[s],candi[i]);
		cost[s]++;
	}
	return;
}


signed main(){
	cin>>n;
	reps(i,n-1){
		int a; cin>>a; a--;
		g[a].PB(i);
	}
	CLR(cost);
	dfs(0);
	rep(i,n) cerr<<cost[i]<<' ';
	cerr<<endl;
	cout<<cost[0]<<endl;
	return 0;
}

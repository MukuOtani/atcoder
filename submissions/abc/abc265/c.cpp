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

signed main() {
	int h,w; cin>>h>>w;
	vector<vector<char>> g(h,vector<char>(w));
	vector<vector<bool>> f(h,vector<bool>(w)); 
	rep(i,h)rep(j,w){
		cin>>g[i][j]; f[i][j]=false;
	}
	int x=0, y=0;
	bool move=true;
	
	while(move){
		cerr<< x SP y <<endl;
		char c = g[x][y];
		if(f[x][y]) return cout<<-1<<endl,0;
		else f[x][y] = true;
		if(c=='U'&&x!=0) x--;
		else if(c=='D'&&x!=h-1) x++;
		else if(c=='L'&&y!=0) y--;
		else if(c=='R'&&y!=w-1) y++;
		else move = false;
	}
	cout << x+1 SP y+1 << endl;

	return 0;
}

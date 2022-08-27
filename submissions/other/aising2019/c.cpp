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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const int MAX_N = 400;

int h,w;
vector<string> s;

ll bl=0, wh=0;
bool visited[MAX_N][MAX_N];

void dfs(int x, int y){
	visited[x][y]=true;
	if(s[x][y]=='#') bl++;
	else wh++;

	rep(i,4){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx<0||nx>=h||ny<0||ny>=w) continue;
		if(s[x][y]==s[nx][ny]) continue;
		if(visited[nx][ny]) continue;
		dfs(nx,ny);
	}
}


signed main(){
	cin>>h>>w;
	s.resize(h); rep(i,h) cin>>s[i];
	ll ans=0LL;
	rep(x,h){
		rep(y,w){
			if(s[x][y]=='.') continue;
			if(visited[x][y]) continue;
			bl=wh=0LL;
			dfs(x,y);
			ans+=bl*wh;
		}
	}
	cout<<ans<<endl;
	return 0;
}

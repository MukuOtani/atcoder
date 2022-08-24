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

int n;
int maze[505][505];
int d[505][505];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfs(int sx, int sy){
	queue<PII> q;
	d[sx][sy]--;
	q.push(MP(sx,sy));
	while(q.size()){
		PII p=q.front(); q.pop();
		rep(i,4){
			int nx=p.first+dx[i], ny=p.second+dy[i];
			if(0<=nx&&nx<n&&0<=ny&&ny<n){
				if(maze[nx][ny]){
					if(d[nx][ny]>d[p.first][p.second]+1){
						d[nx][ny]=d[p.first][p.second]+1; q.push(MP(nx,ny));
					}
				}else{
					if(d[nx][ny]>d[p.first][p.second]){
						d[nx][ny]=d[p.first][p.second]; q.push(MP(nx,ny));
					}
				}
			}
		}
	}
}


signed main(){
	cin>>n;
	int ans=0;
	rep(i,n)rep(j,n) d[i][j]=min(min(i,n-1-i),min(j,n-j-1))+1,maze[i][j]=1;
	rep(i,n*n){
		int p; cin>>p; p--;
		int sx=p/n, sy=p%n;
		ans+=d[sx][sy]-1;
		maze[sx][sy]--;
		bfs(sx,sy);
	}
	cout<<ans<<endl;

	return 0;
}

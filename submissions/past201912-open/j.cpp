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


struct edge{
	int to;
	int cost;
};

int h,w;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int value(int y, int x){
	return x+y*w;
}

VI dijkstra(vector<vector<edge>> G, int s){
	VI dist(h*w, INF);
	priority_queue<PII, vector<PII>, greater<PII>> q;
	dist[s]=0; q.push(MP(0,s));
	while(!q.empty()){
		auto p=q.top(); q.pop();
		int cost=p.first, v=p.second;
		if(cost>dist[v]) continue;
		for(auto e: G[v]){
			int to=e.to, to_cost=cost+e.cost;
			if(dist[to]>to_cost){
				dist[to]=to_cost;
				q.push(MP(to_cost,to));
			}
		}
	}
	return dist;
}

signed main(){
	cin>>h>>w;
	VVI d(h, VI(w));
	rep(i,h)rep(j,w) cin>>d[i][j];
	vector<vector<edge>> G(h*w);
	rep(y,h)rep(x,w)rep(k,4){
		int ny=y+dy[k], nx=x+dx[k];
		if(ny<0||ny>=h||nx<0||nx>=w) continue;
		int a=value(y,x), b=value(ny,nx); G[a].PB({b,d[ny][nx]});
	}

	auto d1=dijkstra(G, value(0,w-1));
	auto d2=dijkstra(G, value(h-1,w-1));
	auto d3=dijkstra(G, value(h-1,0));

	int ans=INF;
	rep(y,h)rep(x,w){
		int p=value(y,x);
		int cost=d1[p]+d2[p]+d3[p]-2*d[y][x];
		chmin(ans,cost);
	}
	cout<<ans<<endl;
	return 0;
}

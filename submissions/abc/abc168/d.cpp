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


// queueを用いた場合の実装(経路復元無し)
const int MAX_E = 100100;
const int MAX_V = 100100;
struct edge{int to, cost;};
int V;
vector<edge> G[MAX_V];
int d[MAX_V];
int last[MAX_V];

void dijkstra(int s){
  // greater<PII>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<PII, vector<PII>, greater<PII> > que;
  fill(d,d+V,INF); d[s] = 0; last[s]=0; que.push(MP(0,s));
  while(!que.empty()){
    PII p = que.top(); que.pop();
    int v = p.second;
    if(d[v]<p.first) continue;
    rep(i,G[v].size()){
      edge e = G[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to] = d[v]+e.cost; last[e.to]=v;
        que.push(PII(d[e.to], e.to));
      }
    }
  }
}

signed main(){
	int n,m; cin>>n>>m; V=n;
	rep(i,m){
		int a,b; cin>>a>>b; a--; b--;
		edge e1,e2; e1.to=b, e1.cost=1;
		e2.to=a, e2.cost=1; G[a].PB(e1); G[b].PB(e2);
	}
	dijkstra(0);
	cout<<"Yes"<<endl;
	reps(i,n-1) cout<<last[i]+1<<endl;


	return 0;
}

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
struct edge{ll to, cost;};
int V;
ll d[MAX_V];

void dijkstra(int s ,vector<vector<edge>> &G){
  // greater<PII>を指定することでfirstが小さい順に取り出せるようにする
  priority_queue<PLL, vector<PLL>, greater<PLL>> que;
  fill(d,d+V,LINF); d[s]=0LL; que.push(PLL(0LL,s));
  while(!que.empty()){
    PLL p = que.top(); que.pop();
    ll v = p.second;
    if(d[v]<p.first) continue;
    rep(i,G[v].size()){
      edge e = G[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to] = d[v]+e.cost;
        que.push(PLL(d[e.to], e.to));
      }
    }
  }
}


signed main(){
	int m,s,t; cin>>V>>m>>s>>t; s--; t--;
	ll u[m],v[m],a[m],b[m];
	int n=V;
	rep(i,m){
		cin>>u[i]>>v[i]>>a[i]>>b[i]; u[i]--; v[i]--;
	}
	vector<vector<edge>> G1(V), G2(V);
	rep(i,m){
		edge e1; e1.to=v[i]; e1.cost=a[i];
		edge e2; e2.to=u[i]; e2.cost=a[i];
		G1[u[i]].PB(e1); G1[v[i]].PB(e2);
	}
	dijkstra(s,G1);
	ll da[n]; rep(i,n) da[i]=d[i];
	rep(i,m){
		edge e1; e1.to=v[i]; e1.cost=b[i];
		edge e2; e2.to=u[i]; e2.cost=b[i];
		G2[u[i]].PB(e1); G2[v[i]].PB(e2);
	}
	dijkstra(t,G2);
	ll db[n]; rep(i,n) db[i]=d[i];

	ll cost[n]; rep(i,n) cost[i]=da[i]+db[i];
	ll min_cost=LINF;
	ll ans[n];
	REP(i,n){
		chmin(min_cost,cost[i]);
		ans[i]=(ll)1e15-min_cost;
	}
	rep(i,n) cout<<ans[i]<<endl;
	return 0;
}

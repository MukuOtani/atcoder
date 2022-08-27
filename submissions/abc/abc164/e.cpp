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

ll a[110], b[110], c[110], d[110];

vector<PLL> edge[55];
vector<PLL> edge2[55*2500];

int value(int v, int s){
	return v*2500+s;
}

vector<ll> dijkstra(int s, vector<PLL> *edge){
	priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
	VL dist(55*2500, LINF);
	dist[s] = 0LL;
	pq.push(PLL(dist[s],s));
	while(!pq.empty()){
		auto tmp = pq.top(); pq.pop();
		int from = tmp.second;
		int d = tmp.first;
		if(dist[from]<d) continue;
		for(auto p: edge[from]){
			int to = p.first;
			int d = p.second;
			if(dist[to]>dist[from]+d){
				dist[to] = dist[from]+d;
				pq.push(PLL(dist[to],to));
			}
		}
	}
	return dist;
}


signed main(){
	int n,m,s,u,v; cin>>n>>m>>s;
	rep(i,m){
		cin>>u>>v>>a[i]>>b[i]; u--; v--;
		edge[u].PB(PLL(v,i));
		edge[v].PB(PLL(u,i));
	}
	rep(i,n) cin>>c[i]>>d[i];

	rep(i,n){
		rep(j,2500){
			int to = min(j+c[i],2499LL);
			edge2[value(i,j)].PB(PLL(value(i,to),d[i]));
			for(auto p : edge[i]){
				int to = p.first;
				int edge_ind = p.second;
				if(j<a[edge_ind]) continue;
				edge2[value(i,j)].PB(PLL(value(to,j-a[edge_ind]),b[edge_ind]));
			}
		}
	}
	chmin(s,2499);
	auto dist = dijkstra(value(0,s),edge2);
	rep(i,n){
		if(i==0) continue;
		ll ans = LINF;
		rep(j,2500) chmin(ans,dist[value(i,j)]);
		cout<<ans<<endl;
	}

	return 0;
}

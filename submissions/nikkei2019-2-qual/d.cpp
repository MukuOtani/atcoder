#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <list>
#include <string>
#include <queue>
#include <deque>
#include <tuple>
#include <map>
#include <sstream>
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
#define SORT(c) sort(ALL(x))
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

struct edge{int to; ll cost;};
typedef pair<ll,int> P;

const int MAX_V = 100005;
int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d,d+V,LINF);
  d[s] = 0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    rep(i,G[v].size()){
      edge e = G[v][i];
      if(d[e.to] > d[v]+e.cost){
        d[e.to] = d[v]+e.cost;
        que.push(P(d[e.to],e.to));
      }
    }
  }
}

signed main(){
  int n,m; cin>>n>>m;
	V = n;
	rep(i,m){
		int l,r; ll c; cin>>l>>r>>c; l--; r--;
		G[l].PB({r,c});
	}
	rep(i,n-1){
		G[i+1].PB({i,0L});
	}
	dijkstra(0);
	if(d[n-1]==LINF) cout<<-1<<endl;
	else cout<<d[n-1]<<endl;

  return 0;
}

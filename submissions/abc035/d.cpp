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
#include <queue>
#include <tuple>
#include <map>
#include <set>
#include <sstream>
using namespace std;
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
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
const int INF = 1001001001;
const ll MOD = 1e9+7;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){std::fill((T*)array, (T*)(array+N),val);}


__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

const int MAX_V = 200100;
struct edge{int to, cost;};
int V;
vector<edge> G[MAX_V];
// int d[MAX_V];

VL dijkstra(int s){
	VL d(MAX_V,INF);
  // greater<PII>ÇéwíËÇ∑ÇÈÇ±Ç∆Ç≈firstÇ™è¨Ç≥Ç¢èáÇ…éÊÇËèoÇπÇÈÇÊÇ§Ç…Ç∑ÇÈ
  priority_queue<PLL, vector<PLL>, greater<PLL> > que;
  d[s] = 0; que.push(PII(0,s));
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
	return d;
}

int e,t;
int A[MAX_V];
int a[100100], b[100100], c[100100];
signed main(){
	cin>>V>>e>>t;
	rep(i,V) cin>>A[i];
	rep(i,e){
		cin>>a[i]>>b[i]>>c[i];
		a[i]--; b[i]--;
		edge e; e.to = b[i]; e.cost = c[i];
		G[a[i]].PB(e);
	}
	auto d1 = dijkstra(0);
	rep(i,MAX_V) G[i].clear();
	rep(i,e){
		edge e; e.to = a[i]; e.cost = c[i];
		G[b[i]].PB(e);
	}
	auto d2 = dijkstra(0);
	ll ans = 0;
	rep(i,V){
		if(d1[i]+d2[i]<=t){
			ll dl = (t-d1[i]-d2[i])*A[i];
			chmax(ans,dl);
		}
	}
	cout << ans << endl;

  return 0;
}

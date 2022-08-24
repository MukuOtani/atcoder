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

signed main(){
  int n,m; cin>>n>>m;
	vector<vector<pair<int,ll>>> G;
	rep(i,n){
		vector<pair<int,ll>> v; G.PB(v);
	}
	rep(i,m){
		int a,b; ll c; cin>>a>>b>>c; a--; b--;
		G[a].PB(MP(b,-c));
	}
	vector<ll> d(n,LINF); d[0]=0LL;
	bool negative=false;
	rep(i,n*2){
		rep(v,n){
			if(d[v]==LINF) continue;
			for(auto e: G[v]){
				if(d[e.first]>d[v]+e.second){
					d[e.first]=d[v]+e.second;
					if(e.first==n-1&&i==n*2-1) negative=true;
				}
			}
		}
	}
	if(!negative) cout<<-d[n-1]<<endl;
	else cout<<"inf"<<endl;
  return 0;
}

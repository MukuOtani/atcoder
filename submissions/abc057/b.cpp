#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
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
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

void solve(){
	int n, m; cin >> n >> m;
	VVI G, P;
	rep(i,n){
		VI g; int a,b; cin >> a >> b;
		g.PB(a); g.PB(b);
		G.PB(g);
	}
	rep(i,m){
		VI p; int a,b; cin >> a >> b;
		p.PB(a); p.PB(b);
		P.PB(p);
	}
	VI ans;
	rep(i,n){
		int h = INF; int k = INF;
		int a,b; a=G[i][0]; b=G[i][1];
		rep(j,m){
			int c,d; c=P[j][0]; d=P[j][1];
			int t = abs(c-a)+abs(d-b);
			if(t<h) k=j;
			h = min(h,t);
		}
		ans.PB(k+1);
	}
	rep(i,n){
		cout << ans[i] << endl;
	}

	return;
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}

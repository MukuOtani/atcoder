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
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

ll dfs(int K, const VVI &graph, int now, int from){
	int can_use_color_num;
	if(from==-1){
		can_use_color_num = K-1;
	}else{
		can_use_color_num = K-2;
	}
	if(K<graph[now].size()){
		return 0;
	}else{
		ll case_num = 1;
		for(auto e: graph[now]){
			if(e==from)continue;

			case_num *= can_use_color_num;
			can_use_color_num--;
			case_num %= MOD;
		}
		for(auto e: graph[now]){
			if(e==from) continue;
			case_num *= dfs(K,graph,e,now);
			case_num %= MOD;
		}
		return case_num;
	}
}


int main(){
	int n, k; cin >> n >> k;
	VVI G(n);
	rep(i,n-1){
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].PB(b);
		G[b].PB(a);
	}

	ll answer = k*dfs(k,G,0,-1);
	answer %= MOD;
	cout << answer << endl;

	return 0;
}

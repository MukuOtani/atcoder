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
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

void add(ll &a, ll b){
  a += b;
  if(a>=MOD) a -= MOD;
}

VI col_pl[210000];

signed main(){
	int n; cin>>n;
  VI c(n);
  rep(i,210000) col_pl[i].clear();
  // rep(i,n){
  //   VI col; col_pl.PB(col);
  // }
  rep(i,n){
    cin >> c[i];
    col_pl[c[i]].PB(i);
  }

  ll dp[n+1]; CLR(dp); dp[0]=1;
  reps(i,n){
    add(dp[i],dp[i-1]);
    int color = c[i-1];
    int it = lower_bound(ALL(col_pl[color]), i-1) - col_pl[color].begin();
    if(it>0){
      int j = col_pl[color][it-1];
      if((i-1)-j>1) add(dp[i],dp[j+1]);
    }
  }
  cout << dp[n] << endl;

  return 0;
}

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

const int lim = 100100;
int N,W;


signed main(){
  cin>>N>>W;
  int w[N], v[N];
  rep(i,N) cin>>w[i]>>v[i];
  ll dp[N+1][N+1][N*3+1]; memset(dp,-1,sizeof(dp));
  dp[0][0][0] = 0;
  ll ans = 0;
  rep(i,N){
    rep(j,N){
      int d = w[i]-w[0];
      rep(k,N*3+1){
        if(dp[i][j][k]==-1) continue;
        dp[i+1][j][k] = max(dp[i][j][k], dp[i+1][j][k]);
        ll next_w = j*w[0]+k+w[i];
        if(next_w>W) continue;
        dp[i+1][j+1][k+d] = max(dp[i+1][j+1][k+d],dp[i][j][k]+v[i]);
        ans = max(ans,dp[i+1][j+1][k+d]);
      }
    }
  }
  cout << ans << endl;

  return 0;
}

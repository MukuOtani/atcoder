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


signed main(){
	string S; cin>>S;
  int n = S.size();
  VI dp(n+5);

  rep(i,n+1) dp[i] = 0;
  dp[0] = 0; // 0文字目までは1通り
  dp[1] = 1; // 1文字目までは1通り
  bool flag = false; // 1つ前のiで1文字区切りならfalse
  for(int i=2; i<=n; i++){
    if(S[i-2]!=S[i-1]||flag){ // 1つ前の文字と同じでない、もしくはtrueなら1文字が可能
      if(dp[i]<dp[i-1]+1){ // もし1文字だけの方が場合の数が大きくなるなら採用
        flag = false; dp[i]=dp[i-1]+1;
      }
    }
    if(dp[i]<=dp[i-2]+1){ // 2文字区切りも考える
      flag = true; dp[i]=dp[i-2]+1;
    }
  }
  cout << dp[n] << endl;


  return 0;
}

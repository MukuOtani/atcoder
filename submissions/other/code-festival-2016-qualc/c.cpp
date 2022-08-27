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


signed main(){
  int n; cin>>n;
  int t[n], a[n]; rep(i,n) cin>>t[i]; rep(i,n) cin>>a[i];
  ll dp[n+1]; dp[0] = 1; // dp[i]:i番目の山まで見たときの場合の数
  if(t[n-1]!=a[0]) return cout << 0 << endl, 0;
  if(n==1) return cout << 1 << endl, 0;
  reps(i,n-2){ // i番目(0-indexed)の山について考える
    dp[i] = dp[i-1];
    if(t[i]>t[i-1]&&a[i]>a[i+1]&&t[i]!=a[i]) return cout << 0 << endl, 0;
    if(t[i]==t[i-1]&&a[i]>a[i+1]&&t[i]<a[i]) return cout << 0 << endl, 0;
    if(t[i]>t[i-1]&&a[i]==a[i+1]&&t[i]>a[i]) return cout << 0 << endl, 0;
    if(t[i]==t[i-1]){ // Tの最高が変わらないならあり得るのはt[i]までの全通り
      if(a[i]>a[i+1]) continue; // Aが更新されてたら一通りに収束
      dp[i] *= min(t[i],a[i]); // 両方更新されないなら小さい方の数の通りがある
      dp[i] %= MOD;
    } // Tの最高が更新されてたら一通りだから特に何もしない
  }
  // 最後の山(n-1番目)についてはそのひとつ前のdpまでと場合の数は変わらないのでn-2までで十分
  rep(i,n-2) cerr << dp[i] << ' ';
  cerr << endl;
  cout << dp[n-2] << endl;
  return 0;
}

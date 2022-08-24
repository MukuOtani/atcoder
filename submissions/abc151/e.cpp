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
#define chmax(a, b) a = (((a)<(b))?(b):(a))
#define chmin(a, b) a = (((a)<(b))?(a):(b))

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

class CompareDist
{
public:
    bool operator()(PLL n1,PLL n2) {
				if(n1.first!=n2.first) return n1.first<n2.first;
				else return n1.second<n2.second;
    }
};

#define lengthof(x) (sizeof(x) / sizeof(*(x)))


__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}



signed main(){
  int n,k; cin>>n>>k;
  VL a(n),memo(n);
  rep(i,n){
    cin>>a[i]; memo[i]=0;
  }


  // int idx;
  // if(k<=n-k) idx=n-k-1;
  // else idx = n-k+1;
  // memo[idx] = 1;
  //

  memo[n-k] = 1;
  for(int i=n-k-1; i>=0; i--){
    memo[i] = (memo[i+1]*(n-1-i))%MOD;
    memo[i] *= mpow(n-i-k,MOD-2);
    memo[i] = (memo[i]+MOD)%MOD;
  }

  // // memo[n-k-1] = 1;
  // for(int i=idx+1; i<=n-1; i++){
  //   memo[i] = (memo[i-1]*i)%MOD;
  //   memo[i] *= mpow(i-(k-1),MOD-2);
  //   memo[i] = (memo[i]+MOD)%MOD;
  // }
  // rep(i,n){
  //   cerr << memo[i] << endl;
  // }

  ll big = 0, small = 0;
  sort(ALL(a));
  rep(i,n-k+1){
    small += (a[i]*memo[i])%MOD;
    small %= MOD;
  }
  sort(RALL(a));
  rep(i,n-k+1){
    big += (a[i]*memo[i])%MOD;
    big %= MOD;
  }
  //
  //
  //
  // rep(i,n-k+1){
  //   big += (a[n-1-i]*memo[n-1-i])%MOD;
  //   big %= MOD;
  //   small += (a[i]*memo[n-1-i])%MOD;
  //   small %= MOD;
  //   cerr << big SP small << endl;
  // }
  ll ans = (big-small+2*MOD)%MOD;
  cout << ans << endl;


  return 0;
}

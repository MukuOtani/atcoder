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
  int n; cin>>n;
  VI a(n); rep(i,n) cin>>a[i];
  sort(ALL(a));
  int cnt = 1;
  int ans = 0;
  reps(i,n-1){
    if(a[i-1]==a[i]) cnt++;
    else{
      if(a[i-1]<=cnt) ans += cnt-a[i-1];
      else ans += cnt;
      cnt = 1;
    }
  }
  if(a[n-1]!=cnt){
    if(a[n-1]<cnt) ans += cnt-a[n-1];
    else ans += cnt;
  }
  cout << ans << endl;

  return 0;
}

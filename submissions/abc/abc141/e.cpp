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

struct RollingHash{
  static const int base1 = 1007, base2 = 2009;
  static const int mod1 = 1000000007, mod2 = 1000000009;
  vector<ll> hash1, hash2, power1, power2;

  RollingHash(const string &s){
    int n = (int)s.size();
    hash1.assign(n+1,0);
    hash2.assign(n+1,0);
    power1.assign(n+1,1);
    power2.assign(n+1,1);
    rep(i,n){
      hash1[i+1] = (hash1[i]*base1+s[i])%mod1;
      hash2[i+1] = (hash2[i]*base2+s[i])%mod2;
      power1[i+1] = (power1[i]*base1)%mod1;
      power2[i+1] = (power2[i]*base2)%mod2;
    }
  }
  pair<ll, ll> get(int l, int r){
    ll res1 = hash1[r]-hash1[l]*power1[r-l]%mod1;
    if(res1<0) res1+=mod1;
    ll res2 = hash2[r]-hash2[l]*power2[r-l]%mod2;
    if(res2<0) res2+=mod2;
    return {res1, res2};
  }
  int getLCP(int a, int b){
    int len = min((int)hash1.size()-a, (int)hash1.size()-b);
    int low = 0, high = len;
    while(high-low>1){
      int mid = (low+high)>>1;
      if(get(a,a+mid)!=get(b,b+mid)) high=mid;
      else low = mid;
    }
    return low;
  }
};

signed main(){
  int n; cin>>n;
  string s; cin>>s;
  RollingHash rh(s);

  int res = 0;
  rep(i,n){
    for(int j=i+1; j<n; j++){
      int lcp = rh.getLCP(i,j);
      lcp = min(lcp,j-i);
      res = max(res, lcp);
    }
  }
  cout << res << endl;
  return 0;
}

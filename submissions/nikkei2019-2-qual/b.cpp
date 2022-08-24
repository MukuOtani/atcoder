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
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
const int INF = 1001001001;
const ll MOD = 998244353;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

// ll lpow(ll a, ll b){
//   if(b==0) return 1;
//   else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
//   else return lpow(a,b-1) * a;
// }


signed main(){
	int n; cin>>n;
  VI d(n); rep(i,n) cin>>d[i];
  if(d[0]!=0) return cout<<'0'<<endl,0;
  sort(ALL(d));
  ll cnt0=1, cnt1=1, ans=1;

  rep(i,n-1){
    // cerr << i SP d[i] SP cnt0 SP cnt1 SP ans<< endl;
    if(i!=0&&d[i]==0) return cout<<'0'<<endl,0;
    if(d[i]!=d[i+1]){
      if(d[i]+1!=d[i+1]) return cout<<'0'<<endl,0;
      ans *= cnt0;
      ans %= MOD;
      cnt0 = cnt1; cnt1 = 1;
    }else{
      ans *= cnt0;
      ans %= MOD;
      cnt1++;
    }
  }
  ans *= cnt0;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}

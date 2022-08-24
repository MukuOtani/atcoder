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
#include <cstdlib>
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


__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

signed main(){
	ll t1, t2, a1, a2, b1, b2;
  cin>>t1>>t2>>a1>>a2>>b1>>b2;

  ll fa = t1*a1, fb = t1*b1, fd = llabs(fa-fb);
  cerr << fa SP fb SP fd << endl;
  ll sa = t2*a2, sb = t2*b2, sd = llabs(sa-sb);
  cerr << sa SP sb SP sd << endl;
  ll sum_a = fa+sa, sum_b = fb+sb, d = llabs(sum_a-sum_b);
  ll u = (fa-fb)/fd;
  ll v = 0;
  if(d!=0) v = (sum_a-sum_b)/d;

  if(u*v>0) return cout << 0 << endl,0;
  else if(d==0) return cout << "infinity" << endl,0;
  // if((fa-fb)*(sum_a-sum_b)<0){
  else{
    cerr << sum_a SP sum_b << endl;
    cerr << d SP fd << endl;
    ll tmp = fd/d;
    ll cnt = 0;
    if(tmp*d==fd) cnt++;
    ll ans = 1+tmp*2-cnt;
    cout << ans << endl;
  }

  return 0;
}

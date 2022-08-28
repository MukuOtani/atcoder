#include <bits/stdc++.h>
using namespace std;
#define MOD (long long int)(998244353)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const long double PI  = acos(-1.0L);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<double,double> PDD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
#define chmax(a,b) a = (((a)<(b))?(b):(a))
#define chmin(a,b) a = (((a)>(b))?(b):(a))

template <long long mod>
struct modint {
  modint(ll v = 0) : value(normalize(v)) {}
  ll val() const { return value; }
  void normalize() { value = normalize(value); }
  ll normalize(ll v) {
    if (v <= mod && v >= -mod) {
      if (v < 0) v += mod;
      return v;
    }
    if (v > 0 && v < 2 * mod) {
      v -= mod;
      return v;
    }
    if (v < 0 && v > -2 * mod) {
      v += 2 * mod;
      return v;
    }
    v %= mod;
    if (v < 0) v += mod;
    return v;
  }
  modint<mod>& operator=(ll v) {
    value = normalize(v);
    return *this;
  }
  bool operator==(const modint& o) const { return value == o.val(); }
  bool operator!=(const modint& o) const { return value != o.val(); }
  const modint& operator+() const { return *this; }
  const modint& operator-() const { return value ? mod - value : 0; }
  const modint operator+(const modint& o) const {
    return value + o.val();
  }
  modint& operator+=(const modint& o) {
    value += o.val();
    if (value >= mod) value -= mod;
    return *this;
  }
  const modint operator-(const modint& o) const {
    return value - o.val();
  }
  modint& operator-=(const modint& o) {
    value -= o.val();
    if (value < 0) value += mod;
    return *this;
  }
  const modint operator*(const modint& o) const {
    return (value * o.val()) % mod;
  }
  modint& operator*=(const modint& o) {
    value *= o.val();
    value %= mod;
    return *this;
  }
  const modint operator/(const modint& o) const { return operator*(o.inv()); }
  modint& operator/=(const modint& o) { return operator*=(o.inv()); }
  const modint pow(ll n) const {
    modint ans = 1, x(value);
    while (n > 0) {
      if (n & 1) ans *= x;
      x *= x;
      n >>= 1;
    }
    return ans;
  }
  const modint inv() const {
    ll a = value, b = mod, u = 1, v = 0;
    while (b) {
      ll t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return u;
  }
  friend ostream& operator<<(ostream& os, const modint& x) {
    return os << x.val();
  }
  template <typename T>
  friend modint operator+(T t, const modint& o) {
    return o + t;
  }
  template <typename T>
  friend modint operator-(T t, const modint& o) {
    return -o + t;
  }
  template <typename T>
  friend modint operator*(T t, const modint& o) {
    return o * t;
  }
  template <typename T>
  friend modint operator/(T t, const modint& o) {
    return o.inv() * t;
  }

 private:
  ll value;
};
using modint1000000007 = modint<1000000007>;
using modint998244353 = modint<998244353>;
using mint = modint998244353;

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}


signed main(){
	ll n; cin>>n;
	VI a(n); reps(i,n-1) cin>>a[i];
	vector<mint> dp(n+1,0), dps(n+2,0);

	REPS(i,n-1){
		dp[i] = (dps[i+1]-dps[i+a[i]+1]+a[i]+1)/a[i];
		dps[i] = dps[i+1]+dp[i];
	}
	
	cout<< dp[1].val() <<endl;

	return 0;
}

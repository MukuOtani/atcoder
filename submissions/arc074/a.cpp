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
#include <string>
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
const long double PI  = acos(-1.0L);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
#define chmax(a,b) a = (((a)<(b))?(b):(a))
#define chmin(a,b) a = (((a)>(b))?(b):(a))

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

// a‚Ìpæ‚ð‹‚ß‚éŠÖ”
ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==0){
		ll memo = mpow(a,b/2);
		return memo*memo%MOD;
	}else{
		return mpow(a,b-1)*a%MOD;
	}
}

// aCb‚ð‹‚ß‚éŠÖ”
ll mod_combination(int a, int b){
  if(b>a-b) return mod_combination(a,a-b);
  ll ansMul = 1, ansDiv = 1;
  rep(i, b) {
    ansMul *= (a-i); ansDiv *= (i+1);
    ansMul %= MOD; ansDiv %= MOD;
  }
  ll ans = ansMul*mpow(ansDiv, MOD-2)%MOD;
  return ans;
}

signed main(){
	ll h,w; cin>>h>>w;
	ll ans = INF;
	reps(i,h){
		ll sa = i*w;
		ll yoko = w/2;
		ll sb = (h-i)*yoko, sc = (h-i)*(w-yoko);
		// cerr << sa SP sb SP sc << endl;
		chmin(ans,max(abs(sa-sb),max(abs(sb-sc),abs(sc-sa))));
		ll tate = (h-i)/2;
		sb = tate*w, sc = (h-i-tate)*w;
		chmin(ans,max(abs(sa-sb),max(abs(sb-sc),abs(sc-sa))));
	}
	reps(i,w){
		ll sa = i*h;
		ll yoko = h/2;
		ll sb = (w-i)*yoko, sc = (w-i)*(h-yoko);
		// cerr << sa SP sb SP sc << endl;
		chmin(ans,max(abs(sa-sb),max(abs(sb-sc),abs(sc-sa))));
		ll tate = (w-i)/2;
		sb = tate*h, sc = (w-i-tate)*h;
		chmin(ans,max(abs(sa-sb),max(abs(sb-sc),abs(sc-sa))));
	}
	cout<<ans<<endl;
  return 0;
}

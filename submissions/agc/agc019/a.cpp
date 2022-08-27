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
  ll c[4]; double n; cin>>c[0]>>c[1]>>c[2]>>c[3]>>n;
  vector<pair<ll,ll> > costs;
  rep(i,4) costs.PB({c[i]*pow(2,(3-i)),i});
  sort(ALL(costs));
  rep(i,4) cerr<<costs[i].first SP costs[i].second<<endl;
  ll ans = 0;
  // while(n>pow(2,costs[now].second)*0.25){
  rep(now,4){
    ll g = (ll)((1.0*n)/(pow(2,costs[now].second)*0.25));
    cerr << "now" SP costs[now].second << endl;
    cerr << g << endl;
    ans += c[costs[now].second] * g;
    n -= 1.0*g*(pow(2,costs[now].second)*0.25);
    cerr << "last" SP n << endl;
  }
  cout << ans << endl;


  return 0;
}

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
typedef vector<ll> VL;
#define chmax(a, b) a = (((a)<(b))?(b):(a))

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
  ll n; cin>>n;
  VL a(n); rep(i,n) cin>>a[i];
  ll ans = 0;
  // int idx = -1;
  // int last = 0;
  pair<ll,ll> tmp;
  tmp = MP(-1,0);
  rep(i,n){
    ll now = a[i];
    if(now==0){
      tmp.first = i; tmp.second = 0;
      continue;
    }
    // if(last){
    //   ans+=(now+1)/2;
    //   last = now%2;
    // else ans += now/2;
    if(tmp.first+1==i) now+=tmp.second;
    ans += now/2;
    tmp.second = now%2;
    // if(now%2) tmp.second = 1-tmp.second;
    // tmp.second = (now%2)-(tmp.second%2);
    tmp.first = i;
    cerr << i SP tmp.second SP ans << endl;
    // ans += a[i]/2;
    // a[i] %= 2;
  }
  // rep(i,n-1){
  //   if(a[i]==1&&a[i+1]==1){
  //     ans++; a[i+1]--;
  //   }
  // }
  cout << ans << endl;

  return 0;
}

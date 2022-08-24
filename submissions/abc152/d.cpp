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
  ll ans = 0;
  reps(i,n){
    // cerr << i-1 SP ans << endl;
    ostringstream oss;
    oss << i;
    string s = oss.str();
    int m = s.size();
    if(s[0]==s[m-1]){
      ans++;
    }

    int f = s[0]-'0';
    int l = s[m-1]-'0';
    if(l==0) continue;

    if(l*10+f>i) continue;
    else ans+=2;

    if(l*100+f>i) continue;
    else ans += min(((i-l*100-f)/10+1),10)*2;

    if(l*1000+f>i) continue;
    else ans += min(((i-l*1000-f)/10+1),100)*2;

    if(l*10000+f>i) continue;
    else ans += min(((i-l*10000-f)/10+1),1000)*2;

    if(l*100000+f>i) continue;
    else ans += min(((i-l*100000-f)/10+1),10000)*2;

  }
  cout<<ans<<endl;

  return 0;
}

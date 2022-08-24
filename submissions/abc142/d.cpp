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

bool IsPrime(ll num){
    if(num < 2) return false;
    else if(num == 2) return true;
    else if(num % 2 == 0) return false; // ‹ô”‚Í‚ ‚ç‚©‚¶‚ßœ‚­

    double sqrtNum = sqrt(num);
    for(ll i = 3; i <= sqrtNum; i += 2){
        if(num%i==0){
            // ‘f”‚Å‚Í‚È‚¢
            return false;
        }
    }
    // ‘f”‚Å‚ ‚é
    return true;
}

signed main(){
  ll a,b; cin>>a>>b;
  ll ans = 1;
  priority_queue<ll> x,y;

  reps(i,pow(a,0.5)){
    if(a%i!=0) continue;
    if(IsPrime(i)) x.push(i);
    if(i==a/i) continue;
    if(IsPrime(a/i)) x.push(a/i);
  }
  reps(i,pow(b,0.5)){
    if(b%i!=0) continue;
    if(IsPrime(i)) y.push(i);
    if(i==b/i) continue;
    if(IsPrime(b/i)) y.push(b/i);
  }
  while((!x.empty())&&(!y.empty())){
    ll s = x.top(), t = y.top();
    if(s==t){
      x.pop(); y.pop(); ans++;
      // cerr << s << endl;
    }else if(s>t){
      x.pop();
    }else{
      y.pop();
    }
  }
  cout << ans << endl;


  return 0;
}

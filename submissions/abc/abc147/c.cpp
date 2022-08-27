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

int n;
vector<vector<PII> > v;

bool judge(int bit){
  rep(i,n){
    if(!(bit&(1<<i))) continue;
    for(PII xy : v[i]){
      int x = xy.first, y = xy.second;
      // if(y==1 &&!(bit&(1<<x))) return false;
      // if(y==0 && (bit&(1<<x))) return false;
      if(((bit>>x)&1)^y) return false;
    }
  }
  return true;
}

signed main(){
  cin>>n;
  v.resize(n);
  rep(i,n){
    int a; cin>>a;
    v[i].resize(a);
    rep(j,a){
      cin >> v[i][j].first >> v[i][j].second;
      v[i][j].first--;
    }
  }

  int res = 0;
  rep(bit,1<<n){
    if(judge(bit)){
      int count = 0;
      rep(i,n){
        if(bit&(1<<i)) count++;
      }
      res = max(res,count);
    }
  }
  cout << res << endl;

  return 0;
}

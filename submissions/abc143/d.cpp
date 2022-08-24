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

#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))

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
    else if(num % 2 == 0) return false; // �����͂��炩���ߏ���

    double sqrtNum = sqrt(num);
    for(ll i = 3; i <= sqrtNum; i += 2){
        if(num%i==0){
            // �f���ł͂Ȃ�
            return false;
        }
    }
    // �f���ł���
    return true;
}

signed main(){
  int n; cin>>n;
  VI v(n); rep(i,n) cin>>v[i]; sort(ALL(v));
  ll ans = 0;
  for(int m=n-1;m>=0;m--){
    for(int l=m-1;l>=0;l--){
      auto itr = lower_bound(ALL(v), v[m]+v[l]);
      int ng = distance(itr, v.end());
      ans += (n-1-m) - ng;
    }
  }
  cout << ans << endl;

  return 0;
}

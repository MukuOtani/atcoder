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
  int a,b; cin>>a>>b;
  string s[100];
  rep(i,100){
    rep(j,100){
      if(i<50) s[i].PB('.');
      else s[i].PB('#');
    }
  }

  int cnt = 0;
  for(int i=0; i<50; i+=2){
    if(cnt==b-1) break;
    for(int j=0; j<100; j+=2){
      if(cnt==b-1) break;
      s[i][j] = '#'; cnt++;
    }
  }
  cnt = 0;
  for(int i=51; i<100; i+=2){
    if(cnt==a-1) break;
    for(int j=0; j<100; j+=2){
      if(cnt==a-1) break;
      s[i][j] = '.'; cnt++;
    }
  }

  cout << 100 SP 100 << endl;
  rep(i,100) cout << s[i] << endl;

  return 0;
}

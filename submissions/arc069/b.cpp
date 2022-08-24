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

int n;

char next_animal(string &a, string &b, int i){
  if(b[i]=='S'){
    if(b[i-1]=='S'){
      if(a[i%n]=='o') return 'S';
      else return 'W';
    }else{
      if(a[i%n]=='o') return 'W';
      else return 'S';
    }
  }else{
    if(b[i-1]=='S'){
      if(a[i%n]=='o') return 'W';
      else return 'S';
    }else{
      if(a[i%n]=='o') return 'S';
      else return 'W';
    }
  }
}

bool res(string &a, int m){
  rep(i,m){
    if(a[i]!=a[n+i]) return false;
  }
  return true;
}

signed main(){
  cin>>n;
  string s; cin>>s;
  int ans = 0;

  string a,b,c,d;
  a = "SS", b = "SW", c = "WS", d = "WW";
  reps(i,n+5){
    a.PB(next_animal(s,a,i));
    b.PB(next_animal(s,b,i));
    c.PB(next_animal(s,c,i));
    d.PB(next_animal(s,d,i));
  }
  if(res(a,5)) rep(i,n) cout<<a[i];
  else if(res(b,5)) rep(i,n) cout<<b[i];
  else if(res(c,5)) rep(i,n) cout<<c[i];
  else if(res(d,5)) rep(i,n) cout<<d[i];
  else cout << -1;

  cout << endl;

  return 0;
}

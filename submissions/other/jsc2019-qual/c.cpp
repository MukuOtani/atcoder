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

signed main(){
  int n; cin>>n;
  string s; cin>>s;

  string walls = "";
  walls += 'L';
  reps(i,2*n-1){
    if(s[i-1]==s[i]){
      if(walls[i-1]=='L') walls+='R';
      else walls += 'L';
    }else{
      walls += walls[i-1];
    }
  }
  int wall[2*n][2];
  wall[0][0] = 1; wall[0][1] = 0;
  reps(i,2*n-1){
    wall[i][0] = wall[i-1][0];
    wall[i][1] = wall[i-1][1];
    if(walls[i]=='L') wall[i][0]++;
    else wall[i][1]++;
  }
  rep(i,2*n){
    cerr << s[i] SP walls[i] SP wall[i][0] SP wall[i][1] << endl;
  }
  // cerr << wall[2*n-1][0] SP wall[2*n-1][1] << endl;
  if(wall[2*n-1][0]!=wall[2*n-1][1]){
    cout << 0 << endl;
    return 0;
  }
  if(s[0]=='W' || s[2*n-1]=='W'){
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  reps(i,2*n-1){
    if(walls[i]=='R'){
      ans *= wall[i][0]-wall[i][1]+1;
      ans %= MOD;
    }
  }
  vector<ll> kaijo(n+1);
  kaijo[0] = kaijo[1] = 1;
  reps(i,n) kaijo[i] = (kaijo[i-1]*i)%MOD;
  cerr << ans SP kaijo[n] << endl;
  ans *= kaijo[n];
  ans %= MOD;

  cout << ans << endl;

  return 0;
}

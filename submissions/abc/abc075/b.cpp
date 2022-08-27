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
  int h,w; cin>>h>>w;
  string s[h],ans[h]; rep(i,h) cin>>s[i], ans[i]=s[i];
  int dx[8]={1,1,0,-1,-1,-1,0,1}, dy[8]={0,1,1,1,0,-1,-1,-1};
  int cnt=0;
  rep(i,h){
    rep(j,w){
      cnt = 0;
      if(ans[i][j]=='#') continue;
      rep(d,8){
        if(i+dx[d]<0||i+dx[d]>=h||j+dy[d]<0||j+dy[d]>=w) continue;
        if(s[i+dx[d]][j+dy[d]]=='#') cnt++;
      }
      ans[i][j] = '0'+cnt;
    }
  }
  rep(i,h){
    rep(j,w) cout<<ans[i][j];
    cout<<endl;
  }


  return 0;
}

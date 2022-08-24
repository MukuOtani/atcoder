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
  string s; cin>>s;
  int x,y; cin>>x>>y;
  int n = s.size();
  VI a, b; // a:x方向に一度に進む回数 b:y方向に一度に進む回数
  int check = 1; // 1ならx方向に進む 0ならy方向に進む
  int cnt = 0;
  if(n==1&&s[0]=='T'){ //入力がTのみだったらさっさと処理(testcaseには含まれていない)
    if(x==0&&y==0) return cout<<"Yes"<<endl, 0;
    else return cout<<"No"<<endl, 0;
  }

  // x,yのabsはsのabs以下なので配列外アクセスは生じないのでは？

  rep(i,n){
    if(s[i]=='F'){
      cnt++;
    }else{
      if(check) a.PB(cnt); else b.PB(cnt);
      check++; check%=2; cnt=0;
    }
  }
  if(s[n-1]=='F'){
    if(check) a.PB(cnt); else b.PB(cnt);
  }
  int m = 2*n+1;
  // ここからDPでi回目にj+nの座標にいられるかboolで決めていく
  // まずはxについて
  int u = a.size();
  if(u==0){
    if(x) return cout<<"No"<<endl, 0;
  }else{
    bool dpx[u][m];
    rep(j,m) dpx[0][j] = false;
    dpx[0][a[0]+n] = true;
    reps(i,u-1){
      rep(j,m) dpx[i][j] = false;
      rep(j,m){
        if(dpx[i-1][j]){
          dpx[i][j+a[i]]=true; dpx[i][j-a[i]]=true;
        }
      }
    }
    if(!dpx[u-1][x+n]) return cout<<"No"<<endl, 0;
  }


  // 次にyについて
  u = b.size();
  if(u==0){
    if(y) return cout<<"No"<<endl, 0;
  }else{
    bool dpy[u][m];
    rep(j,m) dpy[0][j] = false;
    dpy[0][b[0]+n] = true; dpy[0][-b[0]+n] = true;
    reps(i,u-1){
      rep(j,m) dpy[i][j] = false;
      rep(j,m){
        if(dpy[i-1][j]){
          dpy[i][j+b[i]]=true; dpy[i][j-b[i]]=true;
        }
      }
    }
    if(!dpy[u-1][y+n]) return cout<<"No"<<endl, 0;
  }

  cout << "Yes" << endl;


  return 0;
}

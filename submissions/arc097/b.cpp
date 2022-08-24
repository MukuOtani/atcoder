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

struct UnionFind{
  VI par; // par[i]:iの親の番号
  UnionFind(int n) : par(n){ // 最初は全てが根であるとして初期化
    rep(i,n) par[i] = i;
  }
  int root(int x){
    if(par[x]==x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y){
    int rx = root(x); int ry = root(y);
    if(rx==ry) return;
    par[rx] = ry;
  }
  bool same(int x, int y){
    int rx = root(x); int ry = root(y);
    return rx==ry;
  }
};

signed main(){
  int n,m; cin>>n>>m;
  int p[n];
  UnionFind tree(n);

  rep(i,n){cin>>p[i]; p[i]--;}

  rep(i,m){
    int x,y; cin>>x>>y; x--; y--;
    tree.unite(x,y);
  }
  cerr << endl;
  // ここまで入力処理

  int ans = 0;
  rep(i,n){ // 与えられたp_iについて順々にp_iとiが連結か調べていく
    if(tree.same(i,p[i])) ans++; // 連結ならansに加える
    cerr << tree.same(i,p[i]) << ' '; // 連結判断のデバック 連結(移動可能)なら1
  }
  cerr << endl;
  cout << ans << endl;

  return 0;
}

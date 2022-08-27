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

int n;
int h[100100], s[100100];

bool check(ll x){ // x[m]までに割るのは可能か
  int t[n];
  rep(i,n){
    if(x-h[i]<0) return false;
    t[i] = min((ll)100100, (x-h[i])/s[i]); // 制限時間を考える
  }
  sort(t,t+n);
  rep(i,n) if(t[i]<i) return false; // 制限時間の短い順に割る
  return true;
}

signed main(){
	cin>>n;
  rep(i,n) cin>>h[i]>>s[i];
  ll l=0, r=1e16;
  while(r-l>1){ // 可能(true)な最小値を求めたい
    ll m=(r+l)/2; // 二分探索は真ん中の値をとる
    if(check(m)) r=m; // 可能なら最大値に代入
    else l=m; // だめなら下限値に
  }
  if(!check(r)) r=l;
  cout << r << endl;
	return 0;
}

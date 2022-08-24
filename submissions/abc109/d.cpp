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

int h,w;
int A[505][505];
VVI B;
VVI Y1,Y2;

signed main(){
	cin>>h>>w;
  rep(i,h){
    rep(j,w) cin>>A[i][j];
  }
  rep(i,h){
    if(!(i%2)){
      rep(j,w){
        VI b;
        b.PB(A[i][j]); b.PB(i); b.PB(j);
        B.PB(b);
      }
    }else{
      REP(j,w){
        VI b;
        b.PB(A[i][j]); b.PB(i); b.PB(j);
        B.PB(b);
      }
    }
  }
  rep(i,B.size()-1){
    if(!B[i][0]) continue;
    if(B[i][0]%2==1){
      B[i][0]--; B[i+1][0]++;
      VI X1, X2;
      X1.PB(B[i][1]+1); X1.PB(B[i][2]+1); X2.PB(B[i+1][1]+1); X2.PB(B[i+1][2]+1);
      Y1.PB(X1); Y2.PB(X2);
    }
  }

  cout << Y1.size() << endl;
  rep(i,Y1.size()){
    cout << Y1[i][0] SP Y1[i][1] SP Y2[i][0] SP Y2[i][1] << endl;
  }

  return 0;
}

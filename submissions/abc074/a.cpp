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

signed main(){
  double a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
  double d_m = e/(e+100);
  double ans = 0;
  int water=a, sugar=0;
  for(int i=0; i<=30; i++){
    for(int j=0; i+j<=30; j++){
      double w = (a*i+b*j)*100;
      if(w>f||w==0) continue;

      for(int k=0; k<=3000; k++){
        for(int l=0; k+l<=3000; l++){
          double s = c*l+d*k;
          double n = s/(s+w);
          if(w+s>f||n>d_m) continue;

          if(ans<=n){
            ans = n;
            water=w; sugar=s;
          }
        }
      }
    }
  }
  cout << water+sugar SP sugar << endl;
  return 0;
}

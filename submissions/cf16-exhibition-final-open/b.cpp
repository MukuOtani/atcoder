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
  double x[3], y[3]; double l[3], sum=0;
  rep(i,3) cin>>x[i]>>y[i];
  rep(i,3) l[i] = pow((x[(i+1)%3]-x[i]),2)+pow((y[(i+1)%3]-y[i]),2), l[i] = pow(l[i],0.5), sum+=l[i], cerr<<l[i] << ' ';
  cerr << endl;
  double s = 1.0/2.0*((x[1]-x[0])*(y[2]-y[0])-(x[2]-x[0])*(y[1]-y[0]));
  if(s<0) s = -s;
  cerr << s << endl;
  double r = 2*s/sum;
  cerr << r << endl;
  sort(l,l+3);
  double ans = r*l[2]/(2*r+l[2]);
  cout << ans << endl;
  return 0;
}

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
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
const int INF = 1001001001;
const ll MOD = 998244353;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

// ll lpow(ll a, ll b){
//   if(b==0) return 1;
//   else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
//   else return lpow(a,b-1) * a;
// }




signed main(){
	int n; cin>>n;
	vector<double> x(n), y(n);
	rep(i,n) cin>>x[i]>>y[i];

	double wa = 0, sum = 0;
	// double m = 1;
	// reps(i,n-1){
	// 	m *= i;
	// }
	// cerr << 'm' SP m << endl;
	rep(i,n){
		rep(j,i){
			wa += pow(x[i]-x[j],2);
			wa += pow(y[i]-y[j],2);
			wa = pow(wa,0.5);
			cerr << wa << endl;
			sum += wa*2/n;
			cerr << sum << endl;
			wa = 0;
		}
	}
	// sum = sum/(m*n);
	cout << sum << endl;

  return 0;
}

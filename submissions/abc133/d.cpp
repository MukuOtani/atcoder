#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
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
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main(){
	int n; cin >> n;
	vector<ll> A;
	rep(i,n){
		ll a; cin >> a;
		A.push_back(a);
	}
	// ll ans[n];
	// rep(i,n) ans[i]=0;
	// rep(i,n){
	// 	ll r = A[i];
	// 	rep(j,n){
	// 		ans[min(i+j, (i+j)%n)] += r;
	// 		r *= -1;
	// 	}
	// }
	// cout << ans[n-1] << ' ';
	// rep(i,n-1){
	// 	cout << ans[i] << ' ';
	// }
	ll ans = 0;
	int flp = 1;
	rep(i,n){
		ans += A[i]*flp;
		flp *= -1;
	}
	rep(i,n){
		cout << ans << ' ';
		ans *= -1;
		ans += 2*A[i];
	}


	cout << endl;
	return 0;
}

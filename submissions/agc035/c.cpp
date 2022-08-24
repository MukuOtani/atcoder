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
#define SP << " " <<
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

void solve(){
	int n; cin >> n;
	if(__builtin_popcount(n)==1){
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	cout << 1+n SP 2+n << endl;
	cout << 2+n SP 3+n << endl;
	cout << 3+n SP 1 << endl;
	cout << 1 SP 2 << endl;
	cout << 2 SP 3 << endl;

	FOR(i,4,n){
		if(__builtin_ffs(i)!=1){
			cout << 1 SP i << endl;
			cout << i SP i+1 << endl;
			cout << 1 SP i+1+n << endl;
			cout << i+1+n SP i+n << endl;
		}else{
			continue;
		}
	}

	if(__builtin_ffs(n)!=1){
		int tmp = 2;
		while(n > tmp*2) tmp *= 2;
		cout << n SP tmp << endl;
		cout << n+n SP n-tmp+1+n << endl;
	}

	return;
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}

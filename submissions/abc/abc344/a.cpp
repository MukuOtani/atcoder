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
#include <set>
#include <sstream>
#include <bitset>
#include <string>
using namespace std;
#define MOD (long long int)(998244353)
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n) for (int i = 1; i <= (int)(n); i++)
#define REP(i, n) for (int i = n - 1; i >= 0; i--)
#define REPS(i, n) for (int i = n; i > 0; i--)
#define FOR(i, a, b) for (int i = a; i < (int)(b); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define CLR(a) memset((a), 0, sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const double EPS = 1e-10;
const long double PI = acos(-1.0L);
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
#define chmax(a, b) a = (((a) < (b)) ? (b) : (a))
#define chmin(a, b) a = (((a) > (b)) ? (b) : (a))

__attribute__((constructor)) void initial()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

signed main()
{
	string s; cin>>s;
	bool ok = true;
	rep(i,s.size()){
		if(s[i]=='|'){
			ok = !ok;
		}else if(ok){
			cout<<s[i];
		}
	}
	cout<<endl;
	return 0;
}

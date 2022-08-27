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

//
// int combi(int n, int k) {
//   if (n == k || k == 0)
//     return 1;
//   else {
//     return combi(n - 1, k - 1) + combi(n - 1, k);
//   }
// }

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}


signed main(){
	int n; cin>>n;
  // vector<vector<char> > S;
	vector<string> S;
	rep(i,n){
		string s; cin >> s;
		// vector<char> C;
		// rep(j,10){
		// 	C.PB(s[j]);
		// }
		// sort(ALL(C));
		// S.PB(C);
		sort(ALL(s));
		S.PB(s);
		// cout << s << endl;
	}
	sort(ALL(S));
	// rep(i,n){
	// 	cout << S[i] << endl;
	// }
	// cout << endl;
	ll ans = 0;
	VI cnt;
	ll r = 1;
	rep(i,n-1){
		if(S[i]==S[i+1]) r++;
		else{
			if(r!=1) ans+=(r*(r-1)/2);
			r = 1;
		}
		// cout << r << " ";
	}
	ans+=(r*(r-1)/2);
	// cout << endl;
	cout << ans << endl;
	return 0;
}

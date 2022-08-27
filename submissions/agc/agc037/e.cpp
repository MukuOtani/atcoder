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
	int n,k; cin>>n>>k;
  string s; cin>>s;
  rep(i,n) s.PB(s[n-i-1]);
	vector<string> candidate;
	rep(i,n) candidate.PB(s.substr(i,n));
	sort(ALL(candidate));

  string opt = candidate[0];
	int i = 0;
	int l = 0;
	while(opt[i]==opt[0]){
		l++; i++;
	}
	int r = pow(2,min(k-1,15))*l;
	string ans;
	i = 0;
	while((ans.size()<n)&&(i<r)){
		ans.PB(opt[0]); i++;
	}
	i = 0;
	while(ans.size()<n){
		ans.PB(opt[l+i]); i++;
	}
	cout << ans << endl;
  return 0;
}

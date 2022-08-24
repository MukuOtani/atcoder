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
	string s; cin>>s;
  int n = s.size();
  int ans1 = 0;
  int ans2 = 0;
  // æ‚èœ‚¯‚È‚¢‚Æ‚« abab...aba(‹ô”’·) or abababa...bab(Šï”’·)
  // ‚Ì‚æ‚¤‚É‚È‚é(a,b‚Í”CˆÓ‚Ì•¶š)
  // Å‰‚ÆÅŒã‚Íæ‚èœ‚¯‚È‚¢‚Ì‚ªƒ|ƒCƒ“ƒg
  // Å‰‚ÆÅŒã‚ªˆÙ‚È‚é•¶š‚È‚ç abab ‚Ì‚æ‚¤‚É‹ô”’·
  // Å‰‚ÆÅŒã‚ª“¯‚¶•¶š‚È‚ç aba ‚Ì‚æ‚¤‚ÉŠï”’·
  if(s[0]==s[n-1]) ans1 = 1;
  if(n%2) ans2 = 1;
  if(ans1^ans2) cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
}

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
  int h,w,n; cin>>h>>w>>n;
  int r,c; cin>>r>>c; r--; c--;
  string s,t; cin>>s>>t;

  // ‚Ü‚¸‚Í¶‰E‚É‚Â‚¢‚Ä
  int left=0, right=w;
  if(s[n-1]=='L') left++;
  if(s[n-1]=='R') right--;
  REP(i,n-1){
    if(t[i]=='L') right=min(right+1,w);
    else if(t[i]=='R') left=max(0,left-1);
    if(s[i]=='L') left++;
    else if(s[i]=='R') right--;
    if(left>=right) return cout<<"NO"<<endl,0;
  }
  if(c<left||right<=c) return cout<<"NO"<<endl,0;


  // ŽŸ‚Éã‰º‚É‚Â‚¢‚Ä
  left=0, right=h;
  if(s[n-1]=='U') left++;
  if(s[n-1]=='D') right--;
  REP(i,n-1){
    if(t[i]=='U') right=min(right+1,h);
    else if(t[i]=='D') left=max(0,left-1);
    if(s[i]=='U') left++;
    else if(s[i]=='D') right--;
    if(left>=right) return cout<<"NO"<<endl,0;
  }
  if(r<left||right<=r) return cout<<"NO"<<endl,0;

  cout << "YES" << endl;

  return 0;
}

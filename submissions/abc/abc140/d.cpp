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

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

signed main(){
  int n,k; cin>>n>>k;
  string s; cin>>s;
  int cnt_lr = 0, cnt_rl = 0;
  int hap = 0;
  rep(i,n-1){
    if(s[i]=='L'&&s[i+1]=='R') cnt_lr++;
    if(s[i]=='R'&&s[i+1]=='L') cnt_rl++;
    if(s[i]==s[i+1]) hap++;
  }
  // int cnt = min(k,min(cnt_lr,cnt_rl));
  //
  // cerr << hap SP cnt_lr SP cnt_rl SP cnt << endl;
  int cnt = 0;
  while(cnt<k&&cnt_lr&&cnt_rl){
    hap += 2; cnt++;
    cnt_lr--; cnt_rl--;
  }
  if(cnt<k&&max(cnt_lr,cnt_rl)) hap++;

  // int ans = hap+cnt*2;
  // if((cnt_lr+cnt_rl)&&(!cnt)) ans++;
  // cout << min(n,ans) << endl;
  cout << min(n,hap) << endl;


  return 0;
}

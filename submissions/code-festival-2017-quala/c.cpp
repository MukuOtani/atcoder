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
  int h,w; cin>>h>>w;
  string s[h]; rep(i,h) cin>>s[i];
  int moji[26]; CLR(moji);
  rep(i,h) rep(j,w) moji[s[i][j]-'a']++;
  bool h2 = true, w2 = true;
  if(h%2) h2 = false; if(w%2) w2 = false; // h,w‚»‚ê‚¼‚ê‹ô”‚È‚çh2,w2‚ªtrue
  bool ans = true;
  if(h2&&w2){ // —¼•û‹ô”‚È‚ç‘S•¶š4‚Ì”{”ŒÂ
    rep(i,26){
      if(moji[i]%4){
        ans = false; break;
      }
    }
  }else if(h2&&!w2){ // ‰¡•ûŒü‚¾‚¯Šï”‚È‚ç^‚ñ’†c•ûŒü‚Ì‚İ‰¡Œü‚«‚ÉŒ©‚½‚çŒÇ—§‚µ‚Ä‚à‚æ‚¢
    int cnt = 0;
    rep(i,26){
      if(moji[i]%2){
        ans = false; break;
      }
      if(moji[i]%4==2) cnt++;
    }
    if(cnt>h/2) ans = false;
  }else if(!h2&&w2){ // c•ûŒü‚¾‚¯Šï”‚È‚ç^‚ñ’†‰¡•ûŒü‚Ì‚İcŒü‚«‚ÉŒ©‚½‚çŒÇ—§‚µ‚Ä‚à‚æ‚¢
    int cnt = 0;
    rep(i,26){
      if(moji[i]%2){
        ans = false; break;
      }
      if(moji[i]%4==2) cnt++;
    }
    if(cnt>w/2) ans = false;
  }else{ // —¼•ûŠï”‚È‚ç’†‰›‚Ì•¶š‚Ì‚İŠï”ŒÂ‚Ìí—Ş‚Å‚È‚¯‚ê‚Î‚È‚ç‚È‚¢
    int cnt1 = 0, cnt2 = 0;
    rep(i,26){
      if(moji[i]%2) cnt1++;
      if(moji[i]%4==2||moji[i]%4==3) cnt2++;
    }
    cerr << cnt1 SP cnt2 << endl;
    if(cnt1!=1) ans = false;
    if(cnt2>(h+w)/2-1) ans = false;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

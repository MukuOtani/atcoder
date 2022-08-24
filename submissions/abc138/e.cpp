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
	string s,t; cin>>s>>t;
  ll n = s.size();
  VVI C;
  rep(i,26){
    VI c; C.PB(c);
  }
  rep(i,s.size()) C[s[i]-'a'].PB(i);

  bool can = true;
  rep(i,t.size()) if(C[t[i]-'a'].size()==0) can = false;
  if(!can){
    cout << -1 << endl;
    return 0;
  }

  int len[26]; CLR(len);
  int k = 0; ll rep = 0; ll idx=-1;
  while(k<t.size()){
    if(len[t[k]-'a']==C[t[k]-'a'].size()){
      cerr << "case1" << endl;
      CLR(len); rep++;
    }
    else if(idx>C[t[k]-'a'][len[t[k]-'a']]){
      cerr << "case2" << endl;
      bool flg = true;
      while(true){
        len[t[k]-'a']++;
        if(len[t[k]-'a']==C[t[k]-'a'].size()){
          flg = false; break;
        }
        if(idx<C[t[k]-'a'][len[t[k]-'a']]) break;
      }
      if(!flg){
        CLR(len); rep++;
      }
    }
    idx = C[t[k]-'a'][len[t[k]-'a']];
    len[t[k]-'a']++; k++;
    cerr << rep SP idx << endl;
  }
  ll ans = n*rep+idx+1;
  cout << ans << endl;
  return 0;
}

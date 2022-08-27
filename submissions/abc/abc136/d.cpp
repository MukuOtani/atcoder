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
	string S; cin >> S;
  int n = S.size();

  // LR -> ï™äÚ, RL -> èWçá
  VI cn;
  rep(_,n) cn.PB(1);

  rep(_,2){
    int cnt1 = 0; int cnt2 = 0;
    rep(i,n){
      if((S[i]=='R')&&(S[i+1]=='L')){
        if(i%2){
          cn[i] += cnt1; cn[i+1] += cnt2;
          cnt1 = 0; cnt2 = 0;
        }else{
          cn[i] += cnt2; cn[i+1] += cnt1;
          cnt1 = 0; cnt2 = 0;
        }
      }else if(S[i]=='R'){
        if(i%2){
          cnt1 += cn[i]; cn[i] = 0;
        }else{
          cnt2 += cn[i]; cn[i] = 0;
        }
      }
    }
    reverse(ALL(cn));
    reverse(ALL(S));
    rep(i,n){
      if(S[i]=='L') S[i] = 'R';
      else S[i] = 'L';
    }
  }

  rep(i,n){
    cout << cn[i] << ' ';
  }
  cout << endl;

	return 0;
}

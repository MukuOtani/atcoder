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
#define ALL(x) (x).begin(),(x).end()
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

int main() {
  string S; cin >> S;
  int N = S.size();
  rep(i,N){
    if(S[i]=='B'&&S[i+1]=='C'){
      S[i] = 'D';
      S.erase(S.begin()+i+1);
    }
  }
  // cout << S << endl;

  N = S.size();
  ll ans = 0;
  ll cnt = 0;
  rep(i,N){
    if(S[i]=='A'){
      cnt++;
    }else if(S[i]=='D'){
      ans += cnt;
    }else{
      cnt = 0;
    }
    // cout << ans << endl;
  }

  cout << ans << endl;
  return 0;
}

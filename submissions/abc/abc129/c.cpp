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

ll modpow(ll x, ll n) {
    if(n==0){
        return 1;
    }else if(n%2==0){
        ll h = modpow(x,n/2);
        return h * h % MOD;
    } else {
        return x * modpow(x,n-1) % MOD;
    }
}

int main() {
  int N, M; cin >> N >> M;
  int A[N];
  rep(i,M){
    int a; cin >> a;
    A[i] = a;
  }
  ll dp[N+1];
  dp[0] = 1;
  int j = 0;
  if(A[0]==1){
    dp[1] = 0;
    j++;
  }else{
    dp[1] = 1;
  }
  reps(i,N){
    if(i==1)  continue;
    if(A[j]!=i){
      dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }else{
      dp[i] = 0;
      j++;
    }
  }
  // rep(i,N){
  //   cout << dp[i] << ' ';
  // }
  // cout << endl;

  cout << dp[N]%MOD << endl;

  return 0;
}

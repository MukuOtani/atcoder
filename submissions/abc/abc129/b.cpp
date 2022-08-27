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
  int N; cin >> N;
  vector<int> W;
  rep(i,N){
    int w; cin >> w;
    W.push_back(w);
  }
  int up = 0;
  int down = 0;
  rep(i,N){
    up += W[i];
  }
  int sum = up;
  REPS(i,N-1){
    up -= W[i];
    down += W[i];
    sum = min(sum, abs(up-down));
  }

  cout << sum << endl;

  return 0;
}

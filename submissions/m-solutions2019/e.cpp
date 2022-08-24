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
#define MOD (long long int)(1e6+3)
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
  int Q; cin >> Q;
  ll x, d, n;
  vector<ll> X, D, N;
  rep(i,Q){
    cin >> x >> d >> n;
    X.push_back(x);
    D.push_back(d);
    N.push_back(n);
  }
  vector<ll> kaijo;
  kaijo.push_back(1);
  reps(i,MOD){
    kaijo.push_back((kaijo[i-1]*i)%MOD);
  }

  rep(i,Q){
    x = X[i]; d = D[i]; n = N[i];
    if(d==0){
      cout << modpow(x,n)%MOD << endl;
    }else{

      ll a = (x * modpow(d,MOD-2))%MOD;
      ll b = (x * modpow(d,MOD-2) + n - 1)%MOD;
      if((a > b)||(n>=MOD)||(a == 0)){
        cout << 0 << endl;
      }else{
        cout << kaijo[b] * modpow(kaijo[a-1],MOD-2) % MOD * modpow(d,n) % MOD << endl;
      }
    }
  }
  return 0;
}

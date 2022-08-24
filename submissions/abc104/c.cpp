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
#include <set>
#include <sstream>
#include <bitset>
#include <string>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)


ll modpow(ll x, ll n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        ll h = modpow(x, n / 2);
        return h * h % MOD;
    } else {
        return x * modpow(x, n - 1) % MOD;
    }
}

int gcd(int a,int b)  {
	if (a%b==0)  return(b);
	else return(gcd(b,a%b));
}

int main() {
    int D, G; cin >> D >> G;
    vector<int> p(D), c(D);
    rep(i,D)  cin >> p[i] >> c[i];

    int ans = INF;
    rep(mask, 1<<D) {
      int score = 0, solved = 0, rest_max = -1;
      rep(i,D)  {
        if (mask >> i & 1){
          score += 100 * (i+1) * p[i] + c[i];
          solved += p[i];
        }else{
          rest_max = i;
        }
      }
      if (score < G){
        int plus = 100 * (rest_max + 1);
        int need = (G - score + plus - 1) / plus;
        if (need >= p[rest_max]){
          continue;
        }
        solved += need;
      }
      ans = min(ans, solved);
    }
    cout << ans << endl;
    return 0;
}

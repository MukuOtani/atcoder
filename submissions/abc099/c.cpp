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
    int N; cin >> N;
    vector<int> draws;
    draws.push_back(1);
    for (int i=6; i<=N; i*=6) draws.push_back(i);
    for (int i=9; i<=N; i*=9) draws.push_back(i);

    int dp[N+1];
    fill(dp, dp+N+1, INF);
    dp[0] = 0;

    rep(i,N+1){
      rep(j,draws.size()){
        if (i >= draws[j]){
          dp[i] = min(dp[i], dp[i-draws[j]]+1);
        }
      }
    }

    cout << dp[N] << endl;
    return 0;
}

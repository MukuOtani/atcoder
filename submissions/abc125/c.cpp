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
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N)  cin >> a[i];

    int ans = 0;

    vector<int> g1(N-1);
    auto g2 = g1;
    g1[0] = a[0], g2[0] = a[N-1];

    reps(i,N-1)  {
      g1[i] = gcd(g1[i-1], a[i]);
      g2[i] = gcd(g2[i-1], a[N-1-i]);
    }

    // rep(i,N)  {
    //   cout << g1[i] << ' ' ;
    //   if (i == N-1) cout << endl;
    // }
    // rep(i,N)  {
    //   cout << g2[i] << ' ' ;
    //   if (i == N-1) cout << endl;
    // }

    rep(i,N-2)  {
      // cout << gcd(g1[i],g2[N-3-i]) << endl;
      ans = max(ans, gcd(g1[i],g2[N-3-i]));
    }
    cout << max(ans,max(g1[N-2],g2[N-2])) << endl;
    return 0;
}

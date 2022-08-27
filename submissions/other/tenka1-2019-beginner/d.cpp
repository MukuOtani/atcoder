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
// #define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

const int MOD = 998244353;

long long modpow(long long x, long long n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        long long h = modpow(x, n / 2);
        return h * h % MOD;
    } else {
        return x * modpow(x, n - 1) % MOD;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    int s = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        s += a[i];
    }
    vector<vector<long long>> dp1(N + 1, vector<long long>(s + 1, 0));
    auto dp2 = dp1;
    dp1[0][0] = 1, dp2[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= s; j++) {
            dp1[i + 1][j] += dp1[i][j] * 2;
            dp1[i + 1][j] %= MOD;
            dp2[i + 1][j] += dp2[i][j];
            dp2[i + 1][j] %= MOD;
            if (j - a[i] < 0) {
                continue;
            }
            dp1[i + 1][j] += dp1[i][j - a[i]];
            dp1[i + 1][j] %= MOD;
            dp2[i + 1][j] += dp2[i][j - a[i]];
            dp2[i + 1][j] %= MOD;
        }
    }
    long long res = modpow(3, N);
    for (int j = 0; j <= s; j++) {
        if (2 * j < s) {
            continue;
        }
        res -= dp1[N][j] * 3;
        res %= MOD;
        if (res < 0) {
            res += MOD;
        }
    }
    if (s % 2 == 0) {
        res += dp2[N][s / 2] * 3;
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}

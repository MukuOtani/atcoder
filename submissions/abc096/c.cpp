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
#define all(x) (x).begin(),(x).end()
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

int vector_finder(vector<int> vec, int number) {
  auto itr = find(vec.begin(), vec.end(), number);
  size_t index = distance(vec.begin(), itr);
  if (index != vec.size()) { // ”­Œ©‚Å‚«‚½‚Æ‚«
    return 1;
  }
  else { // ”­Œ©‚Å‚«‚È‚©‚Á‚½‚Æ‚«
    return 0;
  }
}

int main() {
    int H, W; cin >> H >> W;
    vector<string> s(H);
    rep(i, H) cin >> s[i];
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    reps(i, H-2){
      reps(j, W-2){
        int cnt = 0;
        if (s[i][j] != '#') continue;
        rep(k, 4){
          if (s[i+dy[k]][j+dx[k]] == '#')  cnt++;
        }
        if (cnt == 0){
          cout << "No" << endl;
          return 0;
        }
      }
    }
    cout << "Yes" << endl;
    return 0;
}

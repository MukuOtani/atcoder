#include <iostream>
#include <cstring>
#include <cmath>
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
#include <numeric>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(123456789012345678)


unsigned GetDigit(unsigned num) {
    return std::to_string(num).length();
}


int main(void){
	int N; cin >> N;
  int h[N], x[N] = {};
  rep(i, N) cin >> h[i];
  int ans = 0;
  int flg = 1;
  while (flg)  {
    int cnt = 0;
    int mode = 1;
    rep(i, N) {
      if (x[i] != h[i]) {
        x[i] += 1;
        if (mode) {
          cnt += 1;
          mode = 0;
        }
      } else  {
        mode = 1;
      }
    }
    ans += cnt;
    if (cnt == 0) flg = 0;
  }
  cout << ans << endl;
	return 0;
}

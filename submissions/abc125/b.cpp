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


template <typename T>
inline std::string to_bin_str(T n, std::size_t digit_num) {
    std::string str;
    while (n > 0) {
        str.push_back('0' + (n & 1));
        n >>= 1;
    }
    str.resize(digit_num, '0');
    std::reverse(str.begin(), str.end());
    return str;
}


int main(void){
	int N;	cin >> N;
  int V[N], C[N];
  string b[int(pow(2, N))];
  int ans = 0;

  rep(i,N)  {
    int a;
    cin >> a;
    V[i] = a;
  }
  rep(i,N)  {
    int a;
    cin >> a;
    C[i] = a;
  }
  rep(i,int(pow(2, N))) {
    b[i] = to_bin_str(i, N);
  }

  rep(i,int(pow(2, N)))  {
    int X = 0;
    int Y = 0;
    rep(j,N)  {
      if (b[i][j] == '1') {
        X += V[j];
        Y += C[j];
      }
    }
    ans = max(ans, X-Y);
  }



	cout << ans << endl;

	return 0;
}

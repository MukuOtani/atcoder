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

int main(void){
	int N;	cin >> N;
  int A[N];

  ll ans = 0;
  int cnt = 0;
  int mi = INF;

  rep(i,N)  {
    int a;  cin >> a;
    A[i] = a;
  }
  // int idx = 0;
  // rep(i,N)  {
  //   int a = A[i];
  //   cout << a << ' ';
  //   if ((a < 0) && (i != N-1))  a *= -1;
  //   else{
  //     if (i != N-1) idx = i;
  //   }
  //   if (i == N-1) {
  //     if (N-1-idx % 2 == 0) {
  //         if (a < 0)  a *= -1;
  //       }
  //     }
  //   cout << a << endl;
  //   ans += a;
  // }
  // cout << endl;

  rep(i,N)  {
    int a = A[i];
    if (a < 0)  {
      cnt++;
      a *= -1;
    }
    mi = min(mi,a);
    ans += a;
  }

  if (cnt%2 == 1) ans -= mi*2;

  cout << ans << endl;





	return 0;
}

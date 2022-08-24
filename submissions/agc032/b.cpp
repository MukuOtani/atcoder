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
#define INF (int)(1123456789)
#define LINF (long long int)(123456789012345678)


int main(void){
  int N;  cin >> N;
  int mode = N % 2;
  int M = N*(N-1)/2;
  if (mode)  {
    cout << M-(N-1)/2 << endl;
    reps(i, N-1) {
      for(int j=i+1; j<=N; j++) {
        if (j != N-i) {
          cout << i << " " << j << endl;
        }
      }
    }
  } else  {
    cout << M-N/2 << endl;
    reps(i, N-1) {
      for(int j=i+1; j<=N; j++) {
        if (j != N+1-i) {
          cout << i << " " << j << endl;
        }
      }
    }
  }

	return 0;
}

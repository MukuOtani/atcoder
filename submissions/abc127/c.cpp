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

int main() {
  int N, M; cin >> N >> M;
  int L[M], R[M];
  rep(i,M){
    cin >> L[i] >> R[i];
  }
  int left = 1;
  int right = INF;
  int ans = 0;
  rep(i,M){
    left = max(L[i], left);
    right = min(R[i], right);
  }
  if (left<=right)  cout << right-left+1 << endl;
  else cout << 0 << endl;
  return 0;

}

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
#define ALL(x) (x).begin(),(x).end()
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

int main() {
  int N, M; cin >> N >> M;
  vector<int> A, D;
  vector<pair<int, int> > V(M);
  rep(i,N){
    int a; cin >> a;
    A.push_back(a);
  }
  sort(ALL(A));
  rep(i,M){
    int b, c; cin >> b >> c;
    V[i] = {c,b};
  }
  sort(V.rbegin(), V.rend());

  int cnt = 0;
  ll ans = 0;
  rep(i,M){
    rep(j,V[i].second){
      ans += max(A[cnt], V[i].first);
      cnt++;
      if(cnt==N){
        j = V[i].second;
        i = M;
        break;
      }
    }
  }

  for(int i=cnt; i < N; i++){
    ans += A[i];
  }
  cout << ans << endl;

  return 0;
}

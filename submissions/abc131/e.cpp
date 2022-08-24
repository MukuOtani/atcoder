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
#define ALL(x) (x).begin(),(x).end()
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

int main() {
  int N, K; cin >> N >> K;
  vector<vector<int> > G;

  int M = N*(N-1)/2 - K;
  if(N-1 <= M){
    reps(i,N-1){
      vector<int> l;
      l.push_back(1);
      l.push_back(i+1);
      G.push_back(l);
    }
    for(int i=2; i<=N; i++){
      for(int j=i+1; j<=N; j++){
        if(K>0){
          K--;
        }else{
          vector<int> l;
          l.push_back(j);
          l.push_back(i);
          G.push_back(l);
        }
      }
    }
    cout << M << endl;
    rep(i,G.size()){
      cout << G[i][0] << ' ' << G[i][1] << endl;
    }

  }else{
    cout << -1 << endl;
  }



  return 0;
}

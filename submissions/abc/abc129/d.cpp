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
  int H, W; cin >> H >> W;
  string S[H];
  rep(i,H) cin >> S[i];

  int U[H][W], D[H][W], L[H][W], R[H][W];
  int cnt = 0;

  rep(i,H){
    rep(j,W){
      if(S[i][j] == '#'){
        L[i][j] = cnt;
        cnt = 0;
      }else{
        cnt++;
        L[i][j] = cnt;
      }
    }
    cnt = 0;
  }
  rep(i,H){
    REP(j,W){
      if(S[i][j] == '#'){
        R[i][j] = cnt;
        cnt = 0;
      }else{
        cnt++;
        R[i][j] = cnt;
      }
    }
    cnt = 0;
  }
  rep(i,W){
    rep(j,H){
      if(S[j][i] == '#'){
        U[j][i] = cnt;
        cnt = 0;
      }else{
        cnt++;
        U[j][i] = cnt;
      }
    }
    cnt = 0;
  }
  rep(i,W){
    REP(j,H){
      if(S[j][i] == '#'){
        D[j][i] = cnt;
        cnt = 0;
      }else{
        cnt++;
        D[j][i] = cnt;
      }
    }
    cnt = 0;
  }
int ans = 0;
rep(i,H){
  rep(j,W){
    // cout<<R[i][j]<<" ";
    if(S[i][j]=='.'){
      ans = max(ans, L[i][j]+R[i][j]+U[i][j]+D[i][j]-3);
    }
  }
}
cout << ans << endl;

  return 0;
}

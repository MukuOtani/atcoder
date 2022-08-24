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
	int N, A, B, C; cin >> N >> A >> B >> C;
  int ans = INF;
  vector<int> end;  // 目的とする長さのリスト
  end.push_back(A);
  end.push_back(B);
  end.push_back(C);
  int l[N];
  rep(i, N) cin >> l[i];

  // N桁の4進数について考える
  int max_cnt = std::pow(4, N);
  
  // 1から4**Nまで
  rep(i, max_cnt)  {
    
    // 長さが4のリストassignに、A,B,C,未使用の竹の長さを割り当てる
    vector<vector<int> > assign;
    assign.resize(4);
    
    int cnt = i;
    rep(j, N) {
      // 4進数で表した時の一番下の桁を見る
      assign[cnt%4].push_back(l[j]);
      // 一番下の桁を抜く
      cnt = cnt/4;
    }
    if (assign[0].size()!=0 && assign[1].size()!=0 && assign[2].size()!=0)  {
      int cost = 0; // 操作に必要なコスト
      rep(i, 3) {
        cost += (assign[i].size()-1) * 10;  // mergeの操作
        cost += abs(end[i] - std::accumulate(assign[i].begin(), assign[i].end(), 0)); // 長さの調整
      }
      ans = min(ans, cost); // コストの小さい方が答え
    }
  }
  cout << ans << endl;
	return 0;
}

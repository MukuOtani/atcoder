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
  int N; cin >> N;
  vector<int> G[100005], C, d, edge;
  int a, b, cost, M;
  rep(i,N-1){
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i,N){
    cin >> cost;
    C.push_back(cost);
    M += cost;
  }
  sort(ALL(C));
  M -= C[C.size()-1];
  int next = 0;
  rep(i,N){
    edge.push_back(G[i].size());
    d.push_back(-1);
  }

  while(true){
    bool flag = false;
    rep(i,N){
      if(edge[i] == 1){
        flag = true;
        d[i] = C[next];
        next++;
        edge[i]--;
        rep(j,G[i].size()) edge[G[i][j]]--;
      }
    }
    if(!flag) break;
  }

  cout << M << endl;
  rep(i,N){
    if(d[i] == -1){
      cout << C[C.size()-1] << ' ';
    }else{
      cout << d[i] << ' ';
    }
  }
  cout << endl;
  return 0;
}

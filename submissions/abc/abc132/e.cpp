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
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
const int INF = 1001001001;
const ll LINF = 100100100100100100;

typedef pair<int,int> P;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
  int N, M; cin >> N >> M;
  VVI G(N);
  rep(i,M){
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
  }
  int S, T; cin >> S >> T;
  S--; T--;
  int dist[100005][3];
  rep(i,N)rep(j,3) dist[i][j]=INF;

  queue<P> q; q.push(P(S,0));
  dist[S][0] = 0;
  while(!q.empty()){
    int v = q.front().first;
    int l = q.front().second;
    q.pop();
    for(int u : G[v]){
      int nl = (l+1)%3;
      if(dist[u][nl]!=INF) continue;
      dist[u][nl] = dist[v][l]+1;
      q.push(P(u,nl));
    }
  }
  int ans = dist[T][0];
  if(ans==INF) ans = -1;
  else ans /= 3;
  cout << ans << endl;
  return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <sstream>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort(ALL(x))
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

signed main(){
  int n; cin>>n;
  int a[n][n-1];
  rep(i,n){
    rep(j,n-1) cin>>a[i][j];
  }

  int next[n][2]; // 対戦相手, 何試合目か
  rep(i,n){
    next[i][0] = a[i][0];
    next[i][1] = 1;
  }
  int day = 0;
  bool visited[n];
  rep(i,n) visited[i] = false;
  bool check = true;
  int cnt = 0;

  while(check){
    // cerr<<"day"<<day+1<<endl;
    // cerr << "next[0][1]" SP next[0][1] << endl;

    rep(i,n){ // 次の対戦相手の更新
      if(!visited[i]) continue;
      if(next[i][1]==n-1){
        next[i][0] = INF; visited[i]=true;
      }else{
        next[i][0] = a[i][next[i][1]]; visited[i]=false; next[i][1]++;
      }

      // if(i==0){
      //   cerr<< "index0 check" SP next[i][0] SP next[i][1] SP visited[i] << endl;
      // }
      // if(next[i][1]==n) cnt++;
    }

    // rep(i,n) cerr<<next[i][0] << ' ';
    // cerr<<endl;
    check = false;

    rep(i,n){
      if(visited[i]||next[i][0]==INF) continue; // 対戦済みならスルー
      int aite = next[i][0]-1;
      if(visited[aite]||next[aite][0]==INF||next[aite][0]!=i+1) continue;
      // 対戦可能な時の処理
      // if(next[aite][0]!=i+1) continue;
      // cerr << "shori:" SP i SP "aite:" SP aite << endl;
      // cerr << visited[i] SP visited[aite] << endl;
      check = true;
      visited[i] = true; visited[aite] = true;
      if(next[i][1]==n-1) cnt++;
      if(next[aite][1]==n-1) cnt++;
    }
    day++;
    if(!check) return cout<<-1<<endl, 0;
    if(cnt==n) check=false;
    // cerr << "day:" SP day SP "cnt:" SP cnt << endl;
    // cerr << "visited[0]" SP visited[0] << endl;
    // cerr << endl;
  }
  cout << day << endl;

  return 0;
}

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
  int k,n; cin>>k>>n;
	vector<string> V, W;
  rep(i,n){
    string v,w; cin>>v>>w;
    V.PB(v); W.PB(w);
  }
  vector<int> C;
  rep(i,n){
    int c = W[i].size();
    C.PB(c);
  }
  // rep(i,V[0].size()){
  //   cout << V[0][i] << ' ';
  // }
  // cout << endl;
  // rep(i,n){
  //   cout << C[i] << " ";
  // }
  // cout << endl;
  rep(s,pow(3,k)){
    VI len(k);
    rep(i,k) len[i] = ((int)(s/pow(3,i))%3)+1;
    // rep(i,k){
    //   cout << len[i] << ' ';
    // }
    // cout << endl;
    bool flag = true;
    int mojisu;
    rep(i,n){
      mojisu = 0;
      rep(j,V[i].size()){
        int v = V[i][j] - '0' -1;
        mojisu += len[v];
        // if(s==1) cout << v SP len[v] << endl;
      }
      if(mojisu != C[i]){
        flag = false; break;
      }
    }
    // cout << s SP mojisu << endl;
    if(!flag) continue;
    string ans[k];
    rep(i,k) ans[i] = "";
    rep(i,n){
      int index = 0;
      rep(j,V[i].size()){
        int v = V[i][j] - '0' -1;
        if(ans[v]==""){
          ans[v] = W[i].substr(index,len[v]);
        }else{
          if(ans[v]!=W[i].substr(index,len[v])){
            flag = false; break;
          }
        }
        index += len[v];
      }
      if(!flag) break;
    }
    if(!flag){
      continue;
      // cout << "OUT" << endl;
    }
    rep(i,k) cout << ans[i] << endl;
    return 0;
  }
  // return 0;
}

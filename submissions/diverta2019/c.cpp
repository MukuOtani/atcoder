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
    int ans = 0;
    int btm_A = 0;
    int top_B = 0;
    int same = 0;
    int N; cin >> N;
    string s[N];
    rep(i,N) cin >> s[i];
    rep(i,N){
      int l = s[i].size();
      rep(j,l-1){
        if (s[i][j]=='A' && s[i][j+1]=='B') ans++;
      }
      if(s[i][0]=='B') top_B++;
      if(s[i][l-1]=='A') btm_A++;
      if(s[i][0]=='B' && s[i][l-1]=='A') same++;
    }
    int tmp;
    // cout << btm_A << top_B << same << endl;
    if(btm_A==top_B && same==btm_A && same>0) tmp = same-1;
    else tmp = min(btm_A, top_B);
    cout << ans+tmp << endl;
    return 0;
}

#include <iostream>
#include <vector>
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

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
  return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//mod add
void add (ll &a, ll b){
  a += b;
  if (a >= MOD) a -= MOD;
}

// 0: dammy, 1: 'A', 2: 'G', 3: 'C'. 4: 'T'
// "AGC, GAC, ACG", "A*GC", "AG*C"　を含まない (012, 102, 021　を禁止)
ll solve(int N){
  auto dp = make_vec<ll>(N+1, 5, 5, 5); // dp[i文字][3文字前][2文字前][1文字前]
  dp[0][0][0][0] = 1;
  rep(n,N){
    rep(i,5){
      rep(j,5){
        rep(k,5){
          reps(l,4){
            if (i == 1 && j == 2 && l == 3) continue;
            if (i == 1 && k == 2 && l == 3) continue;
            if (j == 1 && k == 2 && l == 3) continue;
            if (j == 2 && k == 1 && l == 3) continue;
            if (j == 1 && k == 3 && l == 2) continue;
            add(dp[n+1][j][k][l], dp[n][i][j][k]);
          }
        }
      }
    }
  }
  ll res = 0;
  reps(i,4){
    reps(j,4){
      reps(k,4){
        add(res, dp[N][i][j][k]);
      }
    }
  }
  return res;
}

int main(){
  int N;  cin >> N;
  cout << solve(N) << endl;
  return 0;
}

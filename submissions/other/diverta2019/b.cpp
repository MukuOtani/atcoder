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

// ëΩéüå≥ vector ê∂ê¨
template<class T>
vector<T> make_vec(size_t a){return vector<T>(a);}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));}

ll modpow(ll x, ll n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        ll h = modpow(x, n / 2);
        return h * h % MOD;
    } else {
        return x * modpow(x, n - 1) % MOD;
    }
}

int gcd(int a,int b)  {
	if (a%b==0)  return(b);
	else return(gcd(b,a%b));
}

int vector_finder(vector<int> vec, int number) {
  auto itr = find(vec.begin(), vec.end(), number);
  size_t index = distance(vec.begin(), itr);
  if (index != vec.size()) { // î≠å©Ç≈Ç´ÇΩÇ∆Ç´
    return 1;
  }
  else { // î≠å©Ç≈Ç´Ç»Ç©Ç¡ÇΩÇ∆Ç´
    return 0;
  }
}

int main() {
    int ans = 0;
    int R, G, B, N; cin >> R >> G >> B >> N;
    rep(i,N/R+1){
      rep(j,(N-i*R)/G+1){
        if((N-i*R-j*G)%B==0){
          // cout << i << j << endl;
          ans++;
        }
      }
    }
    cout << ans<< endl;
    return 0;
}

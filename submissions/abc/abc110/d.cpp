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
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)


/// •ûj
/// —^”M‚ğ‘fˆö”•ª‰ğ‚·‚é ‘fˆö”‚Æ‚»‚Ìw”‚ğpair‚Æ‚µ‚ÄƒŠƒXƒgP‚ÉŠi”[
/// P(‘fˆö”:s,  ŒÂ”:t)
/// NŒÂ‚Ì”‚ÌÏ‚É•ª‰ğ‚µ‚½‚¢‚Ì‚ÅAŠepair‚É‚Â‚¢‚ÄNŒÂ‚É•ªŠ„
/// Ï‚ğæ‚ê‚Î—Ç‚¢

// a‚Ìpæ‚ğ‹‚ß‚éŠÖ”
ll modpow(ll a, int p)  {
  if (p == 0) return 1;
  if (p%2 == 0) {
    int halfP = p / 2;
    ll half = modpow(a, halfP);
    return half * half % MOD;
  }
  else  {
    return a * modpow(a, p-1) % MOD;
  }
}


/// aCb‚ğ‹‚ß‚éŠÖ”
ll mod_combination(int a, int b)  {
  if (b > a-b)  return mod_combination(a, a-b);
  ll ansMul = 1;
  ll ansDiv = 1;
  rep(i, b) {
    ansMul *= (a - i);
    ansDiv *= (i + 1);
    ansMul %= MOD;
    ansDiv %= MOD;
  }
  ll ans = ansMul * modpow(ansDiv, MOD-2) % MOD;
  return ans;
}


int main(void){
	ll N, M; cin >> N >> M;
	vector< pair<int,ll> > P;
  /// ‘fˆö”•ª‰ğ‚µ‚ÄƒŠƒXƒgP‚ÉŠi”[
  ll original = M;
  int flag = 1;
  while (M != 1) {  /// ‘fˆö”•ª‰ğ‚ªI‚í‚é‚Ü‚ÅŒJ‚è•Ô‚·
    for (int i=2; i*i < original; i++)  {  /// l‚¦‚é‘fˆö”‚Ì’l‚ğ•Ï‚¦‚Ä‚¢‚­
      ll cnt = 0;
      while (flag)  {
        if (M%i == 0) {
          cnt++;
          M /= i;
        } else  {
          if (cnt)  {
            pair<int, ll> pa;
            pa.first = i;
            pa.second = cnt;
            P.push_back(pa);
          }
          flag = 0;
        }
      }
      flag = 1;
    }
    if (M != 1)  {
      pair<int, ll> pa;
      pa.first = M;
      pa.second = 1;
      P.push_back(pa);
      M = 1;
    }
  }
  flag = 1;
  ll ans = 1;
  rep(i, P.size())  {
    if (P[i].second == 0) {
      break;
    }
    ans *= mod_combination((P[i].second+N-1), N-1);
    ans %= MOD;
  }
  if (ans < 0)  {
    ans = MOD - ans;
  }
  cout << ans << endl;
	return 0;
}

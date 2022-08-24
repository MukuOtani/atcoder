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



// // a‚Ìpæ‚ð‹‚ß‚éŠÖ”
// ll modpow(ll a, int p)  {
//   if (p == 0) return 1;
//   if (p%2 == 0) {
//     int halfP = p / 2;
//     ll half = modpow(a, halfP);
//     return half * half % MOD;
//   }
//   else  {
//     return a * modpow(a, p-1) % MOD;
//   }
// }
//
//
// /// aCb‚ð‹‚ß‚éŠÖ”
// ll mod_combination(int a, int b)  {
//   if (b > a-b)  return mod_combination(a, a-b);
//   ll ansMul = 1;
//   ll ansDiv = 1;
//   rep(i, b) {
//     ansMul *= (a - i);
//     ansDiv *= (i + 1);
//     ansMul %= MOD;
//     ansDiv %= MOD;
//   }
//   ll ans = ansMul * modpow(ansDiv, MOD-2) % MOD;
//   return ans;
// }

// /// Å‘åŒö–ñ”‚ð‹‚ß‚éŠÖ”
// ll gcd(ll m, ll n) {
//   // int x = max(m, n);
//   // int y = min(m, n);
//   if (y == 0) return x;
//   return gcd(y, x%y);
// }


int main(void){
	int a[5], k;
	cin >> a[0];
	cin >> a[1];
	cin >> a[2];
	cin >> a[3];
	cin >> a[4];
	cin >> k;
	int ans = 0;
  rep(i, 5)	{
		for (int j=i+1; j<5; j++)	{
			if (abs(a[i]-a[j]) > k)	{
				ans++;
			}
		}
	}

	if (ans == 0)	{
		cout << "Yay!" << endl;
	}	else	{
		cout << ":(" << endl;
	}

	return 0;
}

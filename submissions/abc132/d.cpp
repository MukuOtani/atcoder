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
#include <numeric>
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

ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==0){
		ll memo = mpow(a,b/2);
		return memo*memo%MOD;
	}else{
		return mpow(a,b-1) * a % MOD;
	}
}

int main(){
	ll N, K; cin >> N >> K;
	ll ans1, ans2;
	ans1 = N-K+1; ans2 = 1;

	reps(i,K){
		cout << ans1 * ans2 % MOD << endl;
		ans1 *= N-K+1-i;
		ans1 %= MOD;
		ans1 *= mpow(i+1, MOD-2);
		ans1 %= MOD;
		ans2 *= K-i;
		ans2 %= MOD;
		ans2 *= mpow(i, MOD-2);
		ans2 %= MOD;
	}

	return 0;
}

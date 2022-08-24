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

int main(){
	ll l, r; cin >> l >> r;
	ll m = 2019;
	vector<ll> a;
	a.push_back(l%m);
	int cnt = 0;
	for(int i=l+1; i<=r; i++){
		if(cnt==2*m) break;
		ll add = i%m;
		cnt++;
		a.push_back(add);
	}
	ll ans = INF;
	reps(i,a.size()-1){
		rep(j,i){
			ans = min(ans, (a[i]*a[j])%m);
		}
	}

	cout << ans << endl;

	return 0;
}

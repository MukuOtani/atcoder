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

ll gcd(ll a,ll b)  {
	if (a%b==0)  return(b);
	else return(gcd(b,a%b));
}

ll lcm(ll number1,ll number2){
	return number1 * number2 / gcd(number1,number2);
}



int main(){
	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll ans = 0;
	ll x, y, z;
	// cout << "LCM" << endl;
	ll l = lcm(c,d);
	// cout << l << endl;
	x = b/c - (a-1)/c;
	y = b/d - (a-1)/d;
	z = b/l - (a-1)/l;
	ans = (b-a+1) - (x+y-z);


	cout << ans << endl;
	return 0;
}

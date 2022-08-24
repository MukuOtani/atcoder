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

// ll gcd(ll a,ll b)  {
// 	if (a%b==0)  return(b);
// 	else return(gcd(b,a%b));
// }
//
// ll lcm(ll number1,ll number2){
// 	return number1 * number2 / gcd(number1,number2);
// }



int main(){
	int N; cin >> N;
	vector<int> d;
	rep(i,N){
		int a; cin >> a;
		d.push_back(a);
	}
	sort(ALL(d));
	int a = d[N/2-1];
	int b = d[N/2];
	cout << b-a << endl;


	return 0;
}

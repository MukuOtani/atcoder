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
	string S; cin >> S;
	int ans = 0;
	if(S.size()!=4) ans++;
	vector<char> L;
	L.push_back(S[0]);
	reps(i,3){
		bool flg = false;
		rep(j, L.size()){
			if(S[i]==L[j]) flg = true;
		}
		if(!flg) L.push_back(S[i]);
	}
	if(L.size()!=2) ans++;

	if(ans==0){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}


	return 0;
}

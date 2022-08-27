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
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)


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
  if (index != vec.size()) { // ”­Œ©‚Å‚«‚½‚Æ‚«
    return 1;
  }
  else { // ”­Œ©‚Å‚«‚È‚©‚Á‚½‚Æ‚«
    return 0;
  }
}

int main() {
    int A, B, K;  cin >> A >> B >> K;
    int former = A, latter = B-K+1;

    while(former <= min(B,A+K-1)){
      cout << former << endl;
      former++;
    }
    // cout << "sec" << endl;
    latter = max(former, latter);
    while(latter <= B){
      cout << latter << endl;
      latter++;
    }


    return 0;
}

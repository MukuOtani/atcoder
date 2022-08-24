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
#define MOD (long long int)(1e6+3)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define ALL(x) (x).begin(),(x).end()
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

ll modpow(ll x, ll n) {
    if(n==0){
        return 1;
    }else if(n%2==0){
        ll h = modpow(x,n/2);
        return h * h % MOD;
    } else {
        return x * modpow(x,n-1) % MOD;
    }
}

int main() {
  std::cout<<std::fixed<<std::setprecision(12);
  ll n, m, d;
  cin >> n >> m >> d;

  //�S����n^m�ʂ�
  //�������ɊY������g��(n,n-d),...,(d+1,1)
  //�ׂ荇��2�̐��ɂ��Ĕ������𖞂����m����(n-d)/(n^2)
  double ans;

  //d==0�̂Ƃ�
  //�������ɊY������g��n�g
  //�ׂ荇��2�̐��ɂ��Ĕ������𖞂����m����(n)/(n^2)

  if(d==0){
    ans = 1.0*(m-1)/(1.0*n);
  }else{
    ans = 2.0*(n-d)*(m-1)/(1.0*n*n);
  }

  cout << ans << endl;

  return 0;
}

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
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()


template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

int main(){
  std::cout<<std::fixed<<std::setprecision(9);
	double W, H, x, y; cin >> W >> H >> x >> y;
  double ans;
  ans = (1.0*W*H)/2.0;

  if((x==W/2)&&(y==H/2)){
    cout << ans << ' ' << 1 << endl;
  }else if((x==W/2)||(y==H/2)){
    cout << ans << ' ' << 0 << endl;
  }else{
    cout << ans << ' ' << 0 << endl;
  }

	return 0;
}

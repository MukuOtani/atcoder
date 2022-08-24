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
#define LINF (long long int)(123456789012345678)


int main(void){
  int N;  cin >> N;
  int check = 1;
  vector<int> b, ans, tmp;
  rep(i, N) {
    int n;  cin >> n;
    b.push_back(n);
  }

  int i = N;
  while (b.size()) {
    if (i==b[i-1])  {
      ans.push_back(b[i-1]);
      b.erase(b.begin()+i-1);
      i = b.size();
    } else  {
      i--;
      if (i == 0)  {
        check = 0;
        break;
      }
    }
  }
  // while (b.size())  {
  //   REP(i, b.size()) {
  //     if (i+1==b[i])  {
  //       tmp.push_back(b[i]);
  //       b.erase(b.begin()+i-1);
  //       i = b.size()-1;
  //     }
  //   }
  //   if (tmp.size()==0)  {
  //     check = 0;
  //     break;
  //   }
  //   copy(tmp.begin(), tmp.end(), back_inserter(ans));
  //   tmp.clear();
  // }

  if (check)  {
    REP(i, N) {
      cout << ans[i] << endl;
    }
  } else  {
    cout << -1 << endl;
  }
	return 0;
}

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
#define all(x) (x).begin(),(x).end()
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

int main() {
  int s; cin >> s;
  int a = s/100;
  int b = s%100;
  if((1<=a && a<=12) && (b==0 || b>=13)) cout << "MMYY" << endl;
  else if((1<=b && b<=12) && (a==0 || a>=13)) cout << "YYMM" << endl;
  else if((a==0 || a>=13) && (b==0 || b>=13)) cout << "NA" << endl;
  else cout << "AMBIGUOUS" << endl;



}

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
	string s; cin >> s;
	int n = s.size();
	int ans = 0;
	for(int i=n-2; i>0; i-=2){
		string t = s.substr(0, i/2);
		string u = s.substr(i/2, i/2);
		if(t==u){
			ans = max(ans, i);

			// cout << t << ' ' << u << endl;
		}
	}
	cout << ans << endl;
	return 0;
}

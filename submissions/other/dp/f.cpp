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
#define MAX_V 1000


int main(void){
	string s, t;	cin >> s >> t;
	int l_s, l_t;
	l_s = s.size();
	l_t = t.size();
	vector< vector<int> > dp;
	rep(i, l_s+1){
		dp.push_back(vector<int>());
		rep(j, l_t+1){
			dp[i].push_back(0);
		}
	}

	rep(i, l_s){
		rep(j, l_t){
			if(s[i] == t[j]){
				dp[i+1][j+1] = dp[i][j]+1;
			}else{
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}

	string res = "";
	while (l_s > 0 && l_t > 0){
		if (dp[l_s][l_t] == dp[l_s-1][l_t]){
			--l_s;
		}
		else if (dp[l_s][l_t] == dp[l_s][l_t-1]){
			--l_t;
		}
		else {
			res = s[l_s-1] + res;
			--l_s, --l_t;
		}
	}

	cout << res << endl;
	return 0;
}

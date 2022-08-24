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
	int N;	cin >> N;
	ll W;		cin >> W;
	vector<ll> w(N), v(N);
	rep(i,N){
		cin >> w[i] >> v[i];
	}

	int V = N * MAX_V;
	vector< vector<ll> > dp;
	rep(i, N+1){
		dp.push_back(vector<ll>());
		rep(j,V+1){
			dp[i].push_back(LINF);
		}
	}
	dp[0][0] = 0;

	rep(i,N){
		rep(sum_v, V+1){
			if(sum_v < v[i]){
				dp[i+1][sum_v] = dp[i][sum_v];
			}else{
				dp[i+1][sum_v] = min(dp[i][sum_v], dp[i][sum_v-v[i]]+w[i]);
			}
		}
	}
	ll res = 0;
	rep(sum_v, V+1){
		if(dp[N][sum_v] <= W)	res =  sum_v;
	}
	cout << res << endl;
	return 0;
}

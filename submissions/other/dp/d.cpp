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
#define INF (int)(123456789)
#define LINF (long long int)(123456789012345678)
#define MAX_V 1000


int main(void){
	int N, W;	cin >> N >> W;
	vector<int> w(N), v(N);
	rep(i,N){
		cin >> w[i] >> v[i];
	}

	vector< vector<ll> > dp;
	rep(i, N+1){
		dp.push_back(vector<ll>());
		rep(j,W+1){
			dp[i].push_back(0);
		}
	}

	rep(i,N){
		reps(sum_w, W){
			if(sum_w < w[i]){
				dp[i+1][sum_w] = dp[i][sum_w];
			}else{
				dp[i+1][sum_w] = max(dp[i][sum_w], dp[i][sum_w-w[i]]+v[i]);
			}
		}
	}
	cout << dp[N][W] << endl;
	return 0;
}

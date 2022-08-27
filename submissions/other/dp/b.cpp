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
	int N, K;	cin >> N >> K;
	vector<int> h(N);
	rep(i,N){
		cin >> h[i];
	}

	vector<int> dp(N, INF);
	dp[0] = 0;

	rep(i,N){
		reps(j, K){
			if(i+j < N){
				dp[i+j] = min(dp[i+j], dp[i]+abs(h[i]-h[i+j]));
			}
		}
	}
	cout << dp[N-1] << endl;
	return 0;
}

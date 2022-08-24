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
	int n, d; cin >> n >> d;
	vector<vector <double> > X;
	rep(i,n){
		vector<double> Y;
		rep(j,d){
			double x; cin >> x;
			Y.push_back(x);
		}
		X.push_back(Y);
	}

	int ans = 0;
	reps(i,n-1){
		rep(j,i){
			double sum = 0;
			rep(k,d){
				sum += pow((X[i][k] - X[j][k]), 2.0);
			}
			if(ceil(pow(sum, 0.50)) == floor(pow(sum, 0.50))) ans++;
		}
	}

	cout << ans << endl;
	return 0;
}

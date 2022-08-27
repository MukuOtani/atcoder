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
#include <string>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

int main(void){
	int N;	cin >> N;
	vector<ll> A, B;
	rep(i,N)	{
		ll a, b; cin >> a >> b;
		A.push_back(a);
		B.push_back(b);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	ll med_A, med_B;
	if (N%2==0)	{
		med_A = (A[N/2-1]+A[N/2])/2;
		med_B = (B[N/2-1]+B[N/2])/2;
	}else{
		med_A = A[N/2];
		med_B = B[N/2];
	}

	ll ans = 0;
	rep(i,N)	{
		if (med_A < A[i])	{
			if (med_B < B[i])	{
				ans +=  2*B[i] - med_A - med_B;
			}else{
				ans += med_B - med_A;
			}
		}else{
			if (med_B < B[i])	{
				ans +=  med_A - 2*A[i] + 2*B[i] - med_B;
			}else{
				ans += med_A - 2*A[i] + med_B;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

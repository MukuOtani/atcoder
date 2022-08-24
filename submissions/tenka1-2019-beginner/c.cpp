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
	string S;	cin >> S;
	int w_s = 0;
	int b_s = 0;
	int white = 0;
	int black = 0;
	int tmp = 0;


	rep(i, N)	{
		if (S[i] == '#')	b_s++;
		else							w_s++;
	}

	int ans = w_s;

	rep(i, N)	{
		if (S[i] == '#')	black++;
		else							white++;

		tmp = black + (w_s-white);
		ans = min(tmp, ans);
	}

	cout << ans << endl;

	return 0;
}

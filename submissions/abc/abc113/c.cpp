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


unsigned GetDigit(unsigned num) {
    return std::to_string(num).length();
}


int main(void){
	ll N, M;
	cin >> N >> M;
	vector<pair<ll,ll> > pf[100001];
	int ANSP[100001];
	int ANSX[100001];

	reps(i, M)	{
		int p, y;	cin >> p >> y;
		ANSP[i] = p;
		pair<ll, ll> pa;
		pa.first = y;
		pa.second = i;
		// P[i] = a, Y[i] = b;
		pf[p].push_back(pa);
	}

	reps(p, N) {
		sort(pf[p].begin(), pf[p].end());
		rep(x, pf[p].size()) {
			ANSX[pf[p][x].second] = x+1;
		}
	}

	reps(i, M) {
		int len_p = 6 - GetDigit(ANSP[i]);
		std::string str_p(len_p, '0');
		int len_x = 6 - GetDigit(ANSX[i]);
		std::string str_x(len_x, '0');
			cout << str_p << ANSP[i] << str_x << ANSX[i];
			cout << endl;
	}

	return 0;
}

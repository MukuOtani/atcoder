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
	int N, K;	cin >> N >> K;
	string s;	cin >> s;
	vector<int> cnts;
	int cnt = 1;

	///	1の個数、0の個数、1の個数、… 、0の個数、1の個数となるように配列cntsを作る
	///	入力sが、0で始まるor0で終わるようなら、最初or最後に1の個数が0として加えておく
	if (s[0] == '0')	{
		cnts.push_back(0);
	}
	rep(i,N)	{
		if (s[i] != s[i+1])	{
			cnts.push_back(cnt);
			cnt = 1;
		}else{
			cnt++;
		}
	}
	while(cnts.size() < 2+2*K)	{
		cnts.push_back(0);
	}
	if (s[s.size()-1] == '0')	{
		cnts.push_back(0);
	}

	///	2K+1個ずつ、'1の個数'から始まるように和を比較する(尺取法)
	int tmp = 0;
	rep(i,2*K+1)	{
		tmp += cnts[i];
	}
	int ans = tmp;
	reps(i,cnts.size()-2*K-2)	{
		i++;
		tmp -= cnts[i-2] + cnts[i-1];
		tmp += cnts[i+2*K-1] + cnts[i+2*K];
		ans = max(ans, tmp);
	}

	cout << ans << endl;

	return 0;
}

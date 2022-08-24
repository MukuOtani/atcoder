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
	string s;	cin >> s;
	int ans = 0;
	reps(i,N-1)	{
		string s1 = s.substr(0,i);
		string s2 = s.substr(i);
		int tmp = 0;
		for (char c='a'; c<='z'; c++)	{
			bool left=false, right=false;
			rep(i,s1.size())	{
				if (s1[i]==c)	left=true;
			}
			rep(j,s2.size())	{
				if (s2[j]==c)	right=true;
			}
			if (left&&right)	tmp++;
		}
		if (ans < tmp)	ans=tmp;
	}
	cout << ans << endl;
	return 0;
}

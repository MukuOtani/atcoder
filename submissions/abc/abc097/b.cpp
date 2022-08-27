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
	int X;	cin >> X;
	vector<bool> ex(X+1);

	ex[1] = 1;
	for (int b = 2; b <= X; b++)	{
		int v = b * b;
		while (v <= X)	{
			ex[v] = 1;
			v *= b;
		}
	}
	REPS(i, X)	if (ex[i])	{
			cout << i << endl;
			return 0;
	}
}

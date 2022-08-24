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
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

int main(){
	int N,M;
	int k,s;
	vector<vector<int>> swi;
	cin>>N>>M;
	rep(i,M){
		cin>>k;
		swi.push_back(vector<int>());
		rep(j,k){
			cin>>s;
			swi[i].push_back(s-1);
		}
	}

	int inp;
	vector<int> p;
	rep(i,M){
		cin>>inp;
		p.push_back(inp);
	}
	ll ans = 0;
	rep(x,1<<N){
		bool flag = true;
		rep(i,M){
			int count = 0;
			rep(j,swi[i].size()){
				if((x>>swi[i][j])&1){
					count++;
				}
			}
			if(count%2 != p[i]){
				flag = false;

				break;
			}
		}
		if(flag) ans++;
	}
	cout<<ans<<endl;
}

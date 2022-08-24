#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <set>
#include <sstream>
using namespace std;
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort(ALL(x))
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
const int INF = 1001001001;
const ll MOD = 1e9+7;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

signed main(){
	ll a,b,x; cin>>a>>b>>x;

	ll mid, left = -1, right = 1e9+1;
	if(x/a+1<1e9) right = x/a+1;
	while(left<right){
		mid = (left+right)/2;

		if(a*mid+b*((int)log10((double)mid)+1)==x){
			left = mid;
			break;
		}
		else if(a*mid+b*((int)log10((double)mid)+1)>x) right = mid;
		else{
			ll tmp = mid+1;
			if(a*tmp+b*((int)log10((double)tmp)+1)>x){
				left = mid;
				break;
			}
			left = tmp;
		}
	}
	if(left>1e9) left = 1e9;
	cout << left << endl;
	// cerr << mid SP right << endl;

  return 0;
}

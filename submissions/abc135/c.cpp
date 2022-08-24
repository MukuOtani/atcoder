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
using namespace std;
#define MOD (long long int)(1e9+7)
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
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;


void solve(){
	ll n; cin>>n;
	vector<ll> A, B, C;
	rep(i,n+1){
		ll a; cin>>a;
		A.PB(a);
	}
	rep(i,n){
		ll b; cin>>b;
		B.PB(b); C.PB(0);
	}
	B.PB(0); C.PB(0);

	ll ans = 0;
	rep(i,n){
		if((B[i]+C[i])>=A[i]){
			ans += A[i];
			if((C[i]-A[i])>=0){
				C[i+1] = B[i];
			}else{
				C[i+1] = B[i]+C[i]-A[i];
			}
			if(i==n-1){
				ans += min(A[n], B[n]+C[n]);
			}
		}else{
			ans += B[i] + C[i];
		}
		// cout << B[i+1] SP ans << endl;
	}
	cout << ans << endl;
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}

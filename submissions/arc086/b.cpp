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
#include <string>
#include <queue>
#include <deque>
#include <tuple>
#include <map>
#include <sstream>
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
const long double PI  = acos(-1.0L);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
#define chmax(a,b) a = (((a)<(b))?(b):(a))
#define chmin(a,b) a = (((a)>(b))?(b):(a))

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

ll mpow(ll a, ll b){
	if(b==0) return 1;
	else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
	else return mpow(a,b-1) * a % MOD;
}

signed main(){
  int n; cin>>n;
	int b = -1*INF,s = INF; bool p = true;
	int bx = 0, sx = 0;
	VI a(n);
	rep(i,n){
		cin>>a[i];
		if(b<a[i]){
			b = a[i]; bx = i;
		}
		if(s>a[i]){
			s = a[i]; sx = i;
		}
		if(a[i]<0) p = false;
	}
	if(p){
		cout << n-1 << endl;
		reps(i,n-1){
			cout << i SP i+1 << endl;
			a[i-1] += a[i+1];
		}
	}else{
		cout << 2*n-1 << endl;
		if(abs(b)>=abs(s)){
			reps(i,n){
				cout << bx+1 SP i << endl;
				a[i-1] += a[bx];
			}
			reps(i,n-1){
				cout << i SP i+1 << endl;
				a[i] += a[i-1];
			}
		}else{
			reps(i,n){
				cout << sx+1 SP i<< endl;
				a[i-1] += a[sx];
			}
			REPS(i,n-1){
				cout << i+1 SP i << endl;
				a[i-1] += a[i];
			}
		}
	}
	rep(i,n) cerr << a[i] << ' ';
	cerr << endl;


  return 0;
}

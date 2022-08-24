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

signed main(){
	int n,m; cin>>n>>m;
	ll dp[m+5][n+5][n+5]; CLR(dp);
	dp[0][1][1] = 1;
	rep(i,m+1){
		rep(j,n+1){
			rep(k,n+1){
				dp[i+1][j+1][k] += dp[i][j][k]*(n-j)%MOD; // �V�����X�ɍs��
				dp[i+1][j+1][k] %= MOD;
				dp[i+1][j][k] += dp[i][j][k]*(j-k)%MOD; // ���A���v�f�ɂȂ��Ȃ�
				dp[i+1][j][k] %= MOD;
				dp[i+1][j][j] += dp[i][j][k]*k%MOD; // ���A����
				dp[i+1][j][j] %= MOD;
			}
		}
	}
	cout << dp[m][n][n] << endl;

  return 0;
}

#include <bits/stdc++.h>
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
	ll n,k; cin>>n>>k;
	vector<vector<ll>> sushi(n);
	rep(i,n){
		int t; ll d; cin>>t>>d; t--;
		sushi[t].PB(d);
	}
	rep(t,n){
		sort(RALL(sushi[t]));
		if(sushi[t].empty()) sushi[t].PB(-INF);
	}
	sort(RALL(sushi));

	ll tmp = 0LL;
	priority_queue<ll> que;
	rep(i,k){
		tmp+=sushi[i][0];
		reps(j,sushi[i].size()-1) que.push(sushi[i][j]);
	}
	for(int i=k;i<n;i++) rep(j,sushi[i].size()) que.push(sushi[i][j]);

	ll ans=tmp+k*k;
	for(ll x=k-1;x>=1;x--){
		ll a=sushi[x][0], b=que.top();
		if(a<b){
			que.pop(); tmp+=b;
			que.push(a); tmp-=a;
		}
		chmax(ans,tmp+x*x);
	}
	cout<<ans<<endl;
	return 0;
}

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
	int h,w; cin>>h>>w;
	int a[h][w], b[h][w];
	const int max_k=(h+w)*80+5;
	rep(i,h) rep(j,w) cin>>a[i][j];
	rep(i,h) rep(j,w) cin>>b[i][j];
	bool dp[h][w][max_k]; memset(dp,false,sizeof(dp));
	const int dh[2]={1,0}, dw[2]={0,1};
	dp[0][0][abs(a[0][0]-b[0][0])]=true;
	rep(now_h,h)rep(now_w,w){
		rep(i,2){
			int next_h=now_h+dh[i], next_w=now_w+dw[i];
			if(next_h>=h||next_w>=w) continue;
			int d=abs(a[next_h][next_w]-b[next_h][next_w]);
			rep(k,max_k){
				if(!dp[now_h][now_w][k]) continue;
				if(k+d<max_k) dp[next_h][next_w][k+d]=true;
				if(abs(k-d)<max_k) dp[next_h][next_w][abs(k-d)]=true;
			}
		}
	}
	int ans=max_k;
	rep(k,max_k){
		if(dp[h-1][w-1][k]) return cout<<k<<endl,0;
	}
	cout<<ans<<endl;
	return 0;
}

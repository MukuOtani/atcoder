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


// ŠKæ‚â‘g‡‚í‚¹‚Ìê‡‚Ì”‚ð‹‚ß‚é
ll mpow(ll a, ll b, ll p){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2,p); return memo*memo%p;}
  else return mpow(a,b-1,p)*a%2019;
}


signed main(){
	int n; ll p; cin>>n>>p;
	string s; cin>>s;

	if(p==2||p==5){
		ll ans=0;
		rep(i,n){
			if((s[i]-'0')%p==0) ans+=i+1;
		}
		return cout<<ans<<endl,0;
	}

	VL cnt(p,0LL);
	ll keta = 1;
	ll cur = 0;
	rep(i,n){
		cur = (cur+(s[n-i-1]-'0')*keta)%p;
		keta = (keta*10)%p;
		cnt[cur]++;
	}

	ll ans = 0;
	rep(i,p) ans += cnt[i]*(cnt[i]-1)/2;
	ans += cnt[0];
	cout<<ans<<endl;

	return 0;
}

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
ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%2019;}
  else return mpow(a,b-1)*a%2019;
}


signed main(){
	string s; cin>>s;
	int n = s.size();
	VI a(n);
	a[0]=s[n-1]-'0';
	VL cnt(2019,0LL);
	cnt[a[0]]++;
	rep(i,n){
		if(i==0) continue;
		int next = s[n-i-1]-'0';
		a[i] = a[i-1]+mpow(10,i)*next;
		a[i] %= 2019;
		cnt[a[i]]++;
		cerr<<a[i]<<' ';
	}
	cerr<<endl;
	ll ans = 0;
	rep(i,2019){
		if(i==0) ans += cnt[i];
		ans += cnt[i]*(cnt[i]-1)/2;
	}
	cout<<ans<<endl;

	return 0;
}

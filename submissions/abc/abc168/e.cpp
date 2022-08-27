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
typedef pair<ll,ll> PLL;
typedef pair<double,double> PDD;
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

ll cost(int i, int s, VL &a){
	if(s==0||s==4) return a[i];
	else if(s==1||s==3){
		if(a[i]%2==0&&a[i]>0) return 0LL;
		else if(a[i]>0) return 1LL;
		else return 2LL;
	}else{
		if(a[i]%2LL==0LL) return 1LL;
		else return 0LL;
	}
}

ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==0){
		ll memo = mpow(a,b/2);
		return memo*memo%MOD;
	}else{
		return mpow(a,b-1)*a%MOD;
	}
}

signed main() {
	ll n; cin>>n;
	map<PLL, PLL> s;
	ll zeros=0LL;
	rep(i,n){
		ll a,b; cin>>a>>b;
		if(a==0&&b==0) zeros++;
		else if(a==0){
			s[MP(0,1)].first++;
		}else if(b==0){
			s[MP(0,1)].second++;
		}else{
			ll p=abs(a), q=abs(b);
			ll g=gcd(p,q); a/=g; b/=g;
			if((a>0&&b>0)||(a<0&&b<0)){
				a=abs(a); b=abs(b);
				s[MP(a,b)].first++;
			}else{
				a=abs(a); b=abs(b);
				s[MP(b,a)].second++;
			}
		}
	}

	ll ans=1LL;
	for(auto e: s){
		ll p = mpow(2,e.second.first)+mpow(2,e.second.second)-1LL%MOD;
		// cerr<<e.first.first SP e.first.second SP e.second.first SP e.second.second SP p<<endl;
		ans=(ans*p)%MOD;
	}
	cout<<(ans+zeros-1+MOD)%MOD<<endl;
	return 0;
}

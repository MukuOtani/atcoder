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
#define EPS (1e-10)
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

signed main(){
	int q; cin>>q;
	vector<pair<char,ll>> s;
	ll l = 0LL;
	int idx = 0;
	rep(i,q){
		int t; cin>>t;
		if(t==1){
			char c; ll x; cin>>c>>x;
			s.PB(MP(c,x)); l+=x;
		}else{
			// cerr<<"MODE 2"<<endl;
			ll d; cin>>d;
			int c[26]; CLR(c);
			// rep(i,s.size()) cerr<<s[i].first SP s[i].second<<endl;
			if(l){
				while(l&&d){
					if(s[idx].second>d){
						l-=d; c[s[idx].first-'a']+=d; s[idx].second-=d; d=0LL;
					}else{
						l-=s[idx].second; c[s[idx].first-'a']+=s[idx].second; d-=s[idx].second; s[idx].second=0LL; idx++;
					}
					// cerr<<idx SP s[idx].first SP s[idx].second<<endl;
				}
			}
			ll ans=0LL;
			rep(i,26) ans+=pow(c[i],2);
			cout<<ans<<endl;
			cerr<< l SP d<<endl;
		}
	}


	return 0;
}

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
	int n,q; string s; cin>>n>>s>>q;
	vector<set<int>> cnt;
	cnt.assign(26, set<int>({INF}));
	rep(i,n) cnt[s[i]-'a'].insert(i);

	rep(_,q){
		int type; cin>>type;
		if(type==1){
			int i; char c; cin>>i>>c; i--;
			cnt[s[i]-'a'].erase(i);
			s[i]=c; cnt[s[i]-'a'].insert(i);
		}else{
			int l,r; cin>>l>>r; l--;
			int ans=0;
			rep(c,26){
				if(cnt[c].empty()) continue;
				int lidx=*cnt[c].lower_bound(l);
				int ridx=*cnt[c].lower_bound(r);
				if(ridx>lidx) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

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
	int n; cin>>n;
	VI a(n); rep(i,n) cin>>a[i];
	vector<pair<int,PII>> q;
	rep(i,n){
		if(i-a[i]>0) q.PB(MP(i-a[i],MP(i,1)));
		if(i+a[i]<INF) q.PB(MP(i+a[i],MP(i,0)));
	}
	sort(ALL(q));
	ll ans=0, tmp=0;
	int m = q.size();
	int prev_num = 0, next_num=1;
	rep(i,m){
		next_num=q[i].first;
		if(prev_num==next_num){
			if(q[i].second.second==0) tmp++;
			else ans+=tmp;
		}else{
			if(q[i].second.second==0) tmp=1;
			else tmp=0;
		}
		prev_num = next_num;
		// cerr<<q[i].first SP q[i].second.first SP q[i].second.second SP tmp SP ans <<endl;
	}
	cout<<ans<<endl;
	return 0;
}

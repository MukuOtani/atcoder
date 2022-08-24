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


signed main(){
	int n,m; cin>>n>>m;
	VVI g; int h[n];
	rep(i,n){
		VI v; g.PB(v); h[i]=0;
	}
	int a[n+m-1],b[n+m-1];
	rep(i,n+m-1){
		cin>>a[i]>>b[i]; a[i]--; b[i]--; g[a[i]].PB(b[i]); h[b[i]]++;
	}
	stack<int> st; rep(i,n)if(h[i]==0) st.push(i);
	VI p;
	while(st.size()){
		int i=st.top(); st.pop();
		p.PB(i);
		for(auto& j: g[i]){
			h[j]--;
			if(h[j]==0) st.push(j);
		}
	}
	int rev[n]; rep(i,n) rev[p[i]]=i;
	// rep(i,n) cerr<<rev[i]<<' '; cerr<<endl;
	VI ans(n,p[0]); ans[p[0]]=-1;
	rep(i,n-1+m)if(rev[ans[b[i]]]<rev[a[i]]) ans[b[i]]=a[i];
	rep(i,n) cout<<ans[i]+1<<endl;


	return 0;
}

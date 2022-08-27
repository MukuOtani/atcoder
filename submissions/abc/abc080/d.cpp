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
	int n,c; cin>>n>>c;
	int w[100005]; CLR(w);
	vector<vector<PII>> b(c);
	VVI input;
	rep(i,n){
		VI v(3); cin>>v[1]>>v[0]>>v[2]; v[2]--;
		input.PB(v);
	}
	sort(ALL(input));
	rep(i,n){
		int s=input[i][1],t=input[i][0],c=input[i][2];
		if(b[c].size()==0){
			b[c].PB(MP(s,t));
		}else{
			int idx=b[c].size()-1;
			if(b[c][idx].second==s) b[c][idx].second=t;
			else b[c].PB(MP(s,t));
		}
	}
	cerr<<endl;
	rep(i,c){
		rep(j,b[i].size()){
			int s=b[i][j].first, t=b[i][j].second+1;
			// cerr<<i+1 SP s SP t<<endl;
			w[s]++; w[t]--;
		}
	}
	int ans=0, cnt=0;
	rep(i,100002){
		cnt+=w[i]; chmax(ans,cnt);
	}
	cerr<<endl;
	cout<<ans<<endl;
	return 0;
}

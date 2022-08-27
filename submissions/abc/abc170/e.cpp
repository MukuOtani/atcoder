#include <bits/stdc++.h>
using namespace std;
#define MOD (long long int)(998244353)
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

// ‘f”‚©‚Ç‚¤‚©‚Ì”»’è
bool IsPrime(ll num){
    if(num<2) return false;
    else if(num==2) return true;
    else if(num%2==0) return false; // ‹ô”‚Í‚ ‚ç‚©‚¶‚ßœ‚­
    double sqrtNum = sqrt(num);
    for(ll i=3; i<=sqrtNum; i+=2){
        if(num%i==0) return false;
    }
    return true;
}


signed main() {
	int n,q; cin>>n>>q;
	vector<priority_queue<PII>> r;
	priority_queue<PII, vector<PII>, greater<PII>> m;
	rep(i,200000){
		priority_queue<PII> q; r.PB(q);
	}
	VI a(n),b(n);
	rep(i,n){
		cin>>a[i]>>b[i]; b[i]--;
		r[b[i]].push(MP(a[i],i));
	}

	rep(i,200000){
		if(r[i].size()) m.push(MP(r[i].top().first,i));
	}

	while(q--){
		int c,d; cin>>c>>d; c--; d--;
		int past=b[c];
		b[c]=d;
		r[d].push(MP(a[c],c));
		while(r[past].size()&&b[r[past].top().second]!=past){
			r[past].pop();
		}
		while(r[d].size()&&b[r[d].top().second]!=d){
			r[d].pop();
		}
		m.push(MP(r[past].top().first,past));
		m.push(MP(r[d].top().first,d));
		while(r[m.top().second].empty()||r[m.top().second].top().first!=m.top().first){
			m.pop();
		}
		// if(r[d].top().second==c) m.push(r[d].top());
		cout<<m.top().first<<endl;
	}
	// rep(i,200000){
	// 	if(r[i].size()){
	// 		cout<< "kind" SP i<<endl;
	// 		while(r[i].size()){
	// 			cout<<r[i].top().first SP r[i].top().second<<endl;
	// 			r[i].pop();
	// 		}
	// 	}
	// }
	// while(m.size()){
	// 	cout<<m.top().first SP m.top().second<<endl;
	// 	m.pop();
	// }
	return 0;
}

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
typedef vector<VL> VVL;
#define chmax(a,b) a = (((a)<(b))?(b):(a))
#define chmin(a,b) a = (((a)>(b))?(b):(a))

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

signed main() {
	string s; cin>>s;
	int n = s.size();
	deque<char> d; bool hanten = false;
	rep(i,n){
		if(s[i]=='R'){
			hanten = !hanten;
		}else{
			if(hanten) d.push_front(s[i]);
			else d.push_back(s[i]);
		}
	}
	if(hanten) reverse(ALL(d));
	string t;
	for(char c: d){
		if(t.size() && t.back()==c) t.pop_back();
		else t.PB(c);
	}
	cout<<t<<endl;
	// char out='&';
	// if(hanten){
	// 	rep(i,n){
	// 		if(out==d.front()){
	// 			out='&';
	// 		}else{
	// 			if(out!='&') cout<<out;
	// 			out=d.front();
	// 		}
	// 		d.pop_front();
	// 	}
	// }else{
	// 	rep(i,n){
	// 		if(out==d.back()){
	// 			out='&';
	// 		}else{
	// 			if(out!='&') cout<<out;
	// 			out=d.back();
	// 		}
	// 		d.pop_back();
	// 	}
	// }
	// if(out!='&') cout<<out;
	// cout<<endl;

	return 0;
}

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
	int n; ll a,b,c; cin>>n>>a>>b>>c;
	vector<char> ans;
	vector<string> t;
	bool f[n+1][3];
	rep(i,n){
		string s; cin>>s; t.PB(s);
		f[i][0]=false; f[i][1]=false; f[i][2]=false;
		f[i][s[0]-'A']=true; f[i][s[1]-'A']=true;
		// cerr<<s[0]-'A' SP s[1]-'A'<<endl;
	}
	f[n][0]=false; f[n][1]=false; f[n][2]=false;
	rep(i,n){
		if(t[i]=="AB"){
			if(a>b){
				a--; b++; ans.PB('B');
			}else if(a<b){
				a++; b--; ans.PB('A');
			}else{
				if(f[i+1][0]){
					a++; b--; ans.PB('A');
				}else{
					a--; b++; ans.PB('B');
				}
			}
		}else if(t[i]=="AC"){
			if(a>c){
				a--; c++; ans.PB('C');
			}else if(a<c){
				a++; c--; ans.PB('A');
			}else{
				if(f[i+1][0]){
					a++; c--; ans.PB('A');
				}else{
					a--; c++; ans.PB('C');
				}
			}
		}else{
			if(b>c){
				b--; c++; ans.PB('C');
			}else if(b<c){
				b++; c--; ans.PB('B');
			}else{
				if(f[i+1][1]){
					b++; c--; ans.PB('B');
				}else{
					b--; c++; ans.PB('C');
				}
			}
		}
		if(a<0||b<0||c<0) return cout<<"No"<<endl,0;
	}
	cout<<"Yes"<<endl;
	rep(i,n) cout<<ans[i]<<endl;

	return 0;
}

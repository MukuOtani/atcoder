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
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
const long double PI  = acos(-1.0L);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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
	string s; cin>>s;
	int n = s.size();
	vector<string> d;
	char f = s[0]-'A'+'a';
	string next = "";
	next += (char)f;
	reps(i,n-1){
		if('A'<=s[i]&&s[i]<='Z'){
			cerr<<(char)(s[i]-'A'+'a');
			next += (char)(s[i]-'A'+'a');
			if(next.size()>1){
				d.PB(next);
				next = "";
			}
		}else{
			next += (char)s[i];
		}
	}
	cerr<<endl;
	sort(ALL(d));
	rep(i,d.size()) cerr<<d[i]<<' ';
	cerr<<endl;
	rep(i,d.size()){
		d[i][0] = (char)(d[i][0]-'a'+'A');
		d[i][d[i].size()-1] = (char)(d[i][d[i].size()-1]-'a'+'A');
		cout<<d[i];
	}
	cout<<endl;
	return 0;
}

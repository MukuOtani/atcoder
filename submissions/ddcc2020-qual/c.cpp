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
	int h,w,k; cin>>h>>w>>k;
	string s[h]; rep(i,h) cin>>s[i];
	int a[h][w]; CLR(a);
	int now=0;
	map<int,int> c;
	rep(i,h){
		rep(j,w){
			if(s[i][j]=='#') c[i]++;
		}
	}

	queue<int> z,q;
	rep(i,h){
		if(c[i]==0){
			z.push(i);
			continue;
		}
		q.push(i);
		int next=now+1;
		rep(j,w){
			a[i][j]=next;
			if(s[i][j]=='#') next=min(now+c[i],next+1);
		}
		now=next;
	}

	while(q.size()>1&&!z.empty()){
		if(z.front()<q.front()){
			rep(j,w) a[z.front()][j]=a[q.front()][j];
			z.pop();
		}else{
			q.pop();
		}
	}
	while(!z.empty()){
		rep(j,w) a[z.front()][j]=a[q.front()][j];
		z.pop();
	}

	rep(i,h){
		rep(j,w) cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}

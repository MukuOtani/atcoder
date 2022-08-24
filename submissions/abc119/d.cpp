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
	int a,b,q	; cin>>a>>b>>q;
	VL s(a+2,LINF), t(b+2,LINF), x(q); s[0]=-1*LINF; t[0]=-1*LINF;
	reps(i,a)cin>>s[i]; reps(i,b)cin>>t[i];	rep(i,q)cin>>x[i];
	// cerr << endl;
	// “ñ•ª’Tõ‚ÅA“Œ‘¤‚ÅÅ‚à‹ß‚¢_ŽÐ‚ÆŽ›‚Ìindex‚ð‹‚ß‚éB
	rep(i,q){
		int sl = 1, sr = a+2;
		while(sr-sl>1){
			int mid=(sl+sr)/2;
			if(s[mid]>=x[i]) sr=mid;
			else sl=mid;
		}
		int tl = 1, tr = b+2;
		while(tr-tl>1){
			int mid=(tl+tr)/2;
			if(t[mid]>=x[i]) tr=mid;
			else tl=mid;
		}
		// cerr << sr SP tr << endl; // ‚±‚±‚ª0‚È‚ç“ñ•ª’TõŽ¸”sB
		ll ks[2],kt[2]; ks[0]=s[sr-1]; ks[1]=s[sr]; kt[0]=t[tr-1]; kt[1]=t[tr];
		// cerr << x[i] SP ks[0] SP ks[1] SP kt[0] SP kt[1] << endl;
		ll ret = LINF*2;
		rep(j,2){
			rep(k,2){
				ll tmp1 = abs(x[i]-ks[j])+abs(ks[j]-kt[k]);
				ll tmp2 = abs(x[i]-kt[j])+abs(kt[j]-ks[k]);
				// cerr << tmp1 SP tmp2 << ' ';
				chmin(ret,min(tmp1,tmp2));
			}
		}
		// cerr<<endl;
		cout<<ret<<endl;
	}
	return 0;
}

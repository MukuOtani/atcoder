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
	int n; cin>>n;
	int k=-1;
	if(n==1){
		cout<<"Yes"<<endl<<2<<endl;
		rep(i,2) cout<<1 SP 1<<endl;
		return 0;
	}
	for(int i=1; i<=n; i++){
		if(i*(i-1)/2==n) k=i;
	}
	if(k==-1) return cout<<"No"<<endl,0;
	cout<<"Yes"<<endl<<k<<endl;
	int a[k-1];
	int t=1;

	cout<<k-1<<' ';
	reps(i,k-1){
		a[i-1]=t;
		cout<<a[i-1]<<' ';
		t+=i;
	}

	cout<<endl<<k-1<<' ';

	reps(i,k-2){
		int f=a[i];
		rep(j,i+1){
			cout<<f<<' ';
			f++;
		}
		f--;
		int add=i;
		rep(j,k-1-i-1){
			f+=add+1;
			cout<<f<<" ";
			add++;
		}
		cout<<endl<<k-1<<' ';
	}



	int f=1;

	reps(i,k-1){
		cout<<f<<' ';
		f+=i+1;
	}
	cout<<endl;

	return 0;
}

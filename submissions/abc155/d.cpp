#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <limits>
#include <list>
#include <string>
#include <queue>
#include <deque>
#include <tuple>
#include <map>
#include <sstream>
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
#define SORT(c) sort(ALL(x))
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

ll N,K;

bool judge_m(ll mid, VL &p, VL &n){
	ll sum=0LL;
	rep(i,p.size()){
		ll d=(mid-p[i]+1)/p[i];
		sum+=upper_bound(ALL(n),d)-n.begin();
	}
	return sum>=K;
}

bool judge_p(ll mid, VL &p, VL &n){
	ll sum=0LL;
	rep(i,p.size()){
		ll d=mid/p[i];
		ll tmp=upper_bound(ALL(p),d)-p.begin();
		if(i<tmp) tmp--;
		sum+=tmp;
	}
	rep(i,n.size()){
		ll d=mid/n[i];
		ll tmp=upper_bound(ALL(n),d)-n.begin();
		if(i<tmp) tmp--;
		sum+=tmp;
	}
	sum/=2;
	return sum>=K;
}

signed main(){
  cin>>N>>K;
	VL p,n; ll zero=0LL;

	rep(i,N){
		ll a; cin>>a;
		if(a>0) p.PB(a);
		else if(a<0) n.PB(a);
		else zero++;
	}
	sort(ALL(p)); sort(ALL(n));
	// ll posi=pow(p.size(),2LL)+pow(n.size(),2LL)+N-zero;
	ll nega=p.size()*n.size();
	zero=zero*(zero-1)/2+zero*(N-zero);

	if(K<=nega){
		ll l=-1e18-1, u=-1;
		while(u-l>1){
			ll mid=(l+u)/2;
			if(judge_m(mid,p,n)) u=mid;
			else l=mid;
		}
		cout<<u<<endl;
	}else if(K<=nega+zero){
		cout<<0<<endl;
	}else{
		K-=nega+zero;
		rep(i,n.size()) n[i]*=-1;
		sort(ALL(n));
		ll l=-1, u=1e18;
		while(u-l>1){
			ll mid=(l+u)/2;
			if(judge_p(mid,p,n)) u=mid;
			else l=mid;
		}
		cout<<u<<endl;
	}

  return 0;
}

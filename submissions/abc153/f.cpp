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

vector<pair<ll,ll>> p;

// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (p[index].first > key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)p.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


signed main(){
	int n; ll d,a; cin>>n>>d>>a;
	rep(i,n){
		ll x,h; cin>>x>>h; p.PB(MP(x,h));
	}
	p.PB(MP(LINF,0LL));
	sort(ALL(p));
	VI idx(n); // x[i]を左端に爆発させたときの右端のindex
	rep(i,n) idx[i]=binary_search(p[i].first+2*d)-1; // 二分探索

	// rep(i,n) cerr<<idx[i]<<' ';
	// cerr<<endl;

	ll ans=0,cnt=0; queue<pair<int,long>> q;
	// cnt:累積の爆風
	rep(i,n){
		ll x=p[i].first, h=p[i].second;
		while(q.size()&&q.front().first<x){
			cnt-=q.front().second; // 到達しない爆風は減らす
			q.pop();
		}
		ll need=max((h+a-1)/a-cnt,0LL);
		ans+=need; cnt+=need; // x[i]で爆発させた分は累積させる
		q.push(MP(p[idx[i]].first,need));
	}
	cout<<ans<<endl;
	return 0;
}

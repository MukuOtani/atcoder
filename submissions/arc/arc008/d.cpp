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

template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid UNITY;
    int SIZE_R;
    vector<Monoid> dat;

    SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity) { init(n); }
    void init(int n) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, UNITY);
    }

    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[k*2], dat[k*2+1]);
    }

    /* update, a is 0-indexed */
    void update(int a, const Monoid &v) {
        int k = a + SIZE_R;
        dat[k] = v;
        while (k >>= 1) dat[k] = F(dat[k*2], dat[k*2+1]);
    }

    /* get {min-value, min-index}, a and b are 0-indexed */
    Monoid get(int a, int b) {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);
        }
        return F(vleft, vright);
    }
    inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

    /* debug */
    void print() {
        for (int i = 0; i < SIZE_R; ++i) {
            cout << (*this)[i];
            if (i != SIZE_R-1) cout << ",";
        }
        cout << endl;
    }
};

signed main(){
	ll n; int m; cin>>n>>m;
	vector<ll> p(m), pls; vector<double> a(m), b(m);
	rep(i,m){
		cin>>p[i]>>a[i]>>b[i]; p[i]--; pls.PB(p[i]);
	}
	sort(ALL(pls));
	pls.erase(unique(ALL(pls)),pls.end());
	int nn=(int)pls.size();

	SegTree<pair<double,double>> seg(nn,
																	[](pair<double,double> a, pair<double,double> b){
																			return MP(a.first*b.first, a.second*b.first+b.second);
																	},
																	MP(1,0)
																);
	double Min=1.0, Max=1.0;
	rep(i,m){
		int idx=lower_bound(ALL(pls), p[i])-pls.begin();
		seg.update(idx,MP(a[i],b[i]));
		pair<double,double> res=seg.get(0,nn);
		chmin(Min, res.first+res.second);
		chmax(Max, res.first+res.second);
	}
	cout<<Min<<endl<<Max<<endl;

	return 0;
}

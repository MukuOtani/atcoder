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
#include <queue>
#include <tuple>
#include <map>
#include <set>
#include <sstream>
using namespace std;
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
#define chmax(a, b) a = (((a)<(b))?(b):(a))
#define chmin(a, b) a = (((a)<(b))?(a):(b))

const int INF = 1001001001;
const ll MOD = 1e9+7;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){std::fill((T*)array, (T*)(array+N),val);}

class CompareDist
{
public:
    bool operator()(PLL n1,PLL n2) {
				if(n1.first!=n2.first) return n1.first<n2.first;
				else return n1.second<n2.second;
    }
};

#define lengthof(x) (sizeof(x) / sizeof(*(x)))


__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

bool contain(int mask, int position){
  if((mask&(1<<position))) return true;
  else return false;
}


signed main(){
	int n; cin>>n;
  VL c(n);
  ll min_2 = LINF, min_3 = LINF;
  rep(i,n){
    ll m; cin>>m;
    if(i%2==0) min_2 = min(min_2,m);
    min_3 = min(min_3,m);
    c[i]=m;
  }
  // cerr << min_2 SP min_3 << endl;
  int q; cin>>q;
  ll ans = 0;
  ll tmp_2 = 0, tmp_3 = 0;
  rep(i,q){
    ll m,x,a; cin>>m;
    if(m==1){
      cin>>x>>a;
      x--;
      if(x%2==0){
        if(c[x]>=a+tmp_2+tmp_3){
          chmin(min_2,c[x]-tmp_2-tmp_3-a);
          chmin(min_3,c[x]-tmp_2-tmp_3-a);
          // if(c[x]-tmp_2-tmp_3-a<=min_2) min_2=c[x]-tmp_2-tmp_3-a;
          // if(c[x]-tmp_2-tmp_3-a<=min_3) min_3=c[x]-tmp_2-tmp_3-a;
          c[x]-=a; ans+=a;
        }
      }else{
        if(c[x]>=a+tmp_3){
          chmin(min_3,c[x]-tmp_3-a);
          // if(c[x]-tmp_3-a<=min_3) min_3=c[x]-tmp_3-a;
          c[x]-=a; ans+=a;
        }
      }

      // if(c[x]>=a+tmp_2+tmp_3){
      //   if(min_3==c[x]-(tmp_2+tmp_3)) min_3-=a;
      //   if(x%2==0&&min_2==c[x]-tmp_2) min_2-=a;
      //   c[x]-=a, ans+=a;
      // }
    }else if(m==2){
      cin>>a;
      if(min_2>=a){
        // for(int i=0;i<n;i+=2){
        //   c[i]-=a;
        // }
        min_2-=a; ans+=a*((n+1)/2); tmp_2+=a;
        if(min_2<min_3) min_3=min_2;
      }
    }else{
      cin>>a;
      if(min_3>=a){
        // rep(i,n) c[i]-=a;
        ans+=a*n; tmp_3+=a;
        min_3-=a; min_2-=a;
      }
    }
    // cerr << i SP min_2 SP min_3 SP ans << endl;
  }
  cout << ans << endl;
  return 0;
}

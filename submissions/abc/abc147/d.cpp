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
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
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


__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

// long long int sumXOR(int arr[], int n)
// {
//     long long int sum = 0;
//     for (int i = 0; i < 32; i++)
//     {
//         int zc = 0, oc = 0;
//         long long int idsum = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] % 2 == 0)
//                 zc++;
//             else
//                 oc++;
//             arr[j] /= 2;
//         }
//         idsum = oc * zc * (1 << i);
//         sum += idsum;
//     }
//     return sum;
// }


signed main(){
	ll n; cin>>n;
  ll bits[62];
  ll ans = 0;
  rep(i,62) bits[i] = 0;
  rep(i,n){
    ll a; cin>>a;
    rep(j,61){
      if(a%2==0) bits[j]++;
      a /= 2;
    }
  }
  ll keta = 1;
  rep(i,62){
    ll sum = (bits[i]*(n-bits[i]))%MOD;
    sum = (sum*keta)%MOD;
    if(sum<0) sum += MOD;
    keta = (keta*2)%MOD;
    if(keta<0) keta += MOD;
    ans = (ans+sum)%MOD;
  }
  ans = (ans+MOD)%MOD;
  cout << ans << endl;

  return 0;
}

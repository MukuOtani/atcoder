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
const double PI  = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

bool IsPrime(int num){
    if(num < 2) return false;
    else if(num == 2) return true;
    else if(num % 2 == 0) return false; // ‹ô”‚Í‚ ‚ç‚©‚¶‚ßœ‚­

    double sqrtNum = sqrt(num);
    for(int i = 3; i <= sqrtNum; i += 2){
        if(num%i==0){
            // ‘f”‚Å‚Í‚È‚¢
            return false;
        }
    }
    // ‘f”‚Å‚ ‚é
    return true;
}

const int lim = 100000;

signed main(){
  int q; cin>>q;
  int l[q], r[q];
  rep(i,q) cin>>l[i]>>r[i];
  bool check[lim+1];
  check[0] = false;
  reps(i,lim){
    if(IsPrime(i)) check[i] = true;
    else check[i] = false;
  }
  int nums[lim+1]; CLR(nums);
  reps(i,lim){
    nums[i] = nums[i-1];
    if(!i%2) continue;
    if(check[i]&&check[(i+1)/2]) nums[i]++;
  }
  rep(i,8) cerr << i SP ':' SP check[i] SP nums[i] SP IsPrime(i) << endl;
  cerr << endl;
  rep(i,q){
    cout << nums[r[i]]-nums[l[i]-1] << endl;
  }



  return 0;
}

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

signed main(){
	int n; cin>>n;
  VI d(n);
  rep(i,n){
    cin>>d[i];
    if(d[i]==0) return cout<<0<<endl, 0;
  }
  int cnt[12]; CLR(cnt);
  rep(i,n){
    if(d[i]==0) continue;
    cnt[d[i]%12]++;
  }
  VI clock;
  int flg = 1;
  clock.PB(12);
  reps(i,11){
    if(cnt[i]>2) return cout<<0<<endl, 0;
    else if(cnt[i]==2){
      clock.PB(12-i); clock.PB(12+i);
    }else if(cnt[i]==1){
      clock.PB(12+flg*i); flg *= -1;
    }
  }
  if(cnt[0]) clock.PB(0);
  sort(ALL(clock));
  int s = 24;
  int l = clock.size();
  if(l==1) return cout<<0<<endl, 0;
  rep(i,l-1){
    cerr << clock[i] << ' ';
    s = min(s,clock[i+1]-clock[i]);
  }
  cerr << clock[l-1] <<  endl;
  s = min(s,24+clock[0]-clock[l-1]);
  cout << s << endl;

	return 0;
}

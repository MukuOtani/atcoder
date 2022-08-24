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

ll wa(ll x){
  return x*(1+x)/2;
}


signed main(){
	string s; cin>>s;
  ll n = s.size();
  ll l = 0, g = 0, ans = 0;
  queue<ll> L, G;
  rep(i,n-1){
    if(s[i]=='>') l++;
    else g++;

    if(s[i]!=s[i+1]){
      if(l){
        L.push(l);
        cerr << -l << endl;
        l=0;
      }else{
        G.push(g);
        cerr << g << endl;
        g=0;
      }
    }
  }
  if(s[n-1]=='<') G.push(g+1), cerr<<g+1<<endl;
  else L.push(l+1), cerr<<-l-1<<endl;

  cerr << "INPUT END"<< endl;
  if(s[0]=='>') ans+=wa(L.front()), L.pop();
  while(!L.empty()&&!G.empty()){
    l=L.front(); L.pop();
    g=G.front(); G.pop();
    ans += wa(max(g,l))+wa(min(g,l)-1);
    cerr << ans << ' ';
  }
  if(s[n-1]=='<') ans+=wa(G.front()), G.pop();
  cerr << endl;
  cout << ans << endl;

  return 0;
}

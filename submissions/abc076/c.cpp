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

signed main(){
  string s,t; cin>>s>>t;
	vector<string> ans;
	int n=s.size(), m=t.size();
	rep(i,n-m+1){
		cerr << i SP s[i] << endl;
		rep(j,m){
			if(s[i+j]!='?'&&s[i+j]!=t[j]) j=m;
			if(j==m-1){
				cerr << i SP "found" <<endl;
				string kouho = s;
				for(int k=i;k<i+m;k++) kouho[k]=t[k-i];
				cerr << kouho << endl;
				rep(k,n) if(kouho[k]=='?') kouho[k]='a';
				ans.PB(kouho);
				cerr << kouho << endl;
			}
		}
	}
	if(ans.size()){
		sort(ALL(ans)); cout<<ans[0]<<endl;
	}else{
		cout<<"UNRESTORABLE"<<endl;
	}
  return 0;
}

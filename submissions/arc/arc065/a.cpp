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
	string s; cin>>s; int n=s.size();
	rep(i,n/2){
		char c = s[i]; s[i] = s[n-1-i]; s[n-i-1] = c;
	}
	rep(i,n){
		if(s[i]=='m'){
			if(i+4>n||s[i+1]!='a'||s[i+2]!='e'||s[i+3]!='r'||s[i+4]!='d') return cout<<"NO"<<endl,0;
			else i+=4;
		}else if(s[i]=='e'){
			if(i+4>n||s[i+1]!='s'||s[i+2]!='a'||s[i+3]!='r'||s[i+4]!='e') return cout<<"NO"<<endl,0;
			else i+=4;
		}else if(s[i]=='r'){
			if(i+5>n||s[i+1]!='e') return cout<<"NO"<<endl,0;
			if(s[i+2]=='m'){
				if(i+6>n||s[i+3]!='a'||s[i+4]!='e'||s[i+5]!='r'||s[i+6]!='d') return cout<<"NO"<<endl,0;
				else i+=6;
			}else if(s[i+2]=='s'){
				if(s[i+3]!='a'||s[i+4]!='r'||s[i+5]!='e') return cout<<"NO"<<endl,0;
				else i+=5;
			}
		}else{
			return cout<<"NO"<<endl,0;
		}
	}
	cout<<"YES"<<endl;

  return 0;
}

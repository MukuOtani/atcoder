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
	int n,m; cin>>n>>m;
  VVI A;
	rep(i,n){
		int a,b; cin>>a>>b;
		VI H;
		if(a<=m){
			H.PB(a); H.PB(b); A.PB(H);
		}
	}
	int ans = 0;
	n = A.size();



	if(n!=0){
		sort(ALL(A));
		// rep(i,n){
		// 	cout << A[i][0] SP A[i][1] << endl;
		// }
		priority_queue<int> q;
		int idx = 0;
		int day = 1;
		while(day<=m){
			if(idx<n){
				while(A[idx][0]<=day){
					// cout << idx << endl;
					q.push(A[idx][1]); idx++;
					if(idx==n) break;
				}
			}

			if(q.size()!=0){
				ans += q.top(); q.pop();
				// cout << ans << endl;
			}
			// cout << day SP idx SP ans SP q.size() << endl;
			day++;

		}
	}

	cout << ans << endl;

	return 0;
}

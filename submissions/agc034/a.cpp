#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define ALL(x) (x).begin(),(x).end()
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)

int main(){
	int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
	string S; cin >> S;
	bool check = true;
	for(int i=A; i<max(C,D)-2; i++){
		if((S[i]=='#')&&(S[i+1]=='#')){
			check = false;
			i = INF;
			break;
		}
	}
	if(D<C && check){
		check = false;
		for(int i=B-2; i<D-1; i++){
			if(S[i]=='.'&&S[i+1]=='.'&&S[i+2]=='.'){
				check = true;
				i = INF;
				break;
			}
		}
	}
	if(check){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}

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
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()


template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

int main(){
	int N; cin >> N;
	vector<ll> P, M;
	rep(i,N){
		ll a; cin >> a;
		if(a>0){
			P.push_back(a);
		}else{
			M.push_back(-a);
		}
	}
	sort(all(P), greater<ll>());
	sort(all(M), greater<ll>());
	ll x[N-1], y[N-1]; ll ans;
	int i = 0;
	if(N==2){
		if((P.size()==1)&&(M.size()==1)){
			cout << P[0]+M[0] << endl;
			cout << P[0] << ' ' << -M[0] << endl;
		}else if(P.size()==2){
			cout << P[0]-P[1] << endl;
			cout << P[0] << ' ' << P[1] << endl;
		}else{
			cout << M[0]-M[1] << endl;
			cout << -M[1] << ' ' << -M[0] << endl;
		}
	}else{
		if(P.size()==0){
			x[i] = -M[M.size()-1]; y[i] = -M[M.size()-2];
			P.push_back(x[i]-y[i]);
			remove(M, M.size()-1); remove(M, M.size()-1);
			i++;
		}
		if(M.size()>0){
			while(P.size()>1){
				x[i] = -M[0]; y[i] = P[0];
				M.push_back(M[0]+P[0]);
				remove(P, 0); remove(M, 0);
				i++;
			}
			while(i<N-1){
				x[i] = P[0]; y[i] = -M[0];
				P[P.size()-1] += M[0];
				remove(M, 0);
				i++;
			}
		}else{
			// if(N%2==1){
			// 	while(P.size()>1){
			// 		x[i] = P[P.size()-1]; y[i] = P[0];
			// 		remove(P, P.size()-1); remove(P, 0);
			// 		M.push_back(y[i]-x[i]);
			// 		i++;
			// 	}
			// 	while(M.size()>0){
			// 		x[i] = P[0]; y[i] = -M[0];
			// 		P[0] = x[i] - y[i];
			// 		remove(M, 0);
			// 		i++;
			// 	}
			// }else{
			// 	while(P.size()>0){
			// 		x[i] = P[P.size()-1]; y[i] = P[0];
			// 		M.push_back(y[i]-x[i]);
			// 		i++;
			// 		remove(P, P.size()-1); remove(P, 0);
			// 	}
			// 	sort(all(M), greater<ll>());
			// 	x[i] = -M[M.size()-1]; y[i] = -M[0];
			// 	P.push_back(x[i]-y[i]);
			// 	remove(M, M.size()-1); remove(M, 0);
			// 	i++;
			// 	while(M.size()>0){
			// 		// x[i] = -M[M.size()-1]; y[i] = -M[0];
			// 		// P.push_back(x[i]-y[i]);
			// 		// remove(M, M.size()-1); remove(M, 0);
			// 		// i++;
			// 		x[i] = P[0]; y[i] = -M[0];
			// 		P[0] += M[0];
			// 		remove(M, 0);
			// 		i++;
			// 	}
			// }
			x[i] = P[P.size()-1]; y[i] = P[P.size()-2];
			M.push_back(y[i]-x[i]);
			remove(P, P.size()-1); remove(P, P.size()-1);
			i++;
			while(P.size()>1){
				x[i] = -M[0]; y[i] = P[P.size()-1];
				M[0] += P[P.size()-1];
				i++;
				remove(P, P.size()-1);
			}
			x[i] = P[0]; y[i] = -M[0];
			P[0] += M[0];
		}

		cout << P[P.size()-1] << endl;
		rep(i,N-1){
			cout << x[i] << ' ' << y[i] << endl;
		}
	}

	return 0;
}

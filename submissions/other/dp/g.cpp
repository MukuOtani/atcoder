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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(123456789012345678)
#define MAX_V 1000



vector<int> G[100100];	// グラフ　G[i]: から有効辺で繋がっている点を列挙したリスト
// メモ化再帰
int dp[100100];	//dp[i]: iから始めた時の最長の有効パスの長さ
int rec(int now_v) {	// vから始めた時の最長の有効パスの長さを求める
	if (dp[now_v] != -1)	return dp[now_v];	// すでに更新済み
	int max_len = 0;
	rep(i, G[now_v].size()) {
		int next_v = G[now_v][i];
		chmax(max_len, rec(next_v)+1);
	}
	return dp[now_v] = max_len;	// メモしながらリターン
}

int main() {
	// 入力受け取り
	int N, M;	cin >> N >> M;
	rep(i, M) {
		int x, y;	cin >> x >> y;
		G[x].push_back(y);
	}

	// 初期化
	reps(v, N) dp[v] = -1;

	// 全ノードを一通り更新しながら答えを求める
	int res = 0;
	reps(v, N) chmax(res, rec(v));
	cout << res << endl;
	return 0;
}

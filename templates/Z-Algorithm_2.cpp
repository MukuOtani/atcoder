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
#include <stack>
#include <set>
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

const int N = (int)3e5;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll lpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
  else return lpow(a,b-1) * a;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
vector<ll> gyaku_kaijo_memo;
ll gyaku_kaijo(ll n){
  if(gyaku_kaijo_memo.size() > n) return gyaku_kaijo_memo[n];
  if(gyaku_kaijo_memo.size() == 0) gyaku_kaijo_memo.push_back(1);
  while(gyaku_kaijo_memo.size() <= n) gyaku_kaijo_memo.push_back(gyaku_kaijo_memo[gyaku_kaijo_memo.size()-1] * mpow(gyaku_kaijo_memo.size(), MOD-2) % MOD);
  return gyaku_kaijo_memo[n];
}

ll nCr(ll n, ll r){
  if(n == r) return 1;//0個の丸と-1個の棒みたいな時に時に効く？不安.
  if(n < r || r < 0) return 0;
  ll ret = 1;
  ret *= kaijo(n); ret %= MOD;
  ret *= gyaku_kaijo(r); ret %= MOD;
  ret *= gyaku_kaijo(n-r); ret %= MOD;
  return ret;
}

int nn,kk;
int ranks[N + 1];
int tmp[N + 1];

//(ranks[i], ranks[i+k])と(ranks[j], ranks[j+k])を比較
bool compare_sa(int i, int j){
  if(ranks[i] != ranks[j]) return ranks[i] < ranks[j];
  else{
    int ri = i + kk <= nn ? ranks[i+kk] : -1;
    int rj = j + kk <= nn ? ranks[j+kk] : -1;
    return ri < rj;
  }
}

//文字列Sの接尾辞配列を構築 O(n(log n)^2)
void construct_sa(string S, int *sa){
  nn = S.length();

  //最初は1文字, ランクは文字コードにすれば良い
  rep(i, nn+1){
    sa[i] = i;
    ranks[i] = i < nn ? S[i] : -1;
  }

  //k文字についてソートされているところから, 2k文字でソートする
  for(kk=1; kk<=nn; kk*=2){
    sort(sa, sa+nn+1, compare_sa);

    //いったんtmpに次のランクを計算し, それからranksに移す
    tmp[sa[0]] = 0;
    reps(i,nn){
      tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
    }
    rep(i,nn+1){
      ranks[i] = tmp[i];
    }
  }
}

//S内にTが登場するか判定 O(|T|log|S|)
bool contain(string S, int *sa, string T){
  int a = 0, b = S.length();
  while(b - a > 1){
    int c = (a + b) / 2;
    //Sのsa[c]文字目から|T|文字とTを比較
    if(S.compare(sa[c], T.length(), T) < 0) a = c;
    else b = c;
  }
  return S.compare(sa[b], T.length(), T) == 0;
}

//文字列Sとその接尾辞配列saを受け取り, 高さ配列をlcpに計算
void construct_lcp(string S, int *sa, int *lcp){
  int n = S.length();
  rep(i,n+1){
    ranks[sa[i]] = i;
  }

  int h = 0;
  lcp[0] = 0;
  rep(i,n){
    //文字列中での位置iの接尾辞と,接尾辞配列中でその1tう前の接尾辞のLCPを求める.
    int j = sa[ranks[i] - 1];

    //hを先頭の分1減らし, 後ろが一致しているだけ増やす
    if(h>0) h--;
    for(; j+h<n && i+h<n; h++){
      if(S[j+h] != S[i+h]) break;
    }

    lcp[ranks[i] - 1] = h;
  }
}

//KMPのための前計算 O(|S|)
//mp[i] = S[0,i-1]のx文字接頭辞とx文字接尾辞が一致するような最大のx(ただしx=iは除く)
//mp[0] = -1であり, 1_indexのようなもの
void construct_mp(const string& S, int *mp){
  int n = S.size();
  mp[0] = -1;
  int j = -1;
  rep(i,n){
    while(j >= 0 && S[i] != S[j]) j = mp[j];
    mp[i+1] = ++j;
  }
}

//Sの連続部分文字列のうち, Tと一致する文字列の始点のidxリストを返す
//O(|S|)
vector<int> kmp(const string& S, const string& T){
  int mp[S.size()+1];
  construct_mp(T, mp);
  vector<int> ret;
  int m=0, i=0, n=S.size();
  while(m+i < n){
    if(T[i] == S[m+i]){
      if(++i == (int)(T.size())){
        ret.push_back(m);
        m = m+i-mp[i];
        i = mp[i];
      }
    }else{
      m = m+i-mp[i];
      if(i > 0) i = mp[i];
    }
  }
  return ret;
}

//文字iを中心とする最長の回文の半径
//abaaababa
//121412321
//偶数回文を求めたいときはダミー文字を挟んで対応 abba -> a$b$b$a
//O(|S|)
vector<int> manacher(const string& S){
  vector<int> ret(S.size());
  int i = 0, j = 0;
  while (i < S.size()) {
    while (i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
    ret[i] = j;
    int k = 1;
    while (i-k >= 0 && i+k < S.size() && k+ret[i-k] < j) ret[i+k] = ret[i-k], ++k;
    i += k; j -= k;
  }
  return ret;
}

//SとS[i:]の最長共通接頭辞の長さ
//aaabaaaab
//921034210
//O(|S|)
vector<int> Zalgo(const string& S){
  vector<int> Z(S.size());
  Z[0] = S.size();
  int i = 1, j = 0;
  while (i < S.size()) {
    while (i+j < S.size() && S[j] == S[i+j]) ++j;
    Z[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < S.size() && k+Z[k] < j) Z[i+k] = Z[k], ++k;
    i += k; j -= k;
  }
  return Z;
}

int main(void){
  string S = "abcbabcab";
  string T = "bc";
  int n = S.size();

  //接尾辞(空文字列も含む)を辞書順ソートしてそのidxを順に並べた配列
  int sa[n+1];
  construct_sa(S, sa);

  //Sのsa[i]文字目以降 と Sのsa[i+1]文字目以降 について 先頭から共通している長さ
  int lcp[n+1];
  construct_lcp(S, sa, lcp);

  //mp[i] = S[0,i-1]のx文字接頭辞とx文字接尾辞が一致するような最大のx(ただしx=iは除く)
  int mp[n+1];
  construct_mp(S, mp);

  //Sの連続部分文字列のうち, Tと一致する文字列の始点のidxリストを返す
  vector<int> eq = kmp(S,T);

  //文字iを中心とする最長の回文の半径
  vector<int> mana = manacher(S);

  //SとS[i:]の最長共通接頭辞の長さ
  vector<int> Z = Zalgo(S);


  return 0;
}

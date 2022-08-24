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

bool IsPrime(ll num){
    if(num < 2) return false;
    else if(num == 2) return true;
    else if(num % 2 == 0) return false; // �����͂��炩���ߏ���

    double sqrtNum = sqrt(num);
    for(ll i = 3; i <= sqrtNum; i += 2){
        if(num%i==0){
            // �f���ł͂Ȃ�
            return false;
        }
    }
    // �f���ł���
    return true;
}

ll llabs(ll a, ll b){
  if(a>=b) return a-b;
  else return b-a;
}

ll llmax(ll a, ll b){
  if(a>=b) return a;
  else return b;
}

ll llmin(ll a, ll b){
  if(a<=b) return a;
  else return b;
}


// �~��P�Ԗڂ܂ł͊m���ɍ̗p�����
// ��΂ɖ��Z�b�g�ɍ̗p����Ȃ����F�W���b�W�S�����_�������Ă��~��P�Ԗڂɓ_��������Ȃ��ꍇ
// ���̂Ƃ��A���̖��ւ̓��[�́A�~��P�Ԗږ����̖��
// V���I�ԁF����V-1��ڂ܂ł̏ꍇ�́A���̖��ɓ��[����ꍇ���l���Ȃ��Ă͂����Ȃ��@���@�s�v�H�H�H�H
// �����ō~��P�Ԗڂ̖��̓_���Ɣ�r����K�v�����肻��

// �W���b�W�ɂ��ő�+m�_�����Z�����
// �~��P�Ԗڂ̖��ɉ��_����Ă��܂��̂́AV>P�̂Ƃ�

// ���ꂽ�����ɂ́A�S�����_�������΂���
// i�Ԗڂ̖�������Ƃ���
// ����ȊO�̓_���̐U����́A�~����P-1�Ԗڂ܂ł̖�聄���ꂽ�������������ő������
// ����Ƃ��F(p-1)+i < v �̂Ƃ�(�\����������̖��ɓ_�����Ȃ���΂����Ȃ��Ƃ�)

signed main(){
  VVI c;
  VI t(3);
  rep(i,3){
    VI d(3); rep(j,3) cin>>d[j]; c.PB(d);
    t[i] = 0;
  }
  rep(i,3){
    rep(j,3){
      t[(i+j)%3] += c[i][j];
    }
  }
  cerr << t[0] SP t[1] SP t[2] << endl;
  if(t[0]==t[1]&&t[1]==t[2]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

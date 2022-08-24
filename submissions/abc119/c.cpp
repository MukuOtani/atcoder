#include <iostream>
#include <cstring>
#include <cmath>
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
#include <numeric>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(123456789012345678)


unsigned GetDigit(unsigned num) {
    return std::to_string(num).length();
}


int main(void){
	int N, A, B, C; cin >> N >> A >> B >> C;
  int ans = INF;
  vector<int> end;  // �ړI�Ƃ��钷���̃��X�g
  end.push_back(A);
  end.push_back(B);
  end.push_back(C);
  int l[N];
  rep(i, N) cin >> l[i];

  // N����4�i���ɂ��čl����
  int max_cnt = std::pow(4, N);
  
  // 1����4**N�܂�
  rep(i, max_cnt)  {
    
    // ������4�̃��X�gassign�ɁAA,B,C,���g�p�̒|�̒��������蓖�Ă�
    vector<vector<int> > assign;
    assign.resize(4);
    
    int cnt = i;
    rep(j, N) {
      // 4�i���ŕ\�������̈�ԉ��̌�������
      assign[cnt%4].push_back(l[j]);
      // ��ԉ��̌��𔲂�
      cnt = cnt/4;
    }
    if (assign[0].size()!=0 && assign[1].size()!=0 && assign[2].size()!=0)  {
      int cost = 0; // ����ɕK�v�ȃR�X�g
      rep(i, 3) {
        cost += (assign[i].size()-1) * 10;  // merge�̑���
        cost += abs(end[i] - std::accumulate(assign[i].begin(), assign[i].end(), 0)); // �����̒���
      }
      ans = min(ans, cost); // �R�X�g�̏�������������
    }
  }
  cout << ans << endl;
	return 0;
}

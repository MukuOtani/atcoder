#include <bits/stdc++.h>
using namespace std;

int main() {
  // �ϐ�a,b,c��true�܂���false��������AtCoder�Əo�͂����悤�ɂ���B
  bool a = true; // true or false
  bool b = false; // true or false
  bool c = true; // true or false

  // ���������͕ύX���Ȃ�����

  if (a) {
    cout << "At";
  }
  else {
    cout << "Yo";
  }

  if (!a && b) {
    cout << "Bo";
  }
  else if (!b || c) {
    cout << "Co";
  }

  if (a && b && c) {
    cout << "foo!";
  }
  else if (true && false) {
    cout << "yeah!";
  }
  else if (!a || c) {
    cout << "der";
  }

  cout << endl;
}

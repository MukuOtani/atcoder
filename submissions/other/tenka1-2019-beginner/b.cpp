#include <iostream>

#include <string>

using namespace std;

string leet(string, int, int);    // �ϊ��֐�

int main(){
		int N;	cin >> N;
    string str;	cin >> str;
		int K;	cin >> K;
    str = leet(str, N, K);
    cout << str << endl;
    return 0;
}

// �ϊ��֐�

string leet(string str, int size, int tgt){

    for(int i=0;i<size;++i)

        if(str[i]!=str[tgt-1]) str[i]='*';

    return str;

};

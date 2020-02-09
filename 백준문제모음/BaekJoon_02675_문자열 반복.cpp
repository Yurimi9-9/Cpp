// 백준 2675 - 문자열 반복
#include <iostream>

using namespace std;

int main()
{
	int T=0;	// testcase 개수
	cin >> T;
	int repeat[T]={};
	string S[T]={};

	// testcase 입력 받기
	for(int i=0; i<T; i++)
		cin >> repeat[i] >> S[i];

	// 결과 출력
	for(int i=0; i<T; i++)
	{
		for(int j=0; j<S[i].length(); j++)
			for(int k=0; k<repeat[i]; k++)
				cout << S[i][j];
		cout << '\n';
	}

	return 0;
}

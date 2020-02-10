// 백준 1152 - 단어의 개수
#include <iostream>

using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	for(int i=2; i>=0; i--)
	{
		if(A[i] == B[i])
			continue;
		else
		{
			if(A[i] > B[i])
				for(int j=2; j>=0; j--)
					cout << A[j];
			else
				for(int j=2; j>=0; j--)
					cout << B[j];
			i=-1;
		}
	}
	return 0;
}

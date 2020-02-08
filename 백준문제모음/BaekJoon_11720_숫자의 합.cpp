// 백준 11720 - 숫자의 합
#include <iostream>

using namespace std;

int main()
{
	int N=0;
	cin >> N;
	char num[N]={};

	for(int i=0; i<N; i++)
		cin >> num[i];

	int sum=0;
	for(int i=0; i<N; i++)
		sum += num[i]-'0';	// 문자 '0'의 아스키코드값을 빼면 문자로 표현된 숫자의 숫자값을 알 수 있음

	cout << sum;

	return 0;
}

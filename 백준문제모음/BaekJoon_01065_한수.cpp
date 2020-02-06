// 백준 1065 - 한수 (자릿수가 등차수열)
#include <iostream>

using namespace std;

bool isEquivalent(int X)
{
	if(X < 100)
		return true;
	int subtract = X%10 - X/10%10;
	int num = X;
	while(num/10!=0)
	{
		int tail = num%10;
		num = num/10;
		if((tail-num%10) != subtract)
			return false;
	}
	return true;
}

int main()
{
	int N=0;
	cin >> N;
	int count=0;

	for(int i=1; i<=N; i++)
	{
		bool judge = isEquivalent(i);
		if(judge)
			count++;
	}
	cout << count;
}

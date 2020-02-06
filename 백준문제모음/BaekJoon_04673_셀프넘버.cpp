// 백준 4673 - 셀프 넘버
#include <iostream>

using namespace std;

int d(int n)	// n과 n의 각 자릿수를 더하는 함수
{
	int sum=n;
	while(n!=0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main()
{
	bool checked[10001]={true, };	// 해당 인덱스의 숫자가 셀프넘버=false, 셀프넘버아님=true
	// 셀프 넘버가 아닌 수 찾기
	for(int i=1; i<10000; i++)
	{
		int getNum = d(i);
		if(getNum > 10000)
			continue;
		else
			checked[getNum] = true;	// 셀프넘버가 아닌 수 체크
	}
	// 셀프 넘버 출력
	for(int i=1; i<=10000; i++)
		if(!checked[i])
			cout << i << '\n';

	return 0;
}

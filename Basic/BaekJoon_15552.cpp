#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T=0;	// testcase 수
	int A=0, B=0;
	cin >> T;

	for(int i=0; i<T; i++)
	{
		cin >> A >> B;
		cout << A+B << '\n';
	}

	return 0;
}

/*
 * [C++]
 * - scanf / printf는 충분히 빠르며, 아래의 내용은 cin, cout을 사용할 때의 해당사항들이다.
 *
 * 1. '\n'
 *   : 'endl'은 개행문자를 출력할 뿐만 아니라 출력 버퍼를 비워주는 역할까지 한다.
 *     그래서 출력한 뒤 화면에 바로 보이게 할 수 있는데, 그 버퍼를 비우는 작업이 매우 느리다.
 *     또한 온라인 저지에서는 화면에 바로 보여지는 것은 중요치 않고, 무엇이 출력되는지가 중요하기 때문에 버퍼를 그렇게 자주 비우지 않아도 된다. 따라서 endl 대신 \n을 사용한다면, 속도 향상이 매우 클 것이다!
 *
 * 2. cin.tie(NULL)
 *   : cin과 cout의 묶음을 풀어준다.
 *     기본적으로 cin을 읽을 때는 먼저 출력 버퍼를 비우는데, 1번에서 언급했듯이 버퍼를 그리 자주 비우지 않아도 된다.
 *     속도 향상을 위해, 입력과 출력을 번갈아서 반복해야 하는 경우 필수적이다!
 *
 * 3. ios_base::sync_with_stdio(false)
 *   : C와 C++의 버퍼를 분리한다.
 *     이것을 사용하면 cin/cout이 더이상 stdin/stdout과 맞출 필요가 없으므로 속도가 빨라진다.
 *     단, 버퍼가 분리되었으므로 cin과 scanf, gets, getchar 등을 같이 사용하면 안되고,
 *     cout과 printf, puts, putchar 등을 같이 사용하면 안 된다.
 */

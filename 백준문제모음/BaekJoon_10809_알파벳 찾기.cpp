// 백준 10809 - 알파벳 찾기
#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;

	int alphabet[26];
	for(int i=0; i<26; i++)
		alphabet[i] = -1;

	for(int i=0; i<S.length(); i++)
	{
		int current = S[i]-'a';
		if(alphabet[current] == -1)
			alphabet[current] = i;
	}

	for(int i=0; i<26; i++)
		cout << alphabet[i] << " ";

	return 0;
}

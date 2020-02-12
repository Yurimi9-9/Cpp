// 백준 1157 - 단어 공부
#include <iostream>

using namespace std;

int main()
{
	string word;
	cin >> word;
	int words[26]={};

	for(int i=0; i<word.length(); i++)
	{
		int index = word[i];
		if(word[i]<'a')
			index -= 'A';
		else
			index -= 'a';
		words[index]++;
	}

	int max=0;
	for(int i=1; i<26; i++)
		if(words[i] > words[max])
			max = i;

	for(int i=0; i<26; i++)
		if(i!=max)
			if(words[i]==words[max])
			{
				cout << "?";
				return 0;
			}
	cout << (char)(max+'A');

	return 0;
}

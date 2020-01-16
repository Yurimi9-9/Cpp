// Postfix 계산기
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_STACK_SIZE = 100;
typedef float ItemType;

class Stack
{
	int top;
	ItemType data[MAX_STACK_SIZE];

public:
	Stack();
	~Stack();
	bool is_empty();
	bool is_full();
	void push(ItemType item);
	ItemType pop();
};


int main()
{
	string token;	// 입력받은 내용을 저장할 변수
	Stack s;		// 입력 중 숫자(피연산자)를 저장할 스택

	while(cin >> token)			// token값이 입력되면 반복 수행
	{
		// if else 문으로 token으로 입력받은 연산자, 종료 명령어에 따라 작업 수행
		if(token == ";")
			break;

		// 숫자를 입력받을 때
		// (음수 값도 입력받아야 하므로 token[0], token[1] 중에 숫자가 입력되면 숫자로 인식)
		if(isdigit(token[0]) || token[1])
			s.push(atof(token.c_str()));		// 실수 입력을 받기 위해 atof() 사용

		//홀수 입력을 받아오기 위해서는 이곳에 else if로 해야함
		// '+' 연산자를 받았을 때
		if(token == "+")
		{
			// 연산자를 입력받았을 때, 피연산자를 저장하는 스택이 비었으면 error1 출력
			if(s.is_empty())
			{
				cout << "error1" << endl;
				return 0;
			}
			// 두번째 피연산자가 스택에서 먼저 나오므로 두번째 피연산자 먼저 pop()
			ItemType second = s.pop();

			// 두 번째 피연산자를 pop하고 피연산자를 저장하는 스택이 비었으면, error1 출력
			if(s.is_empty())
			{
				cout << "error1" << endl;
				return 0;
			}
			ItemType first = s.pop();
			// 피연산자를 다 pop하고, 연산결과를 다시 스택에 넣기
			s.push(first + second);
		}
		// '-' 연산자를 받았을 때
		else if(token == "-")
		{
			// 연산자를 입력받았을 때, 피연산자를 저장하는 스택이 비었으면 error1 출력
			if(s.is_empty())
			{
				cout << "error1" << endl;
				return 0;
			}
			// 두번째 피연산자가 스택에서 먼저 나오므로 두번째 피연산자 먼저 pop()
			ItemType second = s.pop();

			// 두 번째 피연산자를 pop하고 피연산자를 저장하는 스택이 비었으면, error1 출력
			if(s.is_empty())
			{
				cout << "error1" << endl;
				return 0;
			}
			ItemType first = s.pop();
			// 피연산자를 다 pop하고, 연산결과를 다시 스택에 넣기
			s.push(first - second);
		}
		// '*' 연산자를 받았을 때
		else if(token == "*")
		{
			// 연산자를 입력받았을 때, 피연산자를 저장하는 스택이 비었으면 error1 출력
			if(s.is_empty())
			{
				cout << "error1" << endl;
				return 0;
			}
			// 두번째 피연산자가 스택에서 먼저 나오므로 두번째 피연산자 먼저 pop()
			ItemType second = s.pop();

			// 두 번째 피연산자를 pop하고 피연산자를 저장하는 스택이 비었으면, error1 출력
			if(s.is_empty())
			{
				cout << "error1" << endl;
				return 0;
			}
			ItemType first = s.pop();
			// 피연산자를 다 pop하고, 연산결과를 다시 스택에 넣기
			s.push(first * second);
		}
		// '/' 연산자를 받았을 때
		else if(token == "/")
		{
			// 연산자를 입력받았을 때, 피연산자를 저장하는 스택이 비었으면 error1 출력
			if(s.is_empty())
			{
				cout << "error1" << endl;
				return 0;
			}
			// 두번째 피연산자가 스택에서 먼저 나오므로 두번째 피연산자 먼저 pop()
			ItemType second = s.pop();

			// 두 번째 피연산자를 pop하고 피연산자를 저장하는 스택이 비었으면, error1 출력
			if(s.is_empty())
			{
				cout << "error1" << endl;
				return 0;
			}
			ItemType first = s.pop();
			// 피연산자를 다 pop하고, 연산결과를 다시 스택에 넣기
			s.push(first / second);
		}
	}
	// 연산이 모두 끝난 후, 최종 결과를 pop()하고 result라는 변수에 저장
	ItemType result = s.pop();
	// 최종 결과를 pop()한 뒤, 스택이 비어있으면 결과값 출력
	if(s.is_empty())
		cout << fixed << setprecision(2) << result << endl;
	// 스택이 비어있지 않으면, 피연산자에 대한 연산자가 없는 것이므로 error2 출력
	else
		cout << "error2" << endl;
	return 0;
}


Stack::Stack()
{
	top = -1;
}

Stack::~Stack()
{
	top = 0;
}

bool Stack::is_empty()
{
	return (top == -1);
}

bool Stack::is_full()
{
	return (top == MAX_STACK_SIZE-1);
}

void Stack::push(ItemType item)
{
	if(is_full())
	{
		cout << "스택 포화 오류" << endl;
		return;
	}
	else
		data[++top] = item;
}

ItemType Stack::pop()
{
	if(is_empty())
	{
		cout << "스택 비어있음 오류" << endl;
		return 0;
	}
	else
	{
		ItemType item = data[top--];
		return item;
	}
}

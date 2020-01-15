// 괄호검사 동적 배열 - (,),{,},[,]
#include <iostream>

using namespace std;

typedef char ItemType;

struct Node
{
	ItemType info;
	Node* next;
};

typedef char ItemType;
class Stack
{
public:
	Stack(); // 스택 생성자
	~Stack(); // 스택 소멸자
	bool is_empty() const;
	bool is_full() const;
	void push(ItemType e ); // 맨 위에 원소를 삽입
	ItemType pop( ); // 맨 위의 원소를 삭제하고 반환
	ItemType peek( ) const; // 맨 위의 원소를 삭제하지 않고 반환
	void display( ) const; // 스택 원소들을 위에서부터 차례대로 내용을 출력
private:
	Node *topPtr; // 첫번째 노드(마지막 원소가 저장된 노드)를 가리키는 포인터
};


int main()
{
	Stack s;

	char input;				// 입력 받은 명령어를 저장할 변수
	bool balanced=true;		// balanced/unbalanced를 판별해주는 변수
	char open;				// 여는 괄호를 저장한 스택에서, 여는 괄호를 저장하는 변수

	// input 값이 입력 되고(Enter도 입력문자로 취급), balanced==true일 때 반복
	while(cin.get(input) && balanced)
	{
		// input 값에 따라 작업 수행
		switch(input)
		{
		// 여는 괄호를 입력 받은 경우
		case '(':				// 의도적인 break 생략
		case '{':				// 공통적으로 push() 작업 수행
		case '[':
		{
			s.push(input);	// input 값을 Stack에 push
			break;
		}
		// 닫는 괄호를 입력 받은 경우
		case ')':
		{
			if(s.is_empty())			// Stack이 비었다면
			{
				balanced = false;		// unbalanced
				break;
			}
			else						// 그렇지 않다면
				open = s.pop();			// 스택의 top을 꺼내 open에 저장
			if(open != '(')				// 여는 괄호와 open이 다르다면
				balanced = false;		// unbalanced
			break;
		}
		case '}':
		{
			if(s.is_empty())			// Stack이 비었다면
			{
				balanced = false;		// unbalanced
				break;
			}
			else						// 그렇지 않다면
				open = s.pop();			// 스택의 top을 꺼내 open에 저장
			if(open != '{')				// 여는 괄호와 open이 다르다면
				balanced = false;		// unbalanced
			break;
		}

		case ']':
		{
			if(s.is_empty())			// Stack이 비었다면
			{
				balanced = false;		// unbalanced
				break;
			}
			else						// 그렇지 않다면
				open = s.pop();			// 스택의 top을 꺼내 open에 저장
			if(open != '[')				// 여는 괄호와 open이 다르다면
				balanced = false;		// unbalanced
			break;
		}
		default:
			break;
		}
	}

	// balanced == false일 때
	if(!balanced)
		cout << -1 << endl;		// unbalanced이므로 -1 출력
	// balanced == true일 때
	else if(s.is_empty())		// Stack이 비었다면
		cout << 1 << endl;		// balanced이므로 1 출력
	else						// Stack에 무언가 들어있다면
		cout << -1 << endl;		// unbalanced이므로 -1 출력

	return 0;
}

// 스택 생성자
Stack::Stack()
{
	topPtr = NULL;		// 아직 첫번째 노드가 만들어지지 않았기 때문에 아무것도 가리키지 않는다 (NULL)
}

bool Stack::is_empty() const
{
	return (topPtr == NULL);		// 마지막 원소가 저장된 노드가 없다면, 스택이 비어있는 것이므로 topPtr==NULL인지 판단하여 반환
}

// 맨 위에 원소를 삽입
void Stack::push(ItemType item)
{
	// 새로운 노드를 동적 메모리 할당으로 생성
	Node* newNode;
	newNode = new Node;
	newNode->info = item;		// newNode의 내용에 함수의 매개변수로 입력받은 item값을 넣어준다
	newNode->next = topPtr;		// 포인터 topPtr이 원래 가리키던 노드의 앞에 새로운 노드가 생기므로 newNode의 next에 topPtr이 가리키는 주소값을 받아준다
	topPtr = newNode;			// 새로 만들어진 노드가 첫번째 노드가 된다
}

// 맨 위의 원소를 삭제하고 반환
ItemType Stack::pop()
{
	if(is_empty())
	{
		cout << "스택 비어있음 오류" << endl;
		exit(1);
	}
	else
	{
		ItemType item;				// pop()에서 원소를 반환하기 위해 사용하는 변수
		Node* tempPtr;				// topPtr의 내용을 임시로 저장해줄 Node 생성
		item = topPtr->info;		// 맨 위의 원소 값을 item에 저장
		tempPtr = topPtr;			// 임시 변수에 맨 위 Node의 정보 저장
		topPtr = topPtr->next;		// 첫번째 노드가 가리키는 다음 노드를 topPtr로 지정
		delete tempPtr;				// 임시 Node 삭제

		return item;
	}
}

// 맨 위의 원소를 삭제하지 않고 반환
ItemType Stack::peek() const
{
	if(is_empty())
	{
		cout << "스택 비어있음 오류" << endl;
		exit(1);
	}
	else
		return topPtr->info;		// topPtr에 담긴 정보를 반환
}

// 스택 소멸자
Stack::~Stack()
{
	Node* tempPtr;

	while(topPtr!=NULL)
	{
		tempPtr = topPtr;
		topPtr = topPtr->next;		// 만일 다음 노드가 없다면, next==NULL이므로 topPtr에는 NULL이 저장된다
		delete tempPtr;				// 동적 메모리 반납
	}
}

void Stack::display() const
{
	Node* location = topPtr;

	cout << "[스택 원소들] : ";

	while(!location)
	{
		cout << "<" << location->info << "> ";
		location = location->next;
	}
}

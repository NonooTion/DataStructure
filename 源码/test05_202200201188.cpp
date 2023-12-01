#include <iostream>
#include <string>
using namespace std;
template <class T>
struct chainNode
{
	T element;
	chainNode* next;
	chainNode(int theElement, chainNode* nextNode)
	{
		this->element = theElement;
		this->next = nextNode;
	}
	chainNode(int theElement)
	{
		this->element = theElement;
		this->next = NULL;
	}
};
template<class T>
class stack
{
public:
	stack()
	{
		this->top = NULL;
		this->bottom = NULL;
		this->stackSize = 0;
	}
	int get()
	{
		if (!empty())
		return top->element;
	}
	void pop()
	{
		if (empty())
		{
			return;
		}
		if (stackSize == 1)
		{
			delete top;
			top = bottom = NULL;
			stackSize--;
			return;
		}
		chainNode<T>* currentNode = bottom;
		while (currentNode->next != top)
		{
			currentNode = currentNode->next;
		}
		delete top;
		top = currentNode;
		stackSize--;
		return;
	}
	void push(int theElment)
	{
		if (stackSize == 0)
		{
			chainNode<T>* newNode = new chainNode<T>(theElment);
			top = bottom = newNode;
			stackSize++;
		}
		else
		{
			chainNode<T>* newNode = new chainNode<T>(theElment);
			top->next = newNode;
			top = top->next;
			stackSize++;
		}
		return;
	}
	bool empty()
	{
		if (stackSize == 0) return true;
		else return false;
	}
private:
	chainNode<T>* top, * bottom;
	int stackSize;
};
int getPriority(char op)//�������������ȼ�
{
	if (op == '+' || op == '-')return 1;
	else if (op == '*' || op == '/') return 2;
	else return 0;
}
int applyOp(int a, char op, int b)//����
{
	switch (op)
	{
	case '+': return (a + b);
	case '-':return (a - b);
	case '*': return (a * b);
	case '/':return (a / b);
	default:return 0;
	}
}
int evaluateExprssion(const string& expression)
{
	stack<int> values;
	stack<char> operators;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] >= '0' && expression[i] <= '9')
		{
			int temp = expression[i] - '0';
			while (expression[i + 1] >= '0' && expression[i + 1] <= '9')
			{
				temp = temp * 10 + expression[i + 1] - '0';
				i++;
			}
			values.push(temp);
			continue;
		}
		if (operators.empty() || expression[i] == '(')
		{
			operators.push(expression[i]);
			continue;
		}
		if (expression[i] == ')')
		{
			while (operators.get() != '(')
			{
				int b = values.get();
				values.pop();
				int a = values.get();
				values.pop();
				char op = operators.get();
				operators.pop();
				values.push(applyOp(a, op, b));
			}
			operators.pop();
			continue;
		}
		if (getPriority(operators.get())>=getPriority(expression[i]))
		{
			while (getPriority(operators.get()) >= getPriority(expression[i]))
			{
				int b = values.get();
				values.pop();
				int a = values.get();
				values.pop();
				char op = operators.get();
				operators.pop();
				values.push(applyOp(a, op, b));
			}
			operators.push(expression[i]);
			continue;
		}
		else
		{
			operators.push(expression[i]);
			continue;
		}
	}
	while (!operators.empty())
	{
		int b = values.get();
		values.pop();
		int a = values.get();
		values.pop();
		char op = operators.get();
		operators.pop();
		values.push(applyOp(a, op, b));
	}
	return values.get();
}
int main(void)
{
	cout << "Input" << "\n";
	string s;
	cin >> s;
	cout << "Output" << "\n";
	cout << "=" << evaluateExprssion(s) << "\n";
	cout << "End";
	return 0;
}

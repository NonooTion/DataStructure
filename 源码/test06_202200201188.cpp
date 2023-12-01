#include <iostream>
#include <queue>
#include <string>
using namespace std;
bool Count=0;
struct treeNode
{
	char element;
	treeNode* leftChild;
	treeNode* rightChild;
	treeNode(char theElement)
	{
		element = theElement;
		leftChild = NULL;
		rightChild = NULL;
	}
};
void preoutput(treeNode* t)
{
	if (t == NULL) return;
	if (Count == false)
	{
		cout << t->element;
		Count++;
	}
	else
		cout << "," << t->element;
	preoutput(t->leftChild);
	preoutput(t->rightChild);
}
void inoutput(treeNode* t)
{
	if (t == NULL) return;
	inoutput(t->leftChild);
	if (Count == false)
	{
		cout << t->element;
		Count++;
	}
	else
		cout << "," << t->element;
	inoutput(t->rightChild);
}
void postoutput(treeNode* t)
{
	if (t == NULL) return;
	postoutput(t->leftChild);
	postoutput(t->rightChild); 
	if (Count == false)
	{
		cout << t->element;
		Count++;
	}
	else
		cout << "," << t->element;
}
void leveloutput(treeNode* t)
{
	if (t == NULL) return;
	queue<treeNode*> q;
	cout << t->element;
	if (t->leftChild != NULL) q.push(t->leftChild);
	if (t->rightChild != NULL) q.push(t->rightChild);
	while (!q.empty())
	{
		treeNode *nextNode = q.front();
		q.pop();
	
		cout << "," << nextNode->element; 
		if (nextNode->leftChild != NULL) q.push(nextNode->leftChild);
		if (nextNode->rightChild != NULL) q.push(nextNode->rightChild);
	}
	return;
}
class binaryTree
{
public:
	binaryTree()
	{
		root = NULL;
		size = 0;
	}
	void levelCreat(string chars)
	{
		queue<treeNode*> q;
		root = new treeNode(chars[size]);
		size++;
		q.push(root);
		while (!q.empty()&&chars.size() > size)
		{
			treeNode* nextNode = q.front();
			q.pop();
			if (nextNode->leftChild == NULL)
			{
				nextNode->leftChild = new treeNode(chars[size]);
				size++;
				q.push(nextNode->leftChild);
			}
			if (chars.size() == size)
				break;
			if (nextNode->rightChild == NULL)
			{
				nextNode->rightChild = new treeNode(chars[size]);
				size++;
				q.push(nextNode->rightChild);
			}
		}
		return;
	}
	int getHight()
	{
		return height(root);
	}
	void Pre_inCreat(string prestr, string instr, int n)
	{
		root = pre_inCreat(prestr, instr, n);
	}
	void preOutput()
	{
		preoutput(root);
		cout << endl;
		Count = false;
	}
	void inOutput()
	{
		inoutput(root);
		cout << endl;
		Count = false;
	}
	void postOutput()
	{
		postoutput(root);
		cout << endl;
		Count = false;
	}
	void levelOutput()
	{
		leveloutput(root);
		cout << endl;
		Count = false;
	}
	int getSize()
	{
		return size;
	}
private:
	int size;
	treeNode* root;
	int height(treeNode* t)
	{
		if (t == NULL)
			return 0;
		int hl = height(t->leftChild);
		int hr = height(t->rightChild);
		if (hl > hr)
			return ++hl;
		else return ++hr;
	}
	treeNode* pre_inCreat(string prestr, string instr,int n)
	{
		if (n == 0) return NULL;
		int k = 0;
		while (prestr[0] != instr[k]) k++;

		treeNode* rootNode = new treeNode(prestr[0]);
		size++;
		rootNode->leftChild = pre_inCreat(prestr.substr(1,k), instr, k);
		rootNode->rightChild = pre_inCreat(prestr.substr(k + 1, n - k - 1),instr.substr(k + 1, n - k - 1), n - k - 1);
		return rootNode;
	}
};
int main(void)
{
	binaryTree t1, t2;
	string str, prestr, instr;
	cout << "Input1" << endl;
	cin >> str;
	t1.levelCreat(str);
	cout << "Output1" << endl;
	t1.preOutput();
	t1.inOutput();
	t1.postOutput();
	cout << t1.getSize() << endl;
	cout << t1.getHight() << endl;
	cout << "Input2" << endl;
	cin >> prestr >> instr;
	cout<<"Output2"<<endl; 
	t2.Pre_inCreat(prestr, instr, prestr.size());
	t2.postOutput();
	t2.levelOutput();
	cout << "End" << endl;
	return 0;
}

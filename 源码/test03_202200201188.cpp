#include <iostream>
using namespace std;
struct chainNode
{
	int element;
	chainNode* next;
	chainNode(const int& theElement, chainNode* nextNode)
	{
		this->element = theElement;
		this->next = nextNode;
	}
	chainNode(int element)
	{
		this->element = element;
		this->next = NULL;
	}
};
class linkList
{
public:
	linkList()
	{
		listSize = 0;
		firstNode = NULL;
	}
	void insert(int theElement)
	{
		if (listSize == 0)
		{
			chainNode* insertNode = new chainNode(theElement);
			firstNode = insertNode;
			listSize++;
			return;
		}
		if (theElement < firstNode->element)
		{
			chainNode* insertNode=new chainNode(theElement, firstNode);
			firstNode = insertNode;
			listSize++;
			return;
		}
		chainNode* tailNode = firstNode;
		chainNode* currentNode = firstNode->next;
		while (currentNode != NULL&& currentNode->element < theElement)
		{
			tailNode = tailNode->next;
			currentNode = currentNode->next;
		}
		if (currentNode!=NULL&&currentNode->next == NULL&& theElement > currentNode->element)
		{
				chainNode* insertNode = new chainNode(theElement);
				currentNode = insertNode;
				listSize++;
				return;
		}	
		chainNode* insertNode = new chainNode(theElement, currentNode);
		tailNode->next = insertNode;
		listSize++;
		return;
	}
	int find(int theElement)
	{
		chainNode* currentNode = firstNode;
		int count = 0;
		while ( currentNode != NULL&&currentNode->element != theElement )
		{
			currentNode = currentNode->next;
			count++;
		}
		if (currentNode != NULL)
			return count;
		else return -1;
	}
	void erase(int theElement)
	{
		if (theElement == firstNode->element)
		{
			chainNode* deleteNode = firstNode;
			firstNode = firstNode->next;
			delete deleteNode;
			listSize--;
			return;
		}
		chainNode* sourceNode=firstNode;
		chainNode* deleteNode = firstNode;
		while (deleteNode!=NULL&&deleteNode->element != theElement)
		{
			sourceNode = deleteNode;
			deleteNode = deleteNode->next;
		}
		if (deleteNode == NULL)
			return;
		else
		{
			sourceNode->next = deleteNode->next;
		}
		delete deleteNode;
		listSize--;
		return;
	}
	void output()
	{
		if (listSize==0)
		{
			cout << "<null>" << "\n";
		}
		chainNode* sourceNode = firstNode;
		if (sourceNode != NULL)
		{
			cout << sourceNode->element;
			sourceNode = sourceNode->next;
			while (sourceNode != NULL)
			{
				cout << "," << sourceNode->element;
				sourceNode = sourceNode->next;
			}
			cout << "\n";
		}
	}
	void combine(const linkList& theList)
	{
		chainNode* currentNode = theList.firstNode;
		while (currentNode != NULL)
		{
			this->insert(currentNode->element);
			currentNode = currentNode->next;
		}
		return;
	}
protected:
	chainNode* firstNode;
	int listSize;
};
int main()
{
	linkList chain1,chain2;
	int n;
	cout << "Input1" << "\n";
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		chain1.insert(n);
	}
	cout << "Output1" << "\n";
	chain1.output();
	cout << "Input2" << "\n";
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		chain2.insert(n);
	}
	cout << "Output2" << "\n";
	chain2.output();
	cout << "Combine" << "\n";
	chain1.combine(chain2);
	chain1.output();
	cout << "Insert" << "\n";
	cin >> n;
	chain1.insert(n);
	cout << "Insertion" << "\n";
	chain1.output();
	cout << "Delete" << "\n";
	cin >> n;
	chain1.erase(n);
	cout << "Deletion" << "\n";
	chain1.output();
	cout << "Find" << "\n";
	cin >> n;
	cout << "Position" << "\n";
	cout << chain1.find(n)+1<<endl;
	cout << "End" << "\n";
	return 0;
}

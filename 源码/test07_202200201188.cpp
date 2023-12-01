#include <iostream>
#include <queue>
using namespace std;
bool flag=false;
class maxHeap
{
	public:
	void initialHeap(int a[],int theSize)
	{
		heap=a;
		heapSize=theSize;
		for(int root=heapSize/2;root>=1;root--)
		{
			int rootElement=heap[root];
			int child=2*root;
			while(child<=heapSize)
			{
				if(child<heapSize&&heap[child]<heap[child+1])
				child++;
				if(rootElement>=heap[child])break;
				heap[child/2]=heap[child];
				child*=2;
			}
			heap[child/2]=rootElement;
		}
	}
	void levelOrder()
	{
		int start=1;
		queue<int> q;
		q.push(start);
		while(!q.empty())
		{
			int output=q.front();
			int lchild=output*2;
			int rchild=output*2+1;
			q.pop();
			if(lchild<=heapSize) q.push(lchild);
			if(rchild<=heapSize) q.push(rchild);
			if(!flag)
			{
				cout<<heap[output];
				flag=true;
			}
			else cout<<","<<heap[output];
		}
		cout<<"\n";
		flag=false;
		return;
	}
	void output()
	{
		cout<<heap[1];
		for(int i=2;i<=heapSize;i++)
		{
		 cout<<","<<heap[i];
		}
		cout<<"\n";
	}
	private:
	int *heap;
	int arrayLength=100;
	int heapSize=0;
};
struct treeNode
{
	treeNode()
	{
		left=right=NULL;
	}
	treeNode(int element)
	{
		key=element;
		left=right=NULL;
	}
	treeNode *left,*right;
	int key;
};
class bsTree
{
	public:
	bsTree()
	{
		root=NULL;
		treeSize=0;
	}
	void preOrder()
	{
	 preOrder(root);
	 cout<<"\n";
	 flag=false;
	}
	void inOrder()
	{
		inOrder(root);
		cout<<"\n";
		flag=false;
	}
	void initialBSTree(int b[],int theSize)
	{
		treeSize=theSize;
		for(int i=1;i<=theSize;i++)
		{
			insert(b[i]);
		}
		return;
	}
	void insert(int theKey)
	{
	if(root==NULL) 
	{
	root=new treeNode(theKey);
	return;
	}
	treeNode *p,*pp;
	p=root;
	pp=NULL;
	while(p!=NULL)
	{
		pp=p;
		if(theKey<p->key) p=p->left;
		else if(theKey>p->key) p=p->right;
		else
		return;
	}
	treeNode * newNode=new treeNode(theKey);
	if(pp!=NULL)
	if(pp->key>theKey) pp->left=newNode;
	else pp->right=newNode;
	else root=newNode;
	return;
	}
	private:
	void output(treeNode *a)
	{
		if(!flag)
		{
		cout<<a->key;
		flag=true;
		}
		else cout<<","<<a->key;
	}
	void preOrder(treeNode* a)
	{
		if(a==NULL) return;
		output(a);
		preOrder(a->left);
		preOrder(a->right);
		return;
	}
	void inOrder(treeNode *a)
	{
		if(a==NULL) return;
		inOrder(a->left);
		output(a);
		inOrder(a->right);
	}
	treeNode *root;
	int treeSize;
};
void heapSort(int a[],int size)
{
	maxHeap h;
	h.initialHeap(a,size);
	for(int i=size;i>1;i--)
	{
		int temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		h.initialHeap(a,i-1);
	}
	for(int i=1;i<=size;i++)
	{
		if(!flag)
		{
			cout<<a[i];
			flag=true;
		}
		else cout<<","<<a[i];
	}
	cout<<"\n";
	flag=false;
}
int main(void)
{
	cout<<"Input"<<"\n";
	int theSize=0;
	int a[100];
	int b[100];
	int c[100];
	while(1)
	{
		int sc;
		cin>>sc;
		if(sc==0) break;
		a[++theSize]=sc;
		b[theSize]=sc;
		c[theSize]=sc;
	}
	cout<<"Output"<<"\n";
	maxHeap h;
	h.initialHeap(a,theSize);
	h.output();
	heapSort(c,theSize);
	bsTree bs;
	bs.initialBSTree(b,theSize);
	bs.preOrder();
	bs.inOrder();
	cout<<"End"<<"\n";
	return 0;
}
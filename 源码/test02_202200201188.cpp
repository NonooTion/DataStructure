#include <iostream>
using namespace std;
const int N=10000;
int a[N];
swap(int &a,int &b)
{
	int temp=b;
	b=a;
	a=temp;
}
void bubble_sort(int x[],int size)
{
	for(int i=1;i<size;i++)
{
	for(int j=0;j<size-i;j++)
		{
			if(x[j]>x[j+1])
			swap(x[j],x[j+1]);
		}
}
}
void select_sort(int *a,int size)
{
	for(int i=size-1;i>0;i--)
	{
		int max_index=i;
	for(int j=0;j<i+1;j++)
	{
		if(a[j]>a[max_index])
		max_index=j;
	}
		swap(a[max_index],a[i]);
	}
}
void insert_sort(int *a,int size)
{
for(int i=1;i<size;i++)
{
	int val=a[i];
	int index=i;
	for(int j=i;j>=0;j--)
	{
		if(a[j-1]>val)
		{
		a[j]=a[j-1];
		index--;
		}
		else break;
	}
	a[index]=val;
}
}
int main(void)
{
	int size=1;
	cout<<"Input"<<"\n";
	while(1&&size<=18)
	{
		cin>>a[size-1];
		if(a[size-1]==0)
		break;
		size++;
	}
	int func;
	cout<<"1-Bubble Sort,2-Insert Sort,3-Select Sort"<<"\n";
	cin>>func;
	cout<<"Output"<<"\n";
	switch(func)
	{
		case 1:
			cout<<"Bubble Sort"<<"\n";
			bubble_sort(a,size);
			break;
		case 2:
			cout<<"Insert Sort"<<"\n";
			insert_sort(a,size);
			break;
		case 3:
			cout<<"Select Sort"<<"\n";
			select_sort(a,size);
			break;
	} 
	cout<<a[1];
	if(size>2){	
	for(int i=2;i<size;i++)
	cout<<","<<a[i];
}
	cout<<"\n";
	cout<<"End"<<"\n";
	return 0;
}

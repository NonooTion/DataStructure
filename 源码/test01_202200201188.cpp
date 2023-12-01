#include <iostream>
using namespace std;
const int N=1000;
int a[N];
int b[N];
bool flag[N];
int n=1;
void pl(int x)
{
	if(x>(n-1))
	{
		for(int i=1;i<n-1;i++)
		cout<<a[b[i]]<<",";
		cout<<a[b[n-1]];
		cout<<"\n";
	}
	else
	{
	 for(int i=1;i<=n-1;i++)
	 if(!flag[i])
	 {
	 	b[x]=i;	
	 	flag[i]=true;
	 	pl(x+1);
	 	flag[i]=false;
	}
	}
}
int main(void)
{
 cout<<"Input"<<"\n";
 while(1)
 {
 	cin>>a[n];
 	if(a[n]==0)
 	{
 		break;
	}
	n++;
 }
 cout<<"Output"<<"\n";
 pl(1);
 cout<<"End"<<"\n";
 return 0;
} 

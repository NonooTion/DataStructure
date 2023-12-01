#include <iostream>
using namespace std;
int flag[10];
bool output[10];
int main(void)
{
	int n, r;
	int classA, classB;
	cout<<"Input"<<endl; 
	cin >> n >> r;
	char ch;
	for (int i = 1; i <= n; i++)
	{
		flag[i] = i;
	}
	for (int j = 1; j <= r; j++)
	{
		cin >> ch >> classA >> ch >> classB >> ch;
		int tempclass=flag[classB];
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] == tempclass)
				flag[i] = flag[classA];
		}
	}
	cout<<"Output"<<endl;
	for (int i = 1; i <= n; i++)
	{
		if (output[i])
		{
			continue;
		}
		else
		{
			cout << "(" << i;
			output[i] = 1;
			for (int j = i + 1; j <= n; j++)
			{
				if (output[j] || flag[j] != flag[i])
					continue;
				output[j] = 1;
				cout << "," << j;
			}
			cout << ")" << endl;
		}
	}
	cout<<"End";
	return 0;
}

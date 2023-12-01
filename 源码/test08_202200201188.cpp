#include <iostream>
#include <queue>
using namespace std;
bool visited[15];
bool isone=true;
class graph
{
	public:
	graph(int nodeSize)
	{
		this->nodeSize=nodeSize;
		for(int i=1;i<=nodeSize;i++)
		{
		 for(int j=1;j<=nodeSize;j++)
		 map[i][j]=0;
		}
	}
	void dfs(int x)
	{
		visited[x]=true;
		if(isone)
		{
			cout<<x;
			isone=false;
		}
		else cout<<","<<x;
		for(int i=1;i<=nodeSize;i++)
		{
			if(map[x][i]!=0&&visited[i]==false)
			dfs(i);
		}
	}
	void bfs()
	{
		queue<int>q;
		q.push(1);
		while(!q.empty())
		{
			int out=q.front();
			q.pop();
			if(!visited[out])
			{
				visited[out]=true;
				if(isone)
				{
					cout<<out;
					isone=false;
				}
				else cout<<","<<out;
				for(int i=1;i<=nodeSize;i++)
				if(map[out][i]!=0)
				q.push(i);
			}
		}
		isone=true;
		for(int i=1;i<=nodeSize;i++)
		{
			visited[i]=false;
		}
	}
	int shortest_path()
	{
		int dp[nodeSize+1];
		dp[1]=0;
		for(int i=2;i<=nodeSize;i++)
		dp[i]=0xfff;
		queue<int> q;
		q.push(1);
		while(!q.empty())
		{   int num=q.front();
			q.pop();
			for(int j=1;j<=nodeSize;j++)
			{
				if(map[num][j]!=0&&dp[num]+map[num][j]<dp[j])
				{
				q.push(j);
				dp[j]=dp[num]+map[num][j];
				}
			}
		}
		if(dp[nodeSize]==0xfff) return 0;
		return dp[nodeSize];
	}
	int map[15][15];
	int nodeSize;	
};
int main(void)
{
	char c;
	int n,m;
	cout<<"Input"<<"\n";
	cin>>n>>c>>m;
	graph g(n);
	for(int i=1;i<=m;i++)
	{
		int x,y,value;
		cin>>x>>c>>y>>c>>value;
		g.map[x][y]=g.map[y][x]=value;
	}
	cout<<"Output"<<'\n';
	g.bfs();
	cout<<endl;
	g.dfs(1);
	cout<<endl;
	for(int i=1;i<=n;i++)
		{
			visited[i]=false;
		}
	cout<<g.shortest_path()<<endl;
	cout<<"End"<<'\n';
	return 0;
}
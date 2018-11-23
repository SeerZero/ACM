/*
* 时间复杂度O(kE)
* 队列列实现,有时候改成栈实现会更更快,较容易易修改
*/
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
struct Edge
{
	int v;
	int cost;
	Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<Edge> E[MAXN];
void addEdge(int u, int v, int w)
{
	E[u].push_back(Edge(v, w));
}
bool vis[MAXN];
int cnt[MAXN];
int dist[MAXN];
// 在队列列标志
// 每个点的入入列列队次数
bool SPFA(int start, int n)
{
	memset(vis, false, sizeof(vis));
	memset(dist, 0x3f, sizeof(dist));
	vis[start] = true;
	dist[start] = 0;
	queue<int> que;
	while (!que.empty())
	{
		que.pop();
	}
	que.push(start);
	memset(cnt, 0, sizeof(cnt));
	cnt[start] = 1;
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		vis[u] = false;
		for (int i = 0; i < E[u].size(); i++)
		{
			int v = E[u][i].v;
			if (dist[v] > dist[u] + E[u][i].cost)
			{
				dist[v] = dist[u] + E[u][i].cost;
				if (!vis[v])
				{
					vis[v] = true;
					que.push(v);
					if (++cnt[v] > n)
					{
						return false; // cnt[i]为入入队列列次数,用用来判定是否存在负环回路路
					}
				}
			}
		}
	}
	return true;
}


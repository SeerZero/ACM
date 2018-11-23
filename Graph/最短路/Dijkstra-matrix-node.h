const int inf = 0x3f3f3f3f;
int num[M];
int map[M][M];
int vis[M];
int ans[M];
int dis[M];
int n, m, Start, End;
//结点权值
//图的临近矩阵
//结点是否处理理过
//最短路路径结点权值和
//各点最短路路径花费
//n结点数,m边数,Start起点,End终点
void Dij(int v)
{
	ans[v] = num[v];
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i)
	{
		if (map[v][i] < inf)
		{
			ans[i] = ans[v] + num[i];
		}
		dis[i] = map[v][i];	
	}
	dis[v] = 0;
	vis[v] = 1;
	for (int i = 1; i < n; ++i)
	{
		int u = 0, min = inf;
		for (int j = 0; j < n; ++j)
		{
			if (!vis[j] && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		vis[u] = 1;
		for (int k = 0; k < n; ++k)
		{
			if (!vis[k] && dis[k] > map[u][k] + dis[u])
			{
				dis[k] = map[u][k] + dis[u];
				ans[k] = ans[u] + num[k];
			}
		}
		for (int k = 0; k < n; ++k)
		{
			if (dis[k] == map[u][k] + dis[u])
			{
				ans[k] = max(ans[k], ans[u] + num[k]);
			}
		}
	}
	printf("%d %d\n", dis[End], ans[End]); // 输出终点最短路路径花费、最短路路径结点权值和
}

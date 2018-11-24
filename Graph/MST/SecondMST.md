	Second MST
description:	
1.	MAX集合：	prim构建w集合到当前加入节点v的最长边（即为当前边）
2.	枚举每个edge对MAX进行替换，记录最小增加值
	type	time		store							interface		
SecondMST	O(n^2)		cost[][] MAX[][]		int Prim(int cost[][MAXN], int n)

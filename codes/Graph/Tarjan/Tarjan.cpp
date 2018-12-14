struct Tarjan{
	int dfn[MXN], low[MXN], isin[MXN];
	int scc[MXN], num, cntp;
	vector<int>edge[MXN];
	stack<int>st;
	int n;
	void dfs(int u){
		dfn[u] = low[u] = ++cntp;
		st.push(u); isin[u] = 1;
		
		for(int v : edge[u]){
			if(!dfn[v]){
				dfs(v);
				low[u] = min(low[u], low[v]);
			} else if(isin[v]){
				low[u] = min(low[u], dfn[v]);
			}
		}	
		if(dfn[u] == low[u]){
			int v = 0;
			do{
				v = st.top();
				st.pop();
				scc[v] = num;
				isin[v] = 0;
			} while(u != v);
		 	num++;
		}
	}
	void init(int _n){
		n = _n;
		cntp = num = 0;
		for(int i = 1; i <= n; ++i){
			isin[i] = dfn[i] = low[i] = 0;
			edge[i].clear();
		}
		return ;
	}
	void solve(){
		for(int i = 1; i <= n; ++i)
			if(!dfn[i]) dfs(i); 
	}
}tarjan;


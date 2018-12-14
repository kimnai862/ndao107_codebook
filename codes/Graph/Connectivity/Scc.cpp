struct Scc{
	int n, cntp, num;
	int in[MXN], re[MXN], gp[MXN];
	vector<int>edge[MXN], re_edge[MXN];
	void pre(int u){
		in[u] = 1;
		for(int v : edge[u]){
			if(in[v]) continue;
			pre(v);
		}
		re[++cntp] = u;
		return ;
	}
	void dfs(int u){
		in[u] = 1;
		gp[u] = num;
		for(int v : re_edge[u]){
			if(in[v]) continue;
			dfs(v);
		}
		return ;
	}
	void addEdge(int u, int v){
		edge[u].pb(v);
		re_edge[v].pb(u);
		return ;
	}
	void init(int _n){
		n = _n;
		rep1(i, 1, n+1){
			edge[i].clear();
			re_edge[i].clear();
		}
		return ;
	}
	void solve(){
		cntp = num = 0;
		rep1(i, 1, n+1) in[i] = 0;
		rep1(i, 1, n+1) if(!in[i]) pre(i);
		rep1(i, 1, n+1) in[i] = 0;
		reverse( re + 1, re + n + 1 );
		rep1(i, 1, n+1) if(!in[i]){
			num++; dfs(i);
		}
		return ;
	}
};

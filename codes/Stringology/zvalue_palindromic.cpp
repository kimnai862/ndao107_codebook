int extend(int l, int r, int n){
	int res = 0;
	while(l - res >= 1 && r + res <= n && b[l - res] == b[r + res]) res++;
	return res;
}
void sol(int n){
	LL rd = randint();
	rep1(i, 1, 2*n+1) b[i] = rd;
	rep1(i, 1, n+1) b[i*2] = a[i];
	n = n*2 + 1;
	z[1] = 1; 
	int L = 1, R = 1;
	rep1(i, 2, n+1){
		int p = L - (i - L);
		int l = R - i + 1;
		if(i > R){
			z[i] = extend(i, i, n);
			L = i;
			R = i + z[i] - 1;
		}
		else if(z[p] == l){
			z[i] = l + extend(i-l, i+l, n);
			L = i;
			R = i + z[i] - 1;
		}
		else{
			z[i] = min(z[p], l);
		}
	}
}


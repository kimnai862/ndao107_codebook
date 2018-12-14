void Zvalue(){
	Z[1] = 0;
	int l = strlen(s + 1);
	for(int b = 1, i = 2; i <= l; ++i){
		Z[i] = max(min(Z[i-b+1], Z[b] + b - i), 0);
		while( i + Z[i] <= l && s[i + Z[i]] == s[Z[i]+1] ) Z[i]++;
		if(i + Z[i] > b + Z[b]) b = i;
	}
}


void build(){
	int l = strlen(s + 1);
	fail[1] = 0;
	int pos = 0;
	for(int i = 2; i <= l; ++i){
		while(pos != 0 && s[i] != s[pos+1]) pos = fail[pos];
		if(s[i] == s[pos+1]) pos++;
		fail[i] = pos;
	}
}


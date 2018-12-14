bool sieve[MXN];
vector<int>prime;
void linear_sieve(){
  for(int i = 2; i< MXN; ++i){
    if(!sieve[i]) prime.pb(i);
    for(int j = 0; i*prime[j] < MXN; ++j){
      sieve[i*prime[j]] = true;
      if(i % prime[j] == 0) break;
    }
  }
}

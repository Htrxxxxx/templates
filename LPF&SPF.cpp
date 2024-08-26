// To calculate spf for first N integers . 
vector<int> calculateSPF() {
    vector<int> spf(N); 
    iota(spf.begin(), spf.end(), 0); 

    for (int i = 2; i < N; ++i) {
        if (spf[i] == i) { // i is a prime number
            for (int j = i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    
    return spf;
}

//Using spf to get primes in log(n) + preprocessing (O(nlog(log(n)) .

vector<int> calculateSPF() {
    vector<int> spf(N); 
    iota(spf.begin(), spf.end(), 0); 

    for (int i = 2; i < N; ++i) {
        if (spf[i] == i) { // i is a prime number
            for (int j = i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    
    return spf;
}
vector<int> find_divisors_inlog (int n , vector<int> &spf) {
    vector<int> divisors ;
    while(spf[n] != n) {
        int d1 = spf[n] , d2 = n / spf[n] ; 
        divisors.push_back(d1) ; 
        divisors.push_back(d2) ;
        n /= spf[n] ;
    }
    return divisors ;
}

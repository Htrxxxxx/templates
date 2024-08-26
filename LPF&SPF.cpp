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

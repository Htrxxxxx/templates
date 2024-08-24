_  SEGTREE  _

// Build the segment tree with n (power of 2) . 
segtree.resize(2 * n) ;    
for(int i = 0 ; i < n ; i++) {
    segtree[i + n] = a[i] ;
}
for(int i = n - 1 ; i>=1 ; i--) {
    segtree[i] = segtree[i * 2] + segtree[i * 2 + 1] ;  
}

//Query the segment tree (Recusive). 
int get(int node , int node_low , int node_high , int query_low  , int query_high){
    if(node_low >= query_low && node_high <= query_high){
        return segtree[node] ;
    }
    if(node_low > query_high || node_high < query_low) {
        return 0 ;
    }

    int m = (node_low + node_high) / 2 ;
    return get(2 * node , node_low , m , query_low , query_high) +
          get(2 * node + 1 , m+1 , node_high , query_low , query_high) ;
}

//Update the segment tree 
void update(int i , int v ,  int &n , vector<int> &segtree) {
    segtree[n + i] = v ;
    for(int j = (n + i) / 2 ; j>=1 ; j/=2) segtree[j] = segtree[2 * j] + segtree[2 * j + 1] ;
}



// Given an integer n, return the number of prime numbers that are strictly less than n.

// Solution:

int countPrimes(int n) {
    vector<int> prime(n, 1);
    
    for(int i = 2; i*i < n; i++) {
        if(prime[i]) {
            for(int j = i*i; j < n; j += i){
                prime[j] = 0;
            }
        }
    }
        
    int count = 0;
    
    for(int i = 2; i < n; i++) {
        if(prime[i]) count++;
    }
    
    return count;
}

// Time Complexity: O(n*log(log(n)))
// Auxiliary Space: O(n)
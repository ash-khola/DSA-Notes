// Given an integer N, find its factorial.

// Solution:

void multiply(vector<int> &fact, int n) {
    int product, carry = 0;

    for(int i = 0; i < fact.size(); i++) {
        product = fact[i] * n;
        product += carry;
        fact[i] = product % 10;
        carry = product / 10; 
    }

    while(carry) {
        fact.push_back(carry%10);
        carry /= 10;
    }
}

vector<int> factorial(int N) {
    vector<int> fact;
    fact.push_back(1);

    for(int i = 2; i <= N; i++) {
        multiply(fact, i);
    }

    reverse(fact.begin(), fact.end());

    return fact;
}
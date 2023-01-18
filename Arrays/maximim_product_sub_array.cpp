// Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

// Solution:

long long maxProduct(vector<int> nums, int n) {
    // code here
    // long long ma = arr[0], mi = arr[0];
    // long long ans = arr[0];
    
    // for(int i = 1; i<n; i++) {
    //     if(arr[i] < 0) {
    //         swap(ma, mi);
    //     }
    //     ma = max((long long)arr[i], ma * arr[i]);
    //     mi = min((long long)arr[i], mi * arr[i]);
    //     ans = max(ans, ma);
    // }
    
    // return ans;

    // left to right
    long long int maxp = INT_MIN, prod = 1;
    for(int i=0;i<nums.size();i++){
        prod *= nums[i];
        maxp = max(maxp, prod);
        if(prod == 0){
            prod = 1;
        }
    }
    
    // right to left
    prod = 1;
    for(int i=nums.size()-1;i>=0;i--){
        prod *= nums[i];
        maxp = max(maxp, prod);
        if(prod == 0){
            prod = 1;
        }
    }
    
    return maxp;
}
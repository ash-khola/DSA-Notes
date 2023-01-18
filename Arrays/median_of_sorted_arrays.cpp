// Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

double MedianOfArrays(vector<int>& arr1, vector<int>& arr2) {
    // Your code goes here
    int n1 = arr1.size(), n2 = arr2.size();
    
    if(n1 > n2) {           // to reduce T.C to log(min(n, m))
        return MedianOfArrays(arr2, arr1);
    }

    int low = 0, high = n1;

    while(low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int r2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if(l1 <= r2 and l2 <= r1) {
            if((n1 + n2) % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else {
                return max(l1, l2);
            }
        }
        else if(l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1;
        }
    }
}
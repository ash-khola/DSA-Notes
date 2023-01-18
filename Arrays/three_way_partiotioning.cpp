// Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
// 1) All elements smaller than a come first.
// 2) All elements in range a to b come next.
// 3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to return the modified array.

void threeWayPartitioning(vector<int> &arr, int a, int b) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while(mid <= high) {   // equality condition is mandatory here otherwise w.a
        if(arr[mid] < a) {
            swap(arr[low++], arr[mid++]);
        }
        else if(arr[mid] >= a and arr[mid] <= b) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high--]);
        }
    }
}
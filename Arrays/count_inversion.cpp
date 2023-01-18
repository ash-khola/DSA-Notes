// Given an array of integers. Find the Inversion Count in the array. 
// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 


long long int merge(long long int arr[], long long int low, long long int mid, long long int high) {
    long long int i = low, j = mid+1;
    long long int temp[high+1];
    long long int k = low;
    long long int inversions = 0;

    while(i <= mid and j <= high) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++, k++;
        }

        else {
            temp[k] = arr[j];
            inversions += (mid+1) - i;    // arr[k] ko (mid + 1 - i) elements se piche le jana padega
            j++, k++;
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= high) {
        temp[k++] = arr[j++];
    }

    for(int d = low; d <= high; d++) {
        arr[d] = temp[d];
    }

    return inversions;
}

long long int mergeSort(long long int arr[], long long int low, long long int high) {
    long long int mid = (low+high)/2;
    long long int inversions = 0;

    if(low < high) {
        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid+1, high);
        inversions += merge(arr, low, mid, high);
    }

    return inversions;
}

long long int inversionCount(long long arr[], long long N) {
    return mergeSort(arr, 0, N-1);
}
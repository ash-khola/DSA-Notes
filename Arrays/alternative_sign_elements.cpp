// Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers. And you should not use any extra space.
// Note: Array should start with a positive number.

// Solution:

// O(1) space solution

void right_rotate(int arr[], int start, int end) {
    int last_element = arr[end];

    for(int i = end; i > start; i--) {
        arr[i] = arr[i-1];
    }

    arr[start] = last_element;
}

void rearange(int arr[], int n) {
    int out_of_place = -1;

    for(int i = 0; i<n; i++) {
        if(out_of_place != -1) {
            if((arr[out_of_place] < 0 and arr[i] > 0) or (arr[out_of_place] > 0 and arr[i] < 0)) {
                right_rotate(arr, out_of_place, i);

                if(i - out_of_place >= 2) {
                    out_of_place += 2;
                }
                else {
                    out_of_place = -1;
                }
            }
        }

        else if((i&1 and arr[i] > 0) or (i%2 == 0 and arr[i] < 0)) {
            out_of_plcae = i;
        }
    }
} 

// Time Complexity: O(N*N), as we are using a loop to traverse N times and calling function to right rotate each time which will cost O (N).
// Auxiliary Space: O(1).
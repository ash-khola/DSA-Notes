// Given an array of N integers arr[] where each element represents the max length of the jump that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

// Note: Return -1 if you can't reach the end of the array.

// Solution:

int minJumps(int arr[], int n) {
    if(n == 1 or arr[0] == 0) {
        return -1;
    }

    int jumps = 0;
    int max_reach = arr[0];
    int jumps_available = arr[0];

    for(int i = 0; i<n; i++) {
        if(i == n-1) {
            return jumps+1;
        }

        jumps_available--;

        if(jumps_available == 0) {
            jumps++;
            jumps_available = max_reach - i;
            if(jumps_available <= 0) {
                return jumps+1;
            }
        }
    }
}
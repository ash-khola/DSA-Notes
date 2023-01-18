// Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

// Solution:
// We will use a deque and will store elemwnts in decreasing order in that, and for every window, first we check if the front element is within the window or not and after that if not than we simply pop_fornt() and the front element of the queue is our answer

vector <int> max_of_subarrays(int *arr, int n, int k)
{
    deque<int> dq;
    vector<int> ans;
    
    for(int i = 0; i < n; i++) {
        while(!dq.empty() and arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if(i >= k-1) {
            if(dq.front() <= i - k) {
                dq.pop_front();
            }
            
            ans.push_back(arr[dq.front()]);
        }
    }
    
    return ans;
}

// Time Complexity: O(n)
// Space Complexity: O(k)  ----> the size of deque will never exceed k




//********************* Extension of above problem **************************** 
// Sum of minimum and maximum elements of all subarrays of size “K”

// As we find the maximum of subarray of size k, now in this problem we will use both the maximum and minimum of subarray of size k, so for that we will need to make two deques and two arrays and then calculate the sum of (max + min) for each window.
// To find the minimum of window we need to do the same procedure as above with  just a slight change that is we need to store the elements in increasing order in the deque. 

// Solution:

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
    deque<int> dq_max, dq_min;
    vector<int> max_of_k, min_of_k;
    
    // maximum of subarray 
    for(int i = 0; i < n; i++) {
        while(!dq_max.empty() and nums[i] >= nums[dq_max.back()]) {
            dq_max.pop_back();
        }
        
        dq_max.push_back(i);
        
        if(i >= k-1) {
            if(dq_max.front() <= i - k) {
                dq_max.pop_front();
            }
        
            max_of_k.push_back(nums[dq_max.front()]);
        }
    }
    
    // minimum of subarray
    for(int i = 0; i < n; i++) {
        while(!dq_min.empty() and nums[i] <= nums[dq_min.back()]) {
            dq_min.pop_back();
        }
        
        dq_min.push_back(i);
        
        if(i >= k-1) {
            if(dq_min.front() <= i - k) {
                dq_min.pop_front();
            }
        
            min_of_k.push_back(nums[dq_min.front()]);
        }
    }
    
    long long sum_max_min = 0;
    
    for(int i = 0; i < n - k + 1; i++) {
        sum_max_min += max_of_k[i] + min_of_k[i];
    }
    
    return sum_max_min;
}

// Time Complexity: O(n)
// Space Complexity: O(k)  ----> the size of both the deques will never exceed k

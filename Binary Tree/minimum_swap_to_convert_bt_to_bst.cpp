// Given an array A[] which represents a Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child.
// The task is to find the minimum number of swaps required to convert it into a Binary Search Tree

void inorder(vector<int> &A, int i, int n, vector<int> &in) {
    if(i >= n) {
        return ;
    }
    
    inorder(A, 2*i+1, n, in);
    in.push_back(A[i]);
    inorder(A, 2*i+2, n, in);
    
    return;
}

int swaps(vector<int> &in) {
    unordered_map<int, int> mp;
    
    for(int i = 0; i<in.size(); i++) {
        mp[in[i]] = i;
    }
    
    sort(in.begin(), in.end());
    int swaps = 0;
    
    for(int i = 0; i<in.size(); i++) {      // reforming the original array from sorted array
        if(mp[in[i]] != i) {
            swaps++;
            swap(in[i], in[mp[in[i]]]);
            i--;          // we have sent the old character to it's correct place
            // but we are not sure that whether this place is the correct place 
            // place or not for the new character which we got after swapping so 
            // we will again give a check for the current posistion and will remain
            // at the same same position till we keep entering the if condition
        }
    }
    
    return swaps;
}

int minSwaps(vector<int>&A, int n){
    //Write your code here
    vector<int> in;
    inorder(A, 0, n, in);
    
    return swaps(in);
}
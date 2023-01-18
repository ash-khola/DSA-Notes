// Given an array arr[ ] of size N consisting of distinct integers, write a program that returns 1 if given array can represent preorder traversal of a possible BST, else returns 0.

// Solution:

void isValidPreTraversal(vector<int> &pre, int n) {
    stack<int> st;
    int root = INT_MIN;

    for(int i = 0; i<n; i++) {
        if(pre[i] < root) {
            return false;
        }
        else {
            while(!st.empty() and pre[i] > st.top()) {
                root = st.top();
                st.pop();
            }
        }

        st.push(pre[i]);
    }

    return true;
}
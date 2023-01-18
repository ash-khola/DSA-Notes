// **************************** Preorder, Inorder and Postorder Traversal ****************************

// Working for all three traversals:

vector<int> pre, in, post;
stack<pair<node, int>> st;

st.push({root, 1});

while(!st.empty()){
    int state = st.top().second;
    Node *node = st.top().first;

    if(state == 1) {
        pre.push_back(node->data);
        st.top().second+=1;
        if(node->left) {st.push({node->left, 1});}
    }

    if(state == 2) {
        in.push_back(node->data);
        st.top().second += 1;
        if(node->right) {st.push({node->right, 1});}
    }

    if(state == 3) {
        post.push_back(node->data);
        st.pop();
    }
}

return pre, in, post;

// Time Complexity: O(N).
// Auxiliary Space: O(N).
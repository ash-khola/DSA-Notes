vector<int> reverse_order(Node *node) {
    stacn<node *> st;
    queue<int> q;

    q.push(node);

    while(!q.empty()) {
        for(int i = 0; i<q.size(); i++) {
            if(q.front()->right) {q.push(q.front()->right)};
            if(q.front()->left) {q.push(q.front()->left)};

            st.push(q.front());
            q.pop();
        }
    }

    return st;
}

// Time complexity - O(n)
// Space complexity - O(n)

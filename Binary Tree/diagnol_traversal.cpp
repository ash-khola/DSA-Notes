// Given a Binary Tree, print the diagonal traversal of the binary tree.
// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

vector<int> diagonal(Node *root) {
    queue<Node *> q;
    vector<int> ans; 

    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        while(temp) {
            ans.push_back(temp->data);
            if(temp->left) {
                q.push(temp->left);
            }

            temp = temp->right;
        }
    }

    return ans;
}
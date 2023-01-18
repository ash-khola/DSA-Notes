vector<int> level_order(Node *node){
    queue<Node *> nd;
    nd.push(node);
    vector<int> level;

    while(!nd.empty) {
        for (int i = 0; i < nd.size; i++) {
            level.push_back(nd.front()->data);

            if(nd.front()->left != NULL) {nd.push(nd.front()->left)};
            if(nd.front()->right != NULL) {nd.push(nd.front()->right)};

            nd.pop();
        }
    } 

    return level;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
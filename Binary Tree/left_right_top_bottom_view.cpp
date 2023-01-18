// ******************************* Left View *******************************

void solve (vector<int> &ans, Node *node, int level) {
    if(!node) 
        return;
    
    if(level == ans.size()) 
        ans.push_back(node->data);
    
    solve(ans, node->left, level+1);
    solve(ans, node->right, level + 1);
}

vector <int> left_view(Node *node) {
    vector<int> ans;
    solve(ans, node, 0);

    return ans;
}

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).


// ******************************* Right View *******************************

void solve (vector<int> &ans, Node *node, int level) {
    if(!node) 
        return;
    
    if(level == ans.size()) 
        ans.push_back(node->data);
    
    solve(ans, node->right, level + 1);
    solve(ans, node->left, level+1);
}

vector <int> left_view(Node *node) {
    vector<int> ans;
    solve(ans, node, 0);

    return ans;
}

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).



// ******************************* Top View *******************************

vector<int> topView(Node *root) {
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});

    vector<int> ans;

    while(!q.empty()) {
        if(mp.find(q.front().second) == mp.end()) {
            mp[q.front().second] = q.front().first->data;
        }

        if(q.front().first->left) {
            q.push({q.front().first->left, q.front().second-1});
        }

        if(q.front().first->right) {
            q.push({q.front().first->right, q.front().second+1});
        }

        q.pop();
    }

    for(auto m:mp) {
        ans.push_back(m.second);
    }

    return ans;
}

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)



// ******************************* Bottom View *******************************

void bottomView(Node *node) {
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({node, 0});

    while(!q.empty) {
        auto it = q.front();

        mp[it.second] = it.first->data;

        if(it.first->left) {
            q.push({it.first->left, it.second-1});
        }

        if(it.first->right) {
            q.push({it.first->right, it.second+1});
        }

        q.pop();
    }

    vector<int> ans;

    for(auto a:mp) {
        ans.push_back(a);
    }

    return ans;
} 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
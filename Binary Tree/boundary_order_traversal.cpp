// ****************************** Boundary Order Traversal **********************************

void isLeaf(root) {
    if(!root->left and !root->right) return true;
    else return false;
}

void addLeft(Node *root, vector<int> &res) {
    Node *temp = root->left;

    while(temp) {
        if(isLeaf(temp)) {
            break;
        }

        res.push_back(temp->data);
        
        if(temp->left) {temp = temp->left;}
        else {temp = temp->right;}
    }
}

void addRight(Node *root, vector<int> &res) {
    Node *temp = root->right;
    vector<int> vec;

    while(temp) {
        if(isLeaf(temp)) {
            break;
        }

        vec.push_back(temp->data);

        if(temp->right) {temp = temp->right;}
        else {temp = temp->left;}
    }
    
    reverse(vec.begin(), vec.end());
    res.insert(res.end(), vec.begin(), vec.end());
}

void addLeaves(Node *root, vector<int> &res) {
    if(isLeaf(root)) {
        res.push_back(root);
        return;
    }

    if(root->left) {addLeaves(root->left);}
    if(root->right) {addLeaves(root->right);}
} 

vector <int> boundary(Node *root) {
    vector<int> res;
    if(!root) {
        return res;
    }

    if(!isLeaf(root)) {
        res.push_back(root->data);
    }

    addLeft(root, res);
    addLeaves(root, res);
    addRight(root, res);

    return res;
}

// Expected Time Complexity: O(N). 
// Expected Auxiliary Space: O(Height of the Tree).
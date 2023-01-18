unordered_map<string> mp;

string preorder(Node *root) {
    if(!root) {
        return "";
    }

    if(!root->left and !root->right) {
        return to_string(root->data);
    }

    string s;

    s += to_string(root->data);
    s += preorder(root->left);
    s += preorder(root->right);
    mp[s]++;

    return s;
}

int dupSub(Node *root) {
    preorder(root);

    for(auto a: mp) {
        if(a.second > 1) {
            return 1;
        }
    } 

    return 0;
}   
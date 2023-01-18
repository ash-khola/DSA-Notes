// A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k. 
// A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree.

// Solution:

void printPath(vector<int> vec, int j) {
    for(int i = j; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    } 
    cout<<endl;
}

void kSumPaths(Node *root, vector<int> &vec, int k) {
    if(!root) {
        return;
    }

    vec.push_back(root->data);

    kSumPaths(root->left, vec, k);
    kSumPaths(root->right, vec, k);

    int sum = 0;
    for(int i = vec.size() - 1; i>=0; i--) {
        sum += vec[i];

        if(sum == k) {
            printPath(vec, i);
        }
    }

    vec.pop_back();

    return;
}

// Time Complexity: O(n*h*h) 
// Space Complexity: O(h) as maximum size of path vector can be h


// ************** If asked to only count the no. of kSumPaths *****************
// Simply use map 

class Solution {
public:
    int paths = 0;
    unordered_map<long long, long long> mp;

    void solve(TreeNode *root, long long sum, int targetSum) {
        if(!root) return;

        sum += root->val;
        paths += mp[sum - targetSum];
        mp[sum]++;
        solve(root->left, sum, targetSum);
        solve(root->right, sum, targetSum);
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        solve(root, 0, targetSum);
        return paths;
    }
};

// T.C: O(n)
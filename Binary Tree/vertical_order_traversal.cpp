// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
// Return the vertical order traversal of the binary tree.

// Solution: We will use map<int, map<int, multiset<int>>> mp;
                        //   ^         ^      ^   
                        //   |         |      | 
                        //   |         |      |
                        // Vertical   level   can be multiple elememts at same column and same level
                        // column

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        vector<vector<int>> vertical;

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int row = curr.second.first, col = curr.second.second;
            mp[col][row].insert(curr.first->val);
            if(curr.first->left) q.push({curr.first->left, {row + 1, col - 1}});
            if(curr.first->right) q.push({curr.first->right, {row + 1, col + 1}});
        }

        for(auto it : mp) {
            vector<int> temp;
            for(auto it1 : it.second) {
                temp.insert(temp.end(), it1.second.begin(), it1.second.end());
            }
            vertical.push_back(temp);
        }

        return vertical;
    }
};

// T.C : O(n * log(n))
// S.C : O(n)
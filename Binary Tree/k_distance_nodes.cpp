// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solution: Make parent map to store the parents of all nodes. Now do bfs and keep updating the current dist, when current_sidt becomes equal to "k" break, and push all the elements of the queue in result vector.

class Solution {
public:
    unordered_map<TreeNode *, TreeNode *> parent;

    void getParent(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        getParent(root);
        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode *, bool> vis;
        vis[target] = true;
        vector<int> kDist;
        int level = 0;

        while(!q.empty()) {
            level++;
            if(level > k) break;
            int len = q.size();

            for(int i = 0; i < len; i++) {
                if(q.front()->left and !vis[q.front()->left]) q.push(q.front()->left), vis[q.front()->left] = true;
                if(q.front()->right and !vis[q.front()->right]) q.push(q.front()->right), vis[q.front()->right] = true;
                if(parent[q.front()] and !vis[parent[q.front()]]) {
                    vis[parent[q.front()]] = true;
                    q.push(parent[q.front()]);
                } 
                q.pop();
            }
        }

        while(!q.empty()) {
            kDist.push_back(q.front()->val);
            q.pop();
        }

        return kDist;
    }
};
// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

// In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

// Return the minimum number of moves required to make every node have exactly one coin.

// Solution: We traverse childs first (post-order traversal), and return the ballance of coins. For example, if we get '+3' from the left child, that means that the left subtree has 3 extra coins to move out. If we get '-1' from the right child, we need to move 1 coin in. So, we increase the number of moves by 4 (3 moves out left + 1 moves in right). We then return the final ballance: r->val (coins in the root) + 3 (left) + (-1) (right) - 1 (keep one coin for the root).

class Solution {
private:
    int moves = 0;

    int distribute(TreeNode *root) {
        if(!root) return 0; 
        int l = distribute(root->left); 
        int r = distribute(root->right);
        moves += abs(l) + abs(r);
        return l + r + root->val - 1; 
    }
public:
    int distributeCoins(TreeNode* root) {
        distribute(root);
        return moves;
    }
};
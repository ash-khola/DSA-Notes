// Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.
// LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

// Solution:

Node *lowestCommonAncestor(Node *root, int n1, int n2) {
    if(!root) {
        return NULL;
    }

    if(root->data == n1 or root->data == n2) {
        return root;
    } 

    Node *lca_found_on_left = lowestCommonAncestor(root->left, n1, n2);
    Node *lca_found_on_right = lowestCommonAncestor(root->right, n1, n2);

    if(lca_found_on_left and lca_found_on_right){
        return root;   // this is the lca as we have got nodes of n1 and n2 from both left and right subtrees therefore this is the intersection point
    }

    if(lca_found_on_left) {
        return lca_found_on_left;
    }

    else if(lca_found_on_right) {
        return lca_found_on_right;
    }

    else {
        return NULL;  // means neither n1 nor n2 is present on this branch, might be present on some other branch
    }
}

// Expected Time Complexity:O(N).
// Expected Auxiliary Space:O(Height of Tree) stackFrame space
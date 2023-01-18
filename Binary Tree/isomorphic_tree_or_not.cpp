// Given two Binary Trees. Check whether they are Isomorphic or not.
// Note: 
// Two trees are called isomorphic if one can be obtained from another by a series of flips, i.e. by swapping left and right children of several nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.

// Solution:

bool isIsomorphic (Node *root1, Node *root2){
    if(!root1 and !root2) {
        return true;
    }

    if(!root1 and !root2) {
        return false;
    }

    if(root1->data != root2->data) {
        return false;
    }

    bool left_left_rght_right_possibility = isIsomorphic(root1->left, root2->left) & isIsmorphic(root1->right, root2->right);
    bool left_right_right_left_possibility = isIsomorphic(roo1->left, root2->right) & isIsomorphic(roo1->right, root2->left);

    return a | b;
}
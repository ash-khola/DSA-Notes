// Given a Binary Search Tree of size N, find the Median of its Node values, without using an extra space.

// Solution:

int node_count(Node *root) {      // for counting the no. of nodes
    if(!root) {
        return 0;
    }
    
    int left_count = node_count(root->left);
    int right_count = node_count(root->right);
    
    return left_count + right_count + 1;
}

Node *med_node, *prev1;   // pinters to fetch the median node

void median(Node *root, int &count) {   // finding the median node
    if(!root or count <= 0) {
        return;
    }
    
    median(root->left, count);
    if(!med_node) {      // suppose the we get our med_node in above line of code than no need to traverse further.
        if(count == 1) {
            med_node = root;
            count--;
            return;
        }
    
        count--;
        prev1 = root;
        median(root->right, count);
    }
}

float findMedian(struct Node *root)
{
    int count;
    med_node = NULL;
    prev1 = NULL;
    count = node_count(root);
    int med_pos;
    if(count & 1) {
        med_pos = ((count + 1) / 2);
    }
    else {
        med_pos = ((count + 2) / 2);
    }
    median(root, med_pos);
    
    if(count & 1) {
        return med_node->data*1.0;
    }
    else {
        return (med_node->data + prev1->data) / 2.0;
    }
}
// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
// height-balanced binary search tree.

// Solution:
class Solution {
private:
    TreeNode* buildBST(ListNode *head, ListNode *tail) {
        if(head == tail) return NULL;
        if(head->next == tail) {
            TreeNode *newNode = new TreeNode(head->val);
            return newNode;
        }

        ListNode *mid = head, *fast = head;

        while(fast != tail and fast->next != tail) {
            mid = mid->next;
            fast = fast->next->next;
        }

        TreeNode *newNode = new TreeNode(mid->val);

        newNode->left = buildBST(head, mid);
        newNode->right = buildBST(mid->next, tail);
        return newNode;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        return buildBST(head, NULL);
    }
};

// T.C : O(n * log(n))
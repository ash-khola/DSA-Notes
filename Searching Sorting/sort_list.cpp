// Given the head of a linked list, return the list after sorting it in ascending order.

// Solution: 
// It is sorted using a merge sort

ListNode* findMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while(fast != NULL and fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* merge(ListNode *left, ListNode *right) {
    ListNode *head, *join;
    join = head = NULL;
    
    while(left != NULL and right != NULL) {
        if(left->val < right->val) {
            if(join == NULL) {
                join = left;
                head = left;
            }
            else {
                join->next = left;
                join = join->next;
            }
            left = left->next;
        }
        else {
            if(join == NULL) {
                join = right;
                head = right;
            }
            else {
                join->next = right;
                join = join->next;
            }
            right = right->next;
        }
    }
    
    if(left != NULL) {
        join->next = left;
    }
    
    if(right != NULL) {
        join->next = right;
    }

    return head;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL or head->next == NULL) {
        return head;   // don't return NULL here as it may be like head->next == NULL and head != NULL
    }
    ListNode *mid = findMid(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;
    
    left = sortList(left);
    right = sortList(right);
    
    return merge(left, right);
}

// T.C: O(n * log(n))
// S.C: O(1)
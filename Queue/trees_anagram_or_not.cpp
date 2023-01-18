// Given two binary trees, the task is to check if each of their levels are anagrams of each other or not. 


// Solution:
// Anagram : means that at same level of both trees they should have same level data in the nodes, the order of the data don't matter but it should be same on sorting the vector representation of the level traversal for that particaular level.

// We will simply do level order traversal of both the trees and at for each level we will strore the data of the nodes in a vector for both the trees and will match them after sorting them. 

bool areAnagrams(Node *root1, Node *root2)
{
    queue<Node*> q1, q2;
    
    if(root1->data != root2->data) {
        return false;
    }
    
    q1.push(root1);
    q2.push(root2);
    
    while(!q1.empty() and !q2.empty()) {
        int len1 = q1.size(), len2 = q2.size();
        vector<int> vec1, vec2;
        
        for(int i = 0; i < len1; i++) {
            Node *temp = q1.front();
            q1.pop();
            
            if(temp->left) {
                q1.push(temp->left);
                vec1.push_back(temp->left->data);
            }
            
            if(temp->right) {
                q1.push(temp->right);
                vec1.push_back(temp->right->data);
            }
        }
        
        for(int i = 0; i < len2; i++) {
            Node *temp = q2.front();
            q2.pop();
            
            if(temp->left) {
                q2.push(temp->left);
                vec2.push_back(temp->left->data);
            }
            
            if(temp->right) {
                q2.push(temp->right);
                vec2.push_back(temp->right->data);
            }
        }
        
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        
        if(vec1 != vec2) {
            return false;
        }
    }
    
    return true;
}

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)
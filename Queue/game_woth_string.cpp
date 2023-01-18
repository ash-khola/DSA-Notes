// Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character.

// Solution:
// It is an easy question, try to do it yourself wothout seeing the hint at the bottom

int minValue(string s, int k){
    unordered_map<int, int> mp;
    
    for(int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }
    
    priority_queue<int> pq;
    
    for(pair<int, int> a : mp) {
        pq.push(a.second);
    }
    
    while(k > 0) {
        int top_ele = pq.top();
        pq.pop();
        pq.push(--top_ele);
        k--;
    }
    
    int ans = 0;
    
    while(!pq.empty()) {
        ans += pq.top() * pq.top();
        pq.pop();
    }
    
    return ans;
}

// Expected Time Complexity: O(N + Klog(P))  where N is the length of string and P is number of distinct alphabets and K number of alphabets to be removed  (but acc. to me it should be O(N + Plog(P)))
// Expected Auxiliary Space: O(N)

// Hint: The value is minimum when the maximum value is as low as possible.
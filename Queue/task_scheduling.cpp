// Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

// Return the least number of units of times that the CPU will take to finish all the given tasks.


// Solution:

int leastInterval(vector<char>& tasks, int n) {
    priority_queue<int> pq;
    unordered_map<char, int> mp;
    int total_time = 0;
    
    for(int i = 0; i < tasks.size(); i++) {
        mp[tasks[i]]++;
    }
    
    for(auto a : mp) {
        pq.push(a.second);
    }
    
    while(!pq.empty()) {
        vector<int> sequence;
        int time = 0;
        
        for(int i = 0; i < n + 1; i++) {   // cycles of n+1 time if there are enough tasks in the priority_queue than reduce their count by one else let the CPU remain idle 
            if(!pq.empty()) {
                sequence.push_back(pq.top() - 1);
                pq.pop();
                time++;
            }
        }
        
        for(int a : sequence) {
            if(a) {
                pq.push(a);
            }
        }
        
        total_time += pq.empty() ? time : n+1;
    }
    
    return total_time;
}

// T.C: O(n * log(n))
// S.C: O(n)
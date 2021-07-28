// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

// https://leetcode.com/problems/reorganize-string/


string reorganizeString(string s) {
    map<int, int> charCount; // stores the count of all chars
    for(char c : s) {
        charCount[c]++;
    }
    
    priority_queue<pair<int, int>> pq; // max heap based on count of each chat
    for(auto count : charCount) {
        pq.push({count.second, count.first}); // count first, char second
    }
    
    string ans;
    
    pair<int, int> top1, top2;
    
    while(pq.size()) {
        top1 = pq.top();
        pq.pop();
        
        ans += top1.second;
        
        if(pq.size()) {
            ans += pq.top().second;
            top2 = pq.top();
            pq.pop();
            
            if(top2.first > 1) {
                pq.push({top2.first - 1, top2.second});
            }
        }
        
        if(top1.first > 1) {
            pq.push({top1.first - 1, top1.second});
        }
    }
    // if the required string cannot be formed
    for(int i = 0; i < ans.size() - 1; i++) { 
        if(ans[i] == ans[i + 1]) {
            return "";
        }
    }
    
    return ans;
}
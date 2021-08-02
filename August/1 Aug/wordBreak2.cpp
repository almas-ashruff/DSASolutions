// Given a string s and a dictionary of words dict of length n, add spaces in s to construct 
// a sentence where each word is a valid dictionary word. Each dictionary word 
// can be used more than once. Return all such possible sentences.

// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

void helper(string s, vector<string> &temp, vector<string> &ans, int index, unordered_map<string, bool> &mp) {
    if(index == s.size()) {
    // if index reaches end
        string curr = ""; 
        
        for(string st : temp) {
            curr += st + " ";
        } 
        // add words from old array of strings to current 
        // string to make sentence
        
        curr.pop_back(); // remove the space 
        ans.push_back(curr); // push current sentence to answer string
        return;
    }
    
    // else, start with an empty string
    
    string st = ""; 
    for(int i = index; i < s.size(); i++) {
    // go from current index to end of the input string
    // if a word is found in the dictionary, add the word to temp array
    // check for next index through helper
    // remove last word from temp and check for a bigger word (next index chars)
        st += s[i];
        if(mp[st]) {
            temp.push_back(st);
            helper(s, temp, ans, i + 1, mp); 
            temp.pop_back();
        }
    }
}


vector<string> wordBreak(int n, vector<string>& dict, string s) {
    unordered_map<string, bool> mp;
    
    for(string curr : dict) { 
        mp[curr] = true;
    }
    
    // pushes the dictionary words in the map for faster access.
    
    vector<string> temp; // temporary array for checking words
    vector<string> ans; // array containing correct strings
    
    helper(s, temp, ans, 0, mp); // 0 -> index
    
    return ans;
}
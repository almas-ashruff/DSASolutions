// Given a string A and a dictionary of n words B, find out if 
// A can be segmented into a space-separated sequence of dictionary words.

// Note: From the dictionary B each word can be taken any number of times 
// and in any order.

// https://practice.geeksforgeeks.org/problems/word-break1352/1

int wordBreak(string str, vector<string> &B) {
    unordered_set<string> dict;
    for(int i = 0; i < B.size(); i++) {
        dict.insert(B[i]);
    }

    vector<int> dp(str.size());

    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j <= i; j++) {
            string wordToCheck = str.substr(j, i - j + 1);
            if(dict.find(wordToCheck) != dict.end()) { 
                // if word exists between indices j and i
                if(j > 0) { // word starts after the 0th index
                    dp[i] += dp[j - 1];
                } else { // word starts at the 0th index
                    dp[i] += 1;
                }
            }
        }
    }
    return dp[str.size() - 1];
}
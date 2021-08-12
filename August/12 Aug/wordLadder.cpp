// A transformation sequence from word beginWord to word endWord using a dictionary 
// wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need 
// to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, 
// return the number of words in the shortest transformation sequence from 
// beginWord to endWord, or 0 if no such sequence exists.

// https://leetcode.com/problems/word-ladder/

// https://www.youtube.com/watch?v=M9cVl4d0v04


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    
    queue<string> q;
    
    q.push(beginWord);
    int ladder = 1;
    
    while(q.size()) {
        int size = q.size();
        
        for(int i = 0; i < size; i++) {
            string word = q.front();
            q.pop();
            
            if(word == endWord) {
                return ladder;
            }
            
            dict.erase(word);
            
            for(int j = 0; j < word.size(); j++) {
                char c = word[j];
                
                for(int k = 0; k < 26; k++) {
                    word[j] = 'a' + k;
                    if(dict.find(word) != dict.end()) {
                        q.push(word);
                    }
                }
                
                word[j] = c;
            }
        }
        ladder++;
    }
    return 0;
}
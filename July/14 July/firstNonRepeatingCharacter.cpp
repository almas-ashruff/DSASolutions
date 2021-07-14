
// Given an input stream of A of n characters consisting only of lower case alphabets. 
// The task is to find the first non repeating character, each time a character 
// is inserted to the stream. If there is no such character then append '#' to the answer.

// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#


// 1. Freq array stores the frequency of all characters.
// 2. Queue stores all occured characters occured in the string.
// 3. Check the frequency of the character at the front of the queue 
// ... from the frequency array. If it is more than 1, pop it. 
// ... else, add it to the answer string.
// 4. If the queue becomes empty, add '#' to the string.


string FirstNonRepeating(string A){
    int size = A.length();
    int freq[26] = {0}; // we can use a hash-table too.
    
    queue<char> queue;
    string ans = "";
    
    for(int i = 0; i < size; i++) {
        queue.push(A[i]);
        freq[A[i] - 'a']++;

        while(!queue.empty()) {
            char t1 = queue.front() - 'a';
            if(freq[t1] > 1) {
                queue.pop();
            } else {
                break;
            }
        }
        
        if(queue.empty()) {
            ans += '#';
        } else {
            ans += queue.front();
        }
    }
    return ans;
}
// Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', 
// find out the length of the longest valid(well-formed) parentheses substring.
// NOTE: Length of smallest the valid substring ( ) is 2.

// https://practice.geeksforgeeks.org/problems/valid-substring0624/1#

int findMaxLen(string str) {
    int open = 0;
    stack<int> indexStack;
    indexStack.push(-1);
    int ans = 0;
    
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(' ) { // if opening bracket
            open++;
            indexStack.push(i);
        } else { // if closing bracket
            if(open > 0) { // if number of opening bracket > 0
                open--;
                indexStack.pop();
                int len = i - indexStack.top(); // new len
                ans = max(ans, len);
            } else { // abnormal closing bracket
                indexStack.push(i);
            }
        }
    }
    return ans;
}
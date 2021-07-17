// Given string S representing a postfix expression, 
// the task is to evaluate the expression and find the final value. 
// Operators will only include the basic arithmetic operators like *, /, + and -.

// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#

int evaluatePostfix(string s) {
    if(!s.length()) {
        return 0;
    }
     
    stack<int> stack;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') { // it is a number
            stack.push(s[i] - '0'); // push the number in the stack
        } else { // if it is an operator
            int x = stack.top(); // take the top numberr
            stack.pop();
            
            int y = stack.top(); // take the other top number
            stack.pop();
            
            if(s[i] == '+') {
                stack.push(x + y); // add -> push the result in the stack
            } else if(s[i] == '-') {
                stack.push(y - x); // subtract -> push the result in the stack
            } else if(s[i] == '*') {
                stack.push(x * y); // multiply -> push the result in the stack
            } else if(s[i] == '/') {
                stack.push(y / x); // subtract -> push the result in the stack
            } 
        }
    }
    return stack.top(); // return the final result
}
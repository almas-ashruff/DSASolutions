// Given an expression string x. Examine whether the pairs and the orders of 
// “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the function should return 'true' 
// for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#
// https://www.algoexpert.io/questions/Balanced%20Brackets

bool ispar(string x)
{
    if(x.size() % 2 == 1) {
        return false;
    }
    
    stack<char> charStack;
    
    for(char c : x) {
        if(c == ')') {
            if(charStack.empty() || charStack.top() != '(') {
                return false;
            }
            charStack.pop();
        } else if(c == '}') {
            if(charStack.empty() || charStack.top() != '{') {
                return false;
            }
            charStack.pop();
        } else if(c == ']') {
            if(charStack.empty() || charStack.top() != '[') {
                return false;
            }
            charStack.pop();
        } else {
            charStack.push(c);
        }
    }
    return charStack.empty();
}
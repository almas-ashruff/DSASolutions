
// You are given a string S, the task is to reverse the string using stack.

// https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1#

char* reverse(char *S, int len)
{
    stack<char> charStack;
    
    for(int i = 0; i < len; i++) {
        char c = S[i];
        charStack.push(c);
    }
    
    int i = 0;
    while(!charStack.empty()) {
        S[i] = charStack.top();
        charStack.pop();
        i++;
    }
    return S;
}

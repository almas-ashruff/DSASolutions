Given a number K and string str of digits denoting a positive integer, 
build the largest number possible by performing swap operations on the digits of str at most K times.

https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#

https://www.youtube.com/watch?v=5crucASFoA4

void helper(string &str, int k, string &maxString, int index) {
    if(k == 0) {
        return;
    }
    
    char currentChar = str[index];
    
    for(int i = index + 1; i < str.size(); i++) {
        if(str[i] > currentChar) {
            currentChar = str[i];
        }
    }
    
    if(currentChar != str[index]) {
        k--;
    }
    
    for(int i = index; i < str.size(); i++) {
        if(str[i] == currentChar) {
            swap(str[i], str[index]) ;
            maxString = max(maxString, str);
            helper(str, k, maxString, index + 1);
            swap(str[i], str[index]);
        }
    }
}


string findMaximumNum(string str, int k)
{
   int index = 0;
   
   string maxString = "";
   
   helper(str, k, maxString, index);
   return maxString == "" ? str : maxString;
}
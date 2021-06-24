#include <bits/stdc++.h>
using namespace std;


// Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.


// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#
// https://www.algoexpert.io/questions/Balanced%20Brackets

// Solution is self explanatory

bool ispar(string str) {      
    stack<char> stck;
    
    for(char curr : str) {
        
        if(curr == ')' ) {
            if(stck.empty() || stck.top() != '(' ) {
                return false;
            } 
            stck.pop();
        } 
        
        else if(curr == '}' ) {
            if(stck.empty() || stck.top() != '{' ) {
                return false;
            } 
            stck.pop();
        } 
        
        else if(curr == ']' ) {
            if(stck.empty() || stck.top() != '[' ) {
                return false;
            } 
            stck.pop();
        } 
        
        else {
            stck.push(curr);
        }
    }
    return stck.empty();
}
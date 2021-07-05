#include <vector>
using namespace std;

// Given a string in roman no format (s)  your task is to convert it to an integer .

// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
// https://www.youtube.com/watch?v=hEhf_oz3wsM


int romanToDecimal(string &str) {
    unordered_map<char, int> digits;
    
    digits['I'] = 1;
    digits['V'] = 5;
    digits['X'] = 10;
    digits['L'] = 50;
    digits['C'] = 100;
    digits['D'] = 500;
    digits['M'] = 1000;
    // store all numbers in a hash table
    
    int result = 0;
    // if current number is larger than the previous number, subtract the previous number after nullyfying
    // ... its addition, and also add the current number.
    for(int i = 0; i < str.size(); i++) {
        if(i > 0 && digits[str[i]] > digits[str[i - 1]]) {
            result += (digits[str[i - 1]] * -2) + digits[str[i]];
        } else {
            result += digits[str[i]];
            // else add the current number
        }
    }
    return result;
    
}
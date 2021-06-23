#include <bits/stdc++.h>
using namespace std;

// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.

// https://leetcode.com/problems/count-and-say/

// Leetcode - Medium

string countAndSay(int n) {
    string countAndSayString= "1";  //string off with this string
    string newCountAndSayString="";  // New string at every round
    
    for(int i=1; i<n; i++) { 
        // since one round is sone, i = 1. This loop keeps track of the rounds
        for(int j = 0; j < countAndSayString.size(); j++) { 
            // finding the new string for each round
            int count = 0;
            char k = countAndSayString[j];

            while(countAndSayString[j] == k) {
                // Loop to find the number of same characters 
                count++;
                j++;                        
            }
            j--;
            // j-- because j is one extra when leaving the loop
            newCountAndSayString += to_string(count);
            // change to string because the count variable is an int
            newCountAndSayString += k;
        }
        countAndSayString = newCountAndSayString;
        newCountAndSayString = "";
        // when one round is done, new string is saved and a new new-string is created.
    }
    return countAndSayString;
}
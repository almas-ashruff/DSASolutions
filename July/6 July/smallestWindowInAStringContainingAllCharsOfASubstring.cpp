#include <bits/stdc++.h>
using namespace std;

// Given two strings S and P. Find the smallest window in the S consisting of all the characters of P.
// https://www.algoexpert.io/questions/Smallest%20Substring%20Containing
// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

// Sliding window approaches -> both

// GFG Solution
string smallestWindow (string s, string p)
{
    int hash[256] = {0};
    int uniqueWords = 0;
    
    for(int i = 0; i < p.size(); i++)
    {
        if(hash[p[i]] == 0)
        {
            uniqueWords++;
        }
        
        hash[p[i]]++;
    }
    
    int resCount = INT_MAX;
    int resStart = 0;
    
    int i = 0, j = 0;
    
    while(j < s.size())
    {
        hash[s[j]]--;
        
        if(hash[s[j]] == 0)
        {
            uniqueWords--;
        }
        
        if(uniqueWords == 0)
        {
            while(uniqueWords == 0)
            {
                if(resCount > j - i + 1)
                {
                    resCount = min(resCount, j - i + 1);
                    
                    resStart = i;
                }
                
                hash[s[i]]++;
                
                if(hash[s[i]] > 0)
                {
                    uniqueWords++;
                }
                
                i++;
            }
        }
        
        j++;
    }
    
    
    if(resCount == INT_MAX)
    {
        return "-1";
    }
    
    return s.substr(resStart, resCount);
}




// AlgoExpert Solution


string smallestSubstringContaining(string bigString, string smallString) {
  unordered_map<char, int> targetCharCounts = getCharCounts(smallString);
	vector<int> substringBounds = getSubstringBounds(bigString, targetCharCounts);
	return getStringFromBounds(bigString, substringBounds);
}

unordered_map<char, int> getCharCounts(string str) {
	unordered_map<char, int> charCounts;
	for(char c : str) {
		increaseCharCount(c, charCounts);
	}
	return charCounts;
}
vector<int> getCloserBounds(int idx1, int idx2, int idx3, int idx4) {
	return idx2 - idx1 < idx4 - idx3 ? vector<int> {idx1, idx2} : vector<int>{idx3, idx4};
}


vector<int> getSubstringBounds( string str, unordered_map<char, int> targetCharCount){
	vector<int> substringBounds = {0, INT_MAX};
	unordered_map<char, int> substringCharCounts;
	int numUniqueChars = targetCharCount.size();
	int numUniqueCharsDone = 0;
	int leftIdx = 0;
	int rightIdx = 0;
	
	while(rightIdx < str.size()) {
		char rightChar = str[rightIdx];
		if(targetCharCount.find(rightChar)== targetCharCount.end()) {
			rightIdx++;
			continue;
		}
		increaseCharCount(rightChar, substringCharCounts);
		if(substringCharCounts[rightChar] == targetCharCount[rightChar]) {
			numUniqueCharsDone++;
		}
		
		while(numUniqueCharsDone == numUniqueChars && leftIdx <= rightIdx) {
			substringBounds = getCloserBounds(leftIdx, rightIdx, substringBounds[0], substringBounds[1]);
			char leftChar = str[leftIdx];
			
			if(targetCharCount.find(leftChar) == targetCharCount.end()) {
				leftIdx++;
				continue;
			}
			
			if(substringCharCounts[leftChar] == targetCharCount[leftChar]) {
				numUniqueCharsDone--;
			}
			decreaseCharCount(leftChar, substringCharCounts);
			leftIdx++;
		}
		rightIdx++;
	}
	return substringBounds;
}


void increaseCharCount(char c, unordered_map< char, int> &charCounts) {
	if(charCounts.find(c) == charCounts.end()) {
		charCounts[c] = 1;
	} else {
		charCounts[c]++;
	}
}

void decreaseCharCount (char c, unordered_map<char, int> &charCounts) {
	charCounts[c]--;
}

string getStringFromBounds(string str, vector<int> bounds) {
	int start = bounds[0];
	int end = bounds[1];
	if(end == INT_MAX) {
		return "";
	}
	return str.substr(start, end - start + 1);
}
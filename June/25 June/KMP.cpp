#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT VERY HARD QUESTION
// Watch code walkthrough
// https://www.algoexpert.io/questions/Knuth%E2%80%94Morris%E2%80%94Pratt%20Algorithm
//  


vector<int> buildPattern(string substr);
bool doesMatch(string str, string substr, vector<int> pattern); 

bool knuthMorrisPrattAlgorithm(string str, string substr) {
  vector<int> pattern = buildPattern(substr);
	return doesMatch(str, substr, pattern);
}

vector<int> buildPattern(string substr) {
    // build pattern array for the substr

	vector<int> pattern(substr.size(), - 1);
	int j = 0;
	int i = 1;
	
	while(i < substr.size()) {
		if(substr[i] == substr[j]) {
            // if the same character is encountered
			pattern[i] = j;
            // value in the pattern array is stored of the 
            // ... previous index at which the matching character was found
			i++;
			j++;
		} else if (j > 0) {
            // if matching char is not found, and j is not at the 0th index, current char for comparision is the 
            // ... previous matching char's earlier occurance's next index's char
			j = pattern[j - 1] + 1;
		} else {
            // if j is at the 0th index, increase i
			i++;
		}
	}
    // return pattern array
	return pattern;
}

bool doesMatch(string str, string substr, vector<int> pattern) {
	int i = 0;
	int j = 0;
	
	while(i + substr.size() - j <= str.size()) {
		if(str[i] == substr[j]) {
			if(j == substr.size() - 1) {
				return true;
			}
			i++;
			j++;
		} else if (j > 0) {
				j = pattern[j - 1] + 1;
		} else {
			i++;
		}
	}
	return false;
}

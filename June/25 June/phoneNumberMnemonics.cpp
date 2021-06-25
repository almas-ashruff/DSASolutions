#include <bits/stdc++.h>
using namespace std;

// Given a sentence in the form of a string, convert it into its 
// equivalent mobile numeric keypad sequence. 
 
// https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/
// https://www.algoexpert.io/questions/Phone%20Number%20Mnemonics

unordered_map<int, vector<char>> digitLetters {
	{0, {'0'}}, {1,{'1'}}, {2,{'a','b','c'}},
	{3, {'d','e','f'}}, {4,{'g','h','i'}}, {5,{'j','k','l'}},
	{6,{'m','n','o'}}, {7,{'p','q','r','s'}},{8,{'t','u','v'}},
	{9,{'w','x','y','z'}}
};


void phoneNumberMnemonicsHelper(int idx, string phoneNumber, vector<char> &currentMnemonics, vector<string> &mnemonicsFound){
	if(idx == phoneNumber.size()){
		string mnemonics = accumulate(currentMnemonics.begin(), currentMnemonics.end(),string{});
		mnemonicsFound.push_back(mnemonics);
	} else {
		int digit = phoneNumber[idx] - '0';
		vector<char> letters = digitLetters[digit];
		for(auto letter : letters){
			currentMnemonics[idx] = letter;
			phoneNumberMnemonicsHelper(idx + 1, phoneNumber, currentMnemonics, mnemonicsFound);
		}
	}
}


vector<string> phoneNumberMnemonics(string phoneNumber) {
  vector<char> currentMnemonics(phoneNumber.size(), 0);
	vector<string> mnemonicsFound;
	cout<<(int)'4'<<endl;
	phoneNumberMnemonicsHelper(0, phoneNumber, currentMnemonics, mnemonicsFound);
	return mnemonicsFound;
}

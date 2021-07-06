#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Return a list of all valid addresses that can be formed from the current string.

// https://www.algoexpert.io/questions/Valid%20IP%20Addresses

bool isValidPart(string str);
string join(vector<string> strings);
vector<string> validIPAddresses(string str);

// checks if the given substring is valid as a given IP address part
bool isValidPart(string str){
	int stringAsInt = stoi(str);
	
	if(stringAsInt > 255){
		return false;
	}
	if(str.length() != to_string(stringAsInt).length()){
		return false;
	}
	return true;
}

// joins the final result with '.' 
string join(vector<string> strings){
	string s;
	for(int l = 0; l < strings.size(); l++){
		s += strings[l];
		if(l < strings.size() - 1) {
			s += ".";
		}
	}
	return s;
}



vector<string> validIPAddresses(string str) {
	
	vector<string> ipAddressesFound;
	
    for(int i = 1; i < min((int)str.length(), 4); i++){
		vector<string> currentIpAddressParts = {"", "", "", ""};
        // current sections, consisting of four subsections
		
		currentIpAddressParts[0] = str.substr(0, i); // first subsection
		if(!isValidPart(currentIpAddressParts[0])){
			continue;
		}
		
		for(int j = i + 1; j < i + min((int)str.length() - i, 4); j++){ // second subsection
			currentIpAddressParts[1] = str.substr(i, j - i);
			if(!isValidPart(currentIpAddressParts[1])){
				continue;
			}
			
			for(int k = j + 1; k < j + min((int)str.length() - j, 4); k++){
				currentIpAddressParts[2] = str.substr(j, k - j); // third subsection
				currentIpAddressParts[3] = str.substr(k); // fourth subsection
				
				if(isValidPart(currentIpAddressParts[2]) && isValidPart(currentIpAddressParts[3])){
					ipAddressesFound.push_back(join(currentIpAddressParts));
				}
			}
		}
	}
	return ipAddressesFound;
}

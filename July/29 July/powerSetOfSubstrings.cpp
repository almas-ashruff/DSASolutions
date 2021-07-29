// Given a string S find all possible substrings of the string in 
// lexicographically - sorted order.

// https://practice.geeksforgeeks.org/problems/power-set4302/1#

void generatePossibleStrings(string str, vector<string> &res, int index = 0, string curr = "")
{
    if(index == str.size())
    {
        if(curr != "")
        {
            res.push_back(curr);
        }
        
        return;
    }
    
    generatePossibleStrings(str, res, index + 1, curr); 
    // recurse to create without char at index
    generatePossibleStrings(str, res, index + 1, curr + str[index]);
    // recurse to create string with chat at index (concat str[index] to curr)
}

vector<string> AllPossibleStrings(string str)
{
    vector<string> res;
    
    generatePossibleStrings(str, res);
    
    sort(res.begin(), res.end());
    
    return res;
}
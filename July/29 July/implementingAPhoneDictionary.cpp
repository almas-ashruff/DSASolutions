// Given a list of contacts contact[] of length n where 
// each contact is a string which exist in a phone directory and a query string s. 
// The task is to implement a search query for the phone directory. 
// Run a search query for each prefix p of the query string s 
// (i.e. from  index 1 to |s|) that prints all the distinct contacts 
// which have the same prefix as p in lexicographical increasing order. 
// Please refer the explanation part for better understanding.
// Note: If there is no match between query and contacts, print "0".

// https://practice.geeksforgeeks.org/problems/phone-directory4628/1#


struct trie {
    trie *child[26];
    int val = 0;
    
    trie() {
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
            val = 0;
        }
    }
};

void insert(trie *root, string s) {
    for(char x : s) {
        int curr = x - 'a';
        if(root -> child[curr] == NULL) {
            root -> child[curr] = new trie();
        }
        root = root -> child[curr];
    }
    root -> val = 1;
}

vector<string> res;
string str;

void dfs(trie *root) {
    if(root -> val == 1) {
        res.push_back(str);
    }
    
    for(int i = 0; i < 26; i++) {
        if(root -> child[i]) {
            str += char(i + 'a');
            dfs(root -> child[i]);
            str.pop_back();
        }
    }
}

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    vector<string> pro;
    
    for(int i = 0; i < n; i++) {
        pro.push_back(contact[i]);
    }
    
    trie *root = new trie();
    
    vector<vector<string>> ans;
    
    for(auto x : pro) {
        insert(root, x);
    }
    
    for(char x : s) {
        if(root -> child[x - 'a'] != NULL) {
            str = "";
            res.clear();
            dfs(root -> child[x - 'a']);
            ans.push_back(res);
            root = root -> child[x - 'a'];
        } else {
            break;
        }
    }
    
    int i = 0;
    string fin = "";
    
    for(auto &x : ans) {
        fin += s[i];
        i++; // adding the prefixes of the search word
        
        for(string &st : x) {
            st = fin + st;
        }
    }
    
    while(ans.size() < s.size()) {
        ans.push_back({{"0"}});
    }
    
    return ans;
}
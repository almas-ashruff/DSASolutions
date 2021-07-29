// Trie is an efficient information retrieval data structure. 
// Use this data structure to store Strings and search strings. 
// Your task is to use TRIE data structure and search the given string A. 
// If found print 1 else 0.

// https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1#

void insert(struct TrieNode *root, string key)
{
    TrieNode *head = root;
    
    for(int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if(head -> children[index] == NULL) {
            head -> children[index] = getNode();
        }
        head = head -> children[index];
    }
    head -> isLeaf = 1;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    TrieNode *head = root;
    
    for(int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if(head -> children[index] == NULL) {
            return 0;
        }
        head = head -> children[index];
    }
    return (head -> isLeaf);
}
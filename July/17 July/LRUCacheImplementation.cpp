// Implement LRU cache

// https://www.algoexpert.io/questions/LRU%20Cache

using namespace std;

class DoublyLinkedListNode {
public:
	string key; // stores the key to the node
	int value; // stores the corresponding value to the key
	DoublyLinkedListNode *prev;
	DoublyLinkedListNode *next; // storing the prev and next pointers for the nodes

	DoublyLinkedListNode(string key, int value) { // creating a new node
		this -> key = key;
		this -> value = value;
		this -> prev = NULL;
		this -> next = NULL;
	}
	
	void removeBindings() { // removes the binding to the previous and the next nodes
		if(this -> prev) { // if a previous node exists
			this -> prev -> next = this -> next;
		}
		
		if(this -> next) { // if a next node exists
			this -> next -> prev = this -> prev;
		}
		
		this -> prev = NULL;
		this -> next = NULL;
	}
};

class DoublyLinkedList {
public:
	DoublyLinkedListNode *head;
	DoublyLinkedListNode *tail;
	
	DoublyLinkedList() {
		this -> head = NULL;
		this -> tail = NULL;
	}
	
	void setHeadTo(DoublyLinkedListNode *node) { // set the new head
		if(this -> head == node) { // if it is already set to node
			return; // do nothing
		} else if(!this -> head) { // if the head is empty
			this -> head = node;
			this -> tail = node;
			// only one node exists now
		} else if(this -> head == this -> tail) { // if only one node exists
			this -> tail -> prev = node;
			this -> head = node;
			this -> head -> next = this -> tail; // current node exists as head now
		} else { // if multiple nodes exist
			if(this -> tail == node) { // if node is tail, remove it as tail
				this -> removeTail();
			}
			
			node -> removeBindings(); // remove the bindings of the node
			this -> head -> prev = node; // adds the current node at first position
			node -> next = this -> head;
			this -> head = node; // making the current node as the head
		}
	}
	
	void removeTail() {
		if(!this -> tail) { // if no tail exists, return
			return;
		}
		
		if(this -> tail == this -> head) { // if only one node exists
			this -> head = NULL;
			this -> tail = NULL;
			return;
		}
		// when more nodes exist
		this -> tail = this -> tail -> prev;
		this -> tail -> next = NULL;
	}
};

class LRUCache {
public:
	unordered_map <string, DoublyLinkedListNode *> cache; // the hash table whose key points to the doubly linked list node storing the corresponding value. Hash table is necessary for an O(1) time complexity
  int maxSize; // max capacity
	int currentSize; // current number of nodes
	DoublyLinkedList listOfMostRecent; // the doubly linked list 

  LRUCache(int maxSize) { 
		this -> maxSize = maxSize > 1 ? maxSize : 1;
		// if maxsize > 1, maxsize is gonna be the input maxsize, else 1
		this -> currentSize = 0; // current size is 0 as no value is initialized
		this -> listOfMostRecent = DoublyLinkedList(); // initialize a doubly linked list to store the nodes
	}

	// O(1) time and space
  void insertKeyValuePair(string key, int value) {
    if(this -> cache.find(key) == this -> cache.end()) {
		// if the key does not exist in the cache
			if(this -> currentSize == this -> maxSize) {
			// if the cache is full
				this -> evictLeastRecent(); // remove the last node
			} else {
				this -> currentSize++; // increase the current size
			}
			this -> cache[key] = new DoublyLinkedListNode(key, value); // create a new node
		} else { // if key exists in the cache
			this -> replaceKey(key, value); // replace value
		}
		this -> updateMostRecent(this -> cache[key]); // put the node at the front
	}

  int *getValueFromKey(string key) {
    if(this -> cache.find(key) == this -> cache.end()) { // if value does not exist
			return NULL;
		}
		this -> updateMostRecent(this -> cache[key]); // update most recently accessed
		return &this -> cache[key] -> value; // return the value;
  }

  string getMostRecentKey() {
    if(!this -> listOfMostRecent.head) {
			return " "; // if no value exists
		}
		return this -> listOfMostRecent.head -> key;
  }
	
	void evictLeastRecent() { // remove the last node when cache is filled
		string keyToRemove = this -> listOfMostRecent.tail -> key;
		this -> listOfMostRecent.removeTail();
		this -> cache.erase(keyToRemove);
	}
	
	void updateMostRecent(DoublyLinkedListNode *node) { // update the most recent key
		this -> listOfMostRecent.setHeadTo(node);
	}
	
	void replaceKey(string key, int value) { // replace the key
		if(this -> cache.find(key) == this -> cache.end()) { // if key is not found in the cache
			return;
		}
		this -> cache[key] -> value = value;
	}
};

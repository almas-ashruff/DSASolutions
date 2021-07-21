// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1#



vector <int> zigZagTraversal(Node* root)
{
	stack<Node *> s1;
	stack<Node *> s2;
	vector<int> res;
	
	if(!root) {
	    return res;
	}
	
	s1.push(root);
	int i = 1;
	
	res.push_back(root -> data);
	
	while(!s2.empty() || !s1.empty()) {
	    if(i == 1) {
	        Node *node = s1.top();
	        s1.pop();
	        
	        if(node -> right) {
	            res.push_back(node -> right -> data);
	            s2.push(node -> right);
	        }
	        
	        if(node -> left) {
	            res.push_back(node -> left -> data);
	            s2.push(node -> left);
	        }
	    } else if(i == -1) {
	        Node *node = s2.top();
	        s2.pop();
	        
	        if(node -> left) {
	            res.push_back(node -> left -> data);
	            s1.push(node -> left);
	        }
	        
	        if(node -> right) {
	            res.push_back(node -> right -> data);
	            s1.push(node -> right);
	        }
	    }
	    
	    if(s1.empty()) {
	        i = -1;
	    } else if(s2.empty()) {
	        i = 1;
	    }
	}
	
	return res;
}
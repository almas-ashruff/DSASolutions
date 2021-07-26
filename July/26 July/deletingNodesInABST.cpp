// Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
// Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.

// https://leetcode.com/problems/delete-node-in-a-bst/

// https://www.youtube.com/watch?v=5_AZcOOc-kM

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
        return root;
    }
    
    if (root -> val > key) {
        root -> left = deleteNode(root -> left, key);
    } else if (root->val < key) {
        root -> right = deleteNode(root -> right, key);
    } else { // equal
        // Leaf node case 
        if (!root -> left && !root -> right) {
            delete(root);
            return NULL;
        }
        // 1 child case
        if (!root -> left || !root -> right) {
            TreeNode *temp = root -> left ? root->left : root->right;
            delete(root);
            return temp;
        }
        // 2 child case 
        if (root -> left && root -> right) {
            TreeNode *temp = root -> right;
            while (temp -> left) {
                temp = temp -> left;
            }
            root -> val = temp -> val;
            root -> right = deleteNode(root -> right, root -> val);
        }
    }
    return root;
}


// OR - FOR THE 2 CHILD CASE :

 // 2 child case 
    //         if (root -> left && root -> right) {
    //             TreeNode *temp = root -> left;
    //             while (temp -> right) {
    //                 temp = temp -> right;
    //             }
    //             root -> val = temp -> val;
    //             root -> left = deleteNode(root -> left, root -> val);
    //         }
    //     }
    //     return root;
    // }
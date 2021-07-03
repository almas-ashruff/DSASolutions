#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT HARD QUESTION
// To check that out of three nodes, for one, the other two are ancestors and decendents

// https://www.algoexpert.io/questions/Validate%20Three%20Nodes

// SOLUTION 1 
// check if node one is descendant of two, if yes, check if node two is descendant of three
// check if node three is descendant of two, if yes, check is two is descendant of one
// else return false

// O(H) time o(1) space
bool isDescendant(BST *node, BST *target);

bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree){
    if(isDescendant(nodeTwo, nodeOne)){
        return(isDescendant(nodeThree, nodeTwo));
    }
    if(isDescendant(nodeTwo, nodeThree)){
        return isDescendant(nodeOne, nodeTwo);
    }

    return false;
}

bool isDescendant(BST *node, BST *target){
    BST *currentNode = node;
    while(currentNode != NULL && currentNode != target){
        currentNode = target -> value < currentNode -> value ? currentNode -> left : currentNode -> right;
    }
    return currentNode == target;
}


// SOLUTION 2
// Find node two from node one AND node two from node three using loop
// If node two is found, or if node three OR one is found, or if both searches reach NULL, break the loop.
// If node two is not found or if one of the edge nodes are found, return false
// Else -
// Check which node found node two, and from node two, find the remaining edge node (one or three)
// if the edge node is found, return true, else false
// O(d) time O(1) space, d = distance between nodes


bool searchForTarget(BST *node, BST *target);

bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree){
    BST *firstSearch = nodeOne;
    BST *secondSearch = nodeThree;

    while(true){
        bool foundThreeFromOne = firstSearch == nodeThree;
        bool foundOneFromThree = secondSearch == nodeOne;
        bool foundNodeTwo = firstSearch == nodeTwo || secondSearch == nodeTwo;
        bool finishedSearching = firstSearch == NULL && secondSearch == NULL;

        if(foundThreeFromOne || foundOneFromThree || foundNodeTwo || finishedSearching){
            break;
        }

        if(firstSearch != NULL){
            firstSearch = firstSearch -> value > nodeTwo -> value ? firstSearch -> left : firstSearch -> right;
        }

        if(secondSearch != NULL){
            secondSearch = secondSearch -> value > nodeTwo -> value ? secondSearch -> left : secondSearch -> right;
        }
    }

    bool foundNodeFromOther = firstSearch == nodeThree || secondSearch == nodeOne;
    bool foundNodeTwo = firstSearch == nodeTwo || secondSearch == nodeTwo;

    if(!foundNodeTwo || foundNodeFromOther){
        return false;
    }
    
    return searchForTarget(nodeTwo, firstSearch == nodeTwo ? nodeThree : nodeOne);
}


bool searchForTarget(BST *node, BST *target){
    BST *currentNode = node;
    while(currentNode != NULL && currentNode != target){
        currentNode = target -> value < currentNode -> value ? currentNode -> left : currentNode -> right;
    }

    return currentNode == target;
}
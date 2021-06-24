#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT HARD 
// https://www.algoexpert.io/questions/Max%20Path%20Sum%20In%20Binary%20Tree

vector<int> findMaxSum(BinaryTree *tree);

int maxPathSum(BinaryTree tree){
    vector<int> maxSumArray = findMaxSum(&tree);
    return maxSumArray[1];
    //maxSumArray contains -> maxSumAsBranch (considering only one branch + node value),
    // and maxPathSum, overall maximum path sum

}

vector<int> findMaxSum(BinaryTree *tree){
    if(!tree){
        return vector<int> {0, INT_MIN};
    }

    vector<int> leftMaxSumArray = findMaxSum(tree -> left);
    int leftMaxSumAsBranch = leftMaxSumArray[0]; //maxSumAsBranch of the left subtree
    int leftMaxPathSum = leftMaxSumArray[1]; //the max path sum of the left subtree

    vector<int> rightMaxSumArray = findMaxSum(tree -> right);
    int rightMaxSumAsBranch = rightMaxSumArray[0]; //maxSumAsBranch of the left subtree
    int rightMaxPathSum = rightMaxSumArray[1]; //the max path sum of the left subtree

    int maxChildSumAsBranch = max(leftMaxSumAsBranch, rightMaxSumAsBranch); //checking which subtree as branch has bigger value
    int maxSumAsBranch = max(maxChildSumAsBranch + tree -> value, tree -> value ); //max sum as branch -> including the subtree, or excluding the subtree?
    int maxSumAsRootNode = max(leftMaxSumAsBranch + tree -> value + rightMaxSumAsBranch, maxSumAsBranch); //checking if max value is as branch, or a triangle
    int maxPathSum = max(leftMaxPathSum, max(rightMaxPathSum, maxSumAsRootNode)); //checking the max path sum till now is either from left subtree, right subtree, or the current traingle

    return vector<int> {maxSumAsBranch, maxPathSum}; //putting the value in an array and returning
}

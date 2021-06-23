#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int left = matrix[0][0], right = matrix.back().back();
    while (left < right) {
        int mid = left + (right - left) / 2;
        int cnt = search_less_equal(matrix, mid);
        if (cnt < k) left = mid + 1;
        else right = mid;
    }
    return left;
}
	
//compare from the left bottom corner of the matrix: If the element here <= mid, 
// then all the element above < mid, and we sum them up with res += i+1; 
// Then we go right(++j), 
// if element here > mid, we go up (i--).//

int search_less_equal(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), i = n - 1, j = 0, res = 0;   //i：行  j: 列
    while (i >= 0 && j < n) {
        if (matrix[i][j] <= target) {
            res += i + 1;
            ++j;
        } else {
            --i;
        }
    }
    return res;
}




// left: smallest number in each left side
// right: biggest number in each right side

// compare from the left bottom corner of the matrix: If the element here <= mid,
// then all the element above < mid, and we sum them up with res += i+1;
// Then we go right(++j),
// if element here > mid, we go up (i--)

// finally, if left == right, which means there are no element between them. We found the kth smallest value
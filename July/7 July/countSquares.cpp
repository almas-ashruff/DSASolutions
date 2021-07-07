#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/count-squares3649/1

int countSquares(int N) {
    int num = sqrt(N);
    if (num * num < N) {
        return num;
    } else {
        return num - 1;
    }
}
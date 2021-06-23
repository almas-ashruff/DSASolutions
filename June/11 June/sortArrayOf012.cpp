#include <bits/stdc++.h>
using namespace std;
// Sort an array containing only 0, 1, 2 withiut using a sorting algorithm
// SOLUTION 1
// Run three indices
// if value == firstval, swap with first index and  increment first and second indices;
// if value == thirdval, swap with third val and ONLY decrement third index;
// else increment second index;
// loop till second index is greater than third
void sort012(int a[], int n)
 {
     int firstIdx = 0, secondIdx = 0, thirdIdx = n - 1;
     while(secondIdx <= thirdIdx){
         int num = a[secondIdx];
         if(num == 0){
             swap(a[firstIdx], a[secondIdx]);
             secondIdx++;
             firstIdx++;
         } else if(num == 2){
             swap(a[secondIdx], a[thirdIdx]);
             thirdIdx--;
         } else{
             secondIdx++;
         }
     }
 }
    
#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reverse-a-string/1

string reverseWord(string str) {
  for(int i = 0; i < str.size() / 2; i++) {
      swap(str[i], str[str.size() - i - 1]);
  }
  return str;
}
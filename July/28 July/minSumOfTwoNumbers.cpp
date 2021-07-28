// Given an array Arr of size N such that each element is from the range 0 to 9. 
// Find the minimum possible sum of two numbers formed using the elements of the array. 
// All digits in the given array must be used to form the two numbers.

// https://practice.geeksforgeeks.org/problems/minimum-sum4058/1


string sum(string &first,string &second)
{
    if(first.length()<second.length())
    {
        swap(first,second);
    }
    string res="";
    int i=first.length()-1,j=second.length()-1,carry=0;
    while(i>=0 || j>=0)
    {
        int sum=(i>=0?first[i--]-'0':0)+(j>=0?second[j--]-'0':0)+carry;
        res.push_back((sum%10)+'0');
        carry=sum/10;
    }
    if(carry)
    {
        res.push_back(carry+'0');
    }
    reverse(res.begin(),res.end());
    while(!res.empty() && res[0]=='0')
    {
        res.erase(res.begin());
    }
    return res;
}
string solve(int arr[], int n) 
{
    sort(arr,arr+n);
    string first="",second="";
    for(int i=0;i<n;i+=2)
    {
        first.push_back(arr[i]+'0');
        if(i+1<n)
        {
            second.push_back(arr[i+1]+'0');
        }
    }
    return sum(first,second);
}
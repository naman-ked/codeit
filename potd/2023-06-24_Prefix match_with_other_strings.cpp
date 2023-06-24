/*
Given an array of strings arr[] of size n, a string str and an integer k.
The task is to find the count of strings in arr[] whose prefix of length k matches with the k-length prefix of str.

Example 1:
Input:
n = 6
arr[] = {“abba”, “abbb”, “abbc”, “abbd”, “abaa”, “abca”}
str = “abbg”
k = 3
Output: 
4 
Explanation: “abba”, “abbb”, “abbc” and “abbd” have their prefix of length 3 equal to 3-length prefix of str i.e., "abb".
*/

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
         if (k > str.length())
            return 0;
        string temp = str.substr(0, k);
        int count = 0;
        for (int i = 0; i < n; i++)
        {  
            if (temp == arr[i].substr(0, k))
            {
            count++;
            }
        }
        return count;
    }
};

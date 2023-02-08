/*
Given a Matrix size N*N and an integer K. Initially, the matrix contains only 0. 
You are given K tasks and for each task, you are given two coordinates (r,c) [1 based index]. 
Where coordinates (r,c) denotes rth row and cth column of the given matrix.
You have to perform each task sequentially in the given order. For each task, You have to put 1 in all rth row cells and all cth columns cells.
After each task, You have to calculate the number of 0 present in the matrix and return it.

Example 1:
Input:
n = 3, k= 3
2 2
2 3
3 2
Output: 4 2 1
Explanation: After 1st Operation, all the 2nd row and all the 2nd column will be filled by 1. So remaning cell with value 0 will be 4 After 2nd Operation, 
all the 2nd row and all the 3rd column will be filled by 1. So remaning cell with value 0 will be 2.After 3rd Operation cells having value 0 will be 1.
*/

class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      long long int res=n*n;           // initial number of zeroes
      vector<long long int> zero;      // result vector
      unordered_set<long long int> r;  // row set
      unordered_set<long long int> c;  // column set
      for(int i=0;i<k;i++){   // O(k)
          if(r.find(arr[i][0])==r.end()){   
              r.insert(arr[i][0]);
              res=res-n+c.size();           // logic 1
          }
          if(c.find(arr[i][1])==c.end()){
              res=res-n+r.size();
              c.insert(arr[i][1]);        // logic 2
          }
          zero.push_back(res);
      }
      return zero;
  }
};

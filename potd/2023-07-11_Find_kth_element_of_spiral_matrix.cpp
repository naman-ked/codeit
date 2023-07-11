/*
Given a matrix with n rows and m columns.
Your task is to find the kth element which is obtained while traversing the matrix spirally. 
You need to complete the method findK which takes four arguments the first argument is the matrix A and the next two arguments will be n and m denoting the size of the matrix A and then the forth argument is an integer k. 
The function will return the kth element obtained while traversing the matrix spirally.

Example 1:
Input:
n = 4, m = 4, k = 10
A[][] = {{1  2  3  4},{5  6  7  8}, {9  10 11 12}, {13 14 15 16}}
Output: 13
*/

class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int i, top=0, down=n-1, left=0, right=m-1, dir=0, ans=-1;
        while(top<=down && left<=right) {
            if(dir==0) {
                for(i=left;i<=right;i++) {
                    k--;
                    if(k==0) {
                        ans = a[top][i];
                        break;
                    }
                }
                top++;
            }
            else if(dir==1) {
                for(i=top;i<=down;i++) {
                    k--;
                    if(k==0) {
                        ans = a[i][right];
                        break;
                    }
                }
                right--;
            }
            else if(dir==2) {
                for(i=right;i>=left;i--) {
                    k--;
                    if(k==0) {
                        ans = a[down][i];
                        break;
                    }
                }
                down--;
            }
            else if(dir==3) {
                for(i=down;i>=top;i--) {
                    k--;
                    if(k==0) {
                        ans = a[i][left];
                        break;
                    }
                }
                left++;
            }
            dir++;
            dir=dir%4;
            if(k==0) break;
        }
        return ans;
    }
};

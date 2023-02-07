/*
Given an array arr[] consisting of n integers, find the length of the longest subarray with positive (non zero) product. 

Example 1:
Input:
arr[] ={0, 1, -2, -3, -4} 
Output: 3
Explanation: 
The longest subarray with positive product is: {1, -2, -3}.Therefore, the required length is 3.

*/

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           long long int g_max=0,c_max=1,c_start=0,start=0,p=1;
           for(int i=0;i<n;i++){
               if(arr[i]==0){
                   start=i+1;
                   c_start=i+1;
                   p=1;
                   c_max=1;
               }
               else{
                   p=p*arr[i];
                   c_max*=arr[i];
                   //for debugging
                   //cout<<c_max<<" "<<p<<" "<<start<<"  "<<c_start<<" "<<g_max<<endl;
                   if(c_max>0){
                       c_max=1;
                       g_max=max(g_max,i-c_start+1);
                   }else c_max=-1;
                   if(p>0){
                       p=1;
                       g_max=max(g_max,i-start+1);
                   }else p=-1;
                   if(c_max<0 and p<0){
                       c_max=1;
                       c_start=i+1;
                   }
               }
           }
           return g_max;
        }
};

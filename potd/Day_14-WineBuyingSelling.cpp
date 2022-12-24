/*
Given an array, Arr[] of size N represents N house built along a straight line with equal distance between adjacent houses. Each house has a certain number of wine and they want to buy/sell those wines to other houses. Transporting one bottle of wine from one house to an adjacent house results in one unit of work. The task is to find the minimum number of work is required to fulfill all the demands of those N houses.

if arr[i] < 0, then ith house wants to sell arr[i] number of a wine bottle to other houses.
if arr[i] > 0, then ith house wants to buy arr[i] number of a wine bottle from other houses.
Note: One have to print the minimum number such that, all the house can buy/sell wine to each other.
It is guaranteed that sum of all the elements of the array will be 0.

Example 1:

Input: N = 5, Arr[] = {5, -4, 1, -3, 1}
Output: 9
Explanation: 
1th house can sell 4 wine bottles to 0th house,
total work needed 4*(1-0) = 4, new arr[] = 1,0,1,-3,1
now 3rd house can sell wine to 0th, 2th and 4th.
so total work needed = 1*(3-0)+1*(3-2)+1*(4-3) = 5
So total work will be 4+5 = 9
*/

class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int N){
    //Long Solution.
    // int res=0;
    //   vector< pair <int,int> > pos;
    //   for(int i=0;i<N;i++)
    //   { 
    //       if(arr[i]>0)  pos.push_back(make_pair(arr[i],i));
    //   }
      
    //   for(int i=0;i<N;i++){
    //       while(arr[i]<0){
    //           for(int j=0;j<pos.size() and arr[i]!=0;j++){
    //             int temp=-1*arr[i];
    //             res=res+(min(temp,pos[j].first)*abs(i-pos[j].second));
    //             arr[i]=arr[i]+min(temp,pos[j].first);
    //             pos[j].first=pos[j].first-min(temp,pos[j].first);
    //           }
    //       }
    //   }
      long int res = 0;
      long int sum = 0;
      for(int i = 0; i < N; i++){
          res+=abs(sum);
          sum+=arr[i];
          cout<<res<<" "<<sum<<endl;
      }
     return res;
  }
};

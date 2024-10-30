class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int count=0;
        unordered_map<int,int> s;
        s.insert({arr[0],1});
        for(int i=1;i<n;i++){
            int diff = arr[i]-k;
            int diff2 = arr[i]+k;
            if(s.find(diff) != s.end()){
                count+=s[diff];
            }
            if(s.find(diff2) != s.end()){
                count+=s[diff2];
            }
            if(s.find(arr[i]) != s.end()){
                s[arr[i]]+=1;
            }
            else {
                s.insert({arr[i],1});
            }
            
        }
        return count;
    }
};

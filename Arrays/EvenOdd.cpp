/*
Logic explained : 
odd + odd = even
even + even = even
odd + even = even + odd = even
Just count odd and even numbers and get your answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long> evenOdd(int N, vector<int> arr) {
        // code here
        long long even=0;
        long long odd=0;
        for(int i=0;i<N;i++){
            if(arr[i]%2==0) even++;
            else odd++;
        }
        long long same_odd_pair = (odd * (odd - 1))/2;
        long long same_even_pair = (even * (even - 1))/2;
        long long combination = even * odd;
        return {same_odd_pair + same_even_pair, combination};
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        vector<long long> ans = ob.evenOdd(N, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

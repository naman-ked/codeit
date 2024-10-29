class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        int l = 0;
        int r = 0;
        int bucket = 0;
        for(int i=0; i<n; i++){
            r = i;
            bucket += arr[i];
            if(bucket == target){
                return {l+1 , r+1};
            }
            else if(bucket > target){
                while(bucket > target and l<=r){
                    bucket -= arr[l];
                    l++;
                } 
                if(bucket == target){
                    return {l+1 , r+1};
                }
            }
        }
        return {-1};
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        for (int num : arr) {
        pq.push(num);
        // If the size of the heap exceeds k, pop the largest element
        if (pq.size() > k) {
            pq.pop();
        }
    }

    // The top of the heap is the k-th smallest element
    return pq.top();
    }
};

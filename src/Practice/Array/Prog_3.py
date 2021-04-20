# Kadans's Algorithm
# O(n) time | O(1) space
class Solution:
    arr=[1,-3,2,4,9,-5,19,-2]
    def maxSum(arr):
        maxSoFar=arr[0]
        maxEndingHere=arr[0]
        for num in arr[1:]:
            maxEndingHere=max(maxEndingHere+num,num)
            maxSoFar=max(maxEndingHere, maxSoFar)
        print(maxSoFar)
    maxSum(arr)

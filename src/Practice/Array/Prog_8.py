# Minimize the Heights II 
# O(n) time | O(1) space
class Solution:
    arr=[3, 9, 12, 16, 20]
    def getMinDiff(arr,n,k):
        minimum_height=min(arr)+k
        maximum_height=max(arr)
        if(maximum_height-k>0):maximum_height-=k
        else : maximum_height+=k
        result=maximum_height-minimum_height
        
    getMinDiff(arr,5,3)


    Input:
5
10
2 6 3 4 7 2 10 3 2 1

Its Correct output is:
7

And Your Code's output is:
-1
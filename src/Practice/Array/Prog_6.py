#Find the Duplicate Number
#Solution 1:
#O(nlogn) Time | O(1) Space 
# class Solution:
#     def findDuplicate(a):
#         a.sort()
#         n=len(a)
#         for i in range(0,n):
#             if(a[i]==a[i+1] and i<n):
#                 print(a[i])
#     a=[2,2,2,2,2]
#     findDuplicate(a)
#Solution 2:

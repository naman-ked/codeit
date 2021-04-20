# Maximum and Minimum in an array

#Method 1 - Linear search
# O(n) time | O(1) space
# No. of comparison = 1+2(n-1)
# class Solution:
#     arr=[1,-3,2,4,9,-5,19,-2]
#     def check(a):
#            large=a[0]
#            small=a[0]
#            for i in range(1,len(a)):
#                if(a[i]>large):
#                    large=a[i]
#                elif(a[i]<small):
#                    small=a[i]
#            print(large,small)
#     check(arr)

#Method 2 - Check in pairs
# O(n) time | O(1) space
# No. of comparison = 1+3(n-1)/2
class Solution:
    arr=[1,-3,2,4,9,-5,19,-2,7,5,6,8,1,2,3,8,-100]
    def check(a):
           n=len(a)
           l=0
           if(n%2==0):
               large=max(a[0],a[1])
               small=min(a[0],a[1])
               l=2
           else:
               large=a[0]
               small=a[0]
               l=1;               
           for i in range(l,n,2):
               if(a[i]>a[i+1]):
                   large=max(large,a[i])
                   small=min(small,a[i+1])
               else:
                   large=max(large,a[i+1])
                   small=min(small,a[i])
           print(large,small)
    check(arr)



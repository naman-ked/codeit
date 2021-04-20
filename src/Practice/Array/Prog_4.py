#Cyclically Rotate Array by one
#O(n) Time | O(1) Space 
class Solution:
    arr=[1,12,34,23,2,233,34,345]
    def rotate(arr):
        length=0
        for number in arr:
          length+=1
        t=arr[-1]
        for i in range(length-1,0,-1):
            arr[i]=arr[i-1]
        arr[0]=t
        print(arr)
    rotate(arr)

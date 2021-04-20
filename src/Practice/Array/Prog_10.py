# Move negative to front and posiive to end . Order not important
# O(n) time | O(1) space
class Solution:
    arr=[1,-3,2,4,9,-5,19,-2,-9,-10,-100,90,80,-1987]
    def shift(arr):
        front=0
        end=len(arr)-1
        while(front < end):
            if(arr[front]<0 and arr[end]<0):front+=1
            elif(arr[front]>0 and arr[end]>0):end-=1
            elif(arr[front]>0 and arr[end]<0):
                arr[front],arr[end]=arr[end],arr[front]
                front+=1
                end-=1
            else:
                front+=1
                end-=1
        print(arr)
    shift(arr)

# If order has to be maintained 
#  if u find any negative shift all postive infront of it to one step back and insert negative infront
#  of them all. This would take O(n^2) and O(1) space.

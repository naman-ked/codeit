# Merge without Extra Space
# O(n+m) in time O(1) in space
class Solution:
    a=[1, 3, 5, 7]
    b=[0, 2, 6, 8, 9] 
    n=0
    for number in a:
      n+=1  
    m=0
    for number in b:
      m+=1 
    count=0
    def merge(a,b,n,m):
        i=0,j=0
        while(i<n and j<m):
            if(a[i]<b[j]):
                i+=1
            elif(a[i]>b[j]):
                swap(a[i],b[j])
                      

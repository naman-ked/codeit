#Union of two Arrays
#O(n+m) Time | O(n+m) space 
class Solution:
    a=[1,2,3,4,5]
    b=[1,2,3]
    a.sort() 
    b.sort()
    def doUnion(a,n,b,m):
         unique_list_1 = []
         for x in a:# traverse for all elements
            if x not in unique_list_1:# check if exists in unique_list or not
              unique_list_1.append(x)

         unique_list_2 = []
         for x in b:
            if x not in unique_list_2:
              unique_list_2.append(x)
              
         count=0
         n=len(unique_list_1)
         m=len(unique_list_2)
         i=0
         j=0
         while( i < n and j < m):
              if(unique_list_1[i]==unique_list_2[j]):    
                  i+=1
                  j+=1
                  #count+=1 for interscetion
              elif(unique_list_1[i]<unique_list_2[j]):
                  i+=1 
              else:
                  j+=1   
              count+=1
         print(count+n-i+m-j)  #print(count) for intersection     
    doUnion(a,0,b,0)


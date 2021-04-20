#Trapping Rain Water Problem
#O(n) Time | O(n) Space n-length of heights
class Solution:
    heights=[3,0,0,2,0,4]
    def trappingWater(heights):
        leftmax=0
        maxes=[0 for x in heights]
        for i in range(len(heights)):
            maxes[i]=leftmax
            leftmax=max(heights[i],leftmax)    
        rightmax=0
        for i in reversed(range(len(heights))):
            maxes[i]=min(maxes[i],rightmax)
            if heights[i] < maxes[i]:
                maxes[i]=maxes[i]-heights[i]
            else:
                maxes[i]=0    
            rightmax=max(heights[i],rightmax) 
        return sum(maxes)                   
    print(trappingWater(heights))        

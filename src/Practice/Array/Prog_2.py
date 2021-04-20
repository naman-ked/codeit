# Min Number of Jumps
# O(n) Time | O(1) space
class Solution:
    arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
    n=11
    def minJumps(arr,n):
        if (n <= 1):
            return 0
        if (arr[0] == 0):
            return -1
        steps = arr[0]
        jumps = 0
        maxReach = arr[0]
        for i in range(1, n-1):
            maxReach = max(maxReach, arr[i]+i)
            steps = steps - 1
            if steps == 0:
                if(i >= maxReach):
                    return -1
                jumps = jumps+1
                steps = maxReach-i
        return jumps+1
    print(minJumps(arr,n))

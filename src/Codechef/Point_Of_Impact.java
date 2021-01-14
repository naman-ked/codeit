/*
You are playing a Billiards-like game on an N×N table, which has its four corners at the points {(0,0),(0,N),(N,0), and (N,N)}. You start from a coordinate (x,y), (0<x<N,0<y<N) and shoot the ball at an angle 45∘ with the horizontal. On hitting the sides, the ball continues to move with the same velocity and ensuring that the angle of incidence is equal to the angle of reflection with the normal, i.e, it is reflected with zero frictional loss. On hitting either of the four corners, the ball stops there and doesn’t move any further.

Find the coordinates of the point of collision, when the ball hits the sides for the Kth time. If the ball stops before hitting the sides K times, find the coordinates of the corner point where the ball stopped instead.

Input:
The first line of the input contains an integer T, the number of testcases.
Each testcase contains a single line of input, which has four space separated integers - N, K, x, y, denoting the size of the board, the number of collisions to report the answer for, and the starting coordinates.
Output:
For each testcase, print the coordinates of the ball when it hits the sides for the Kth time, or the coordinates of the corner point if it stopped earlier.

Constraints
1≤T≤105
2≤N≤109
1≤K≤109
Subtasks
30 points : Sum of K over all test cases ≤107
70 points : Original constraints.
Sample Input:
2
5 5 4 4
5 2 3 1
Sample Output:
5 5
3 5
 */


package Codechef;

import java.util.Scanner;

public class Point_Of_Impact {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
           while (t > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            int c;
            int p1x,p2x,p3x,p4x;
            int p1y,p2y,p3y,p4y;
               k=k%4;
            if(x>y) {
                   p1x=x-y;
                   p1y=0;
                   p2x=n;
                   p2y=n-x+y;
                   p3x=n-x+y;
                   p3y=n;
                   p4x=0;
                   p4y=x-y;
                   if(k==0)System.out.println(p1x+" "+p1y);
                   if(k==1)System.out.println(p2x+" "+p2y);
                   if(k==2)System.out.println(p3x+" "+p3y);
                   if(k==3)System.out.println(p4x+" "+p4y);
               }
            else if(x<y) {
                p1x = 0;
                p1y = y - x;
                p2x = n - y + x;
                p2y = n;
                p3x = n;
                p3y = n - y + x;
                p4x = y - x;
                p4y = 0;
                if(k==0)System.out.println(p1x+" "+p1y);
                if(k==1)System.out.println(p2x+" "+p2y);
                if(k==2)System.out.println(p3x+" "+p3y);
                if(k==3)System.out.println(p4x+" "+p4y);
            }
            else System.out.println(n+" "+n);
            t = t - 1;
        }
    }
}

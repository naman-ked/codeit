/*
ree types of apartments: three-room, five-room, and seven-room apartments. It's also known that each room of each apartment has exactly one window. In other words, a three-room apartment has three windows, a five-room — five windows, and a seven-room — seven windows.

Monocarp went around the building and counted n windows. Now he is wondering, how many apartments of each type the building may have.

Unfortunately, Monocarp only recently has learned to count, so he is asking you to help him to calculate the possible quantities of three-room, five-room, and seven-room apartments in the building that has n windows. If there are multiple answers, you can print any of them.

Here are some examples:

if Monocarp has counted 30 windows, there could have been 2 three-room apartments, 2 five-room apartments and 2 seven-room apartments, since 2⋅3+2⋅5+2⋅7=30;
if Monocarp has counted 67 windows, there could have been 7 three-room apartments, 5 five-room apartments and 3 seven-room apartments, since 7⋅3+5⋅5+3⋅7=67;
if Monocarp has counted 4 windows, he should have mistaken since no building with the aforementioned layout can have 4 windows.
Input
Th first line contains one integer t (1≤t≤1000) — the number of test cases.

The only line of each test case contains one integer n (1≤n≤1000) — the number of windows in the building.

Output
For each test case, if a building with the new layout and the given number of windows just can't exist, print −1.

Otherwise, print three non-negative integers — the possible number of three-room, five-room, and seven-room apartments. If there are multiple answers, print any of them.

Example
inputCopy
4
30
67
4
14
outputCopy
2 2 2
7 5 3
-1
0 0 2
 */


package Codeforces;

import java.util.Scanner;

public class Number_of_Apartments {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            int a, b, c;
            a = n / 7;
            b = n % 7;
            if(n==11)System.out.println(2 + " " + 1 + " " + 0);
            else if(n==8) System.out.println(1 + " " + 1 + " " + 0);
            else if (n==13) System.out.println(1 + " " + 2 + " " + 0);
            else if (b == 0) System.out.println(0 + " " + 0 + " " + a);
            else if (a > 2) {
                if (b == 3 || b == 6) System.out.println(b/3 + " " + 0 + " " + a);
                if (b == 5) System.out.println(0 + " " + 1 + " " + a);
                if (b == 1) System.out.println(0 + " " + 3 + " " + (a - 2));
                if (b == 2) System.out.println(3 + " " + 0 + " " + (a - 1));
                if (b == 4) System.out.println(6 + " " + 0 + " " + (a - 2));
            } else {
                a = n / 5;
                b = n % 5;
                if (b == 0) System.out.println(0 + " " + a + " " + 0);
                else if (a > 2) {
                    if (b == 1) System.out.println(2 + " " + (a - 1) + " " + 0);
                    if (b == 2) System.out.println(0 + " " + (a - 1) + " " + 1);
                    if (b == 4) System.out.println(3 + " " + (a - 1) + " " + 0);
                    if (b == 3) System.out.println(1 + " " + a + " " + 0);
                } else {
                    a = n / 3;
                    b = n % 3;
                    if (b == 1 || b == 2) System.out.println(-1);
                    else if (b == 0) System.out.println(a + " " + 0 + " " + 0);
                }
            }
            t = t - 1;
        }
    }
}
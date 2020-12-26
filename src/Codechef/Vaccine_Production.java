/*
Increasing COVID cases have created panic amongst the people of Chefland, so the government is starting to push for production of a vaccine. It has to report to the media about the exact date when vaccines will be available.

There are two companies which are producing vaccines for COVID. Company A starts producing vaccines on day D1 and it can produce V1 vaccines per day. Company B starts producing vaccines on day D2 and it can produce V2 vaccines per day. Currently, we are on day 1.

We need a total of P vaccines. How many days are required to produce enough vaccines? Formally, find the smallest integer d such that we have enough vaccines at the end of the day d.

Input
The first and only line of the input contains five space-separated integers D1, V1, D2, V2 and P.
Output
Print a single line containing one integer ― the smallest required number of days.

Constraints
1≤D1,V1,D2,V2≤100
1≤P≤1,000
Subtasks
Subtask #1 (30 points): D1=D2=1
Subtask #2 (70 points): original constraints

Example Input 1
1 2 1 3 14
Example Output 1
3
 */

package Codechef;

import java.util.Scanner;

public class Vaccine_Production {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d1 = sc.nextInt();
        int v1 = sc.nextInt();
        int d2 = sc.nextInt();
        int v2 = sc.nextInt();
        int p = sc.nextInt();
        int current=0;
        int d=0;
        while(current<p){
            d++;
            if(d>=d1)
                current+=v1;
            if(d>=d2)
                current+=v2;
        }
        System.out.println(d);
}
}

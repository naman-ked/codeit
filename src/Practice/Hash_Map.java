/*
Intro to hash map
 */
package Practice;

import java.util.HashMap;
//Hash Map data structure
public class Hash_Map {
    public static void main(String[] args) {
       int a=10;
       int b=3;
       int c=30;
       //taking integer
        HashMap<String,Integer> happy= new HashMap<>();
        happy.put("a",10 );
        happy.put("b", 3);
        happy.put("c", 30);
        happy.remove("a");
        System.out.println(happy);
        System.out.println(happy.get("c"));
        System.out.println(happy.containsValue(30));
    }
}

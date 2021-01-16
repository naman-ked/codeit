package Practice;



import java.util.*;
import java.util.Stack;

public class ValidParentheses {
    public static void main(String[] args) {
        Stack<Character> a = new Stack<>();
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int l = str.length();
        for(int i=0;i<l;i++) {
            char x = str.charAt(i);
            if (x == '(' || x == '[' || x == '{') a.push(x);
            else if(a.isEmpty()){
                System.out.println("false");
                break;
            }
            else {
                System.out.println("2");
                char y;
                y = a.pop();
                if ( ((x == ']' || x == '}') && y == '(') || ((x == ']' || x == ')') && y == '{') || ((x == '}' || x == ')') && y == '[')) {
                    System.out.println("false");
                    break;
                }
            }
        }
        if(a.isEmpty())System.out.println("true");
    }
}

package Practice;

public class Sample_Stack {
    public static void main(String[] args) {
        String str="asdfghjkl";
        Stack one = new Stack(str.length());

        for(int i=0;i<str.length();i++){
            one.push(str.charAt(i));
        }
        System.out.print(one.peak());
        while(one.pop()!=' '){
            System.out.print  (one.peak());
        }

    }
}

package Practice;

import java.util.Arrays;
import java.util.Scanner;

public class Stack {

    private int top;
    private int maxSize;
    private char a[];

    public Stack(int size){
      this.maxSize = size;
      this.a = new char[maxSize];
      this.top=-1;
    }

    public void push(char j)
    {
        top++;
        a[top]=j;
    }

    public char pop(){
        if(top!=0) {
            int oldtop = top;
            top--;
            return a[oldtop];
        }
        else return ' ';
    }

    public char peak(){
        return  a[top];
    }

}

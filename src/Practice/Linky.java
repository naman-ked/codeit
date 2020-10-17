package Practice;

import java.util.Iterator;
import java.util.LinkedList;

public class Linky {
    public static void main(String[] args) {
        LinkedList<String> linky = new LinkedList<>();
        linky.add("Rob");
        linky.add("Alex");
        linky.add("Jose");
        System.out.println(linky.getFirst());
        System.out.println(linky);

        Iterator<String> it = linky.iterator();
        while(it.hasNext()){
            if(it.next().equals("Alex")){
                System.out.println("We found Alex who teaches java on utube");
            }
        }
    }
}

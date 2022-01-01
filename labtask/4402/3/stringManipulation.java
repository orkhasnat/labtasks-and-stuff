import java.util.*;

public class stringManipulation {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        String st = inp.nextLine();
        // stringManipulation pp = new stringManipulation();
        // ssstar(st);
        String s2 = new String();
        for (int i = 1; i <= st.length(); i++) {
            s2 += st.charAt(i - 1);
            if (i % 2 == 0)
                s2 += "*";
        }
        System.out.println(s2);
        inp.close();
    }

    // private static void ssstar(String s) {
    //     String st = new String();
    //     // stringManipulation pp = new stringManipulation();
    //     for (int i = 1; i < s.length(); i++) {
    //         changeStr(st, s.substring(i - 1, i - 1));
    //         // st[i - 1] = s.charAt(i - 1);
    //         System.out.println(st);
    //         if (i % 2 == 0)
    //             changeStr(st, "*");
    //     }
    //     System.out.println(st);
    // }

    // private static String changeStr(String ss, String c) {
    //     return ss + c;
    // }
}
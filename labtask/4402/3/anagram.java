import java.util.*;

public class anagram {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        String s1 = inp.nextLine();
        String s2 = inp.nextLine();
        // System.out.println(SortString(s1)+"\n"+SortString(s2));
        if (SortString(s1).equals(SortString(s2)))
            System.out.println("Given strings are anagram to each other");
        else
            System.out.println("Given strings are NOT anagram to each other");

        inp.close();
    }

    private static String SortString(String s) {
        char temp[] = s.toLowerCase().toCharArray();
        Arrays.sort(temp);
        return new String(temp);
    }

}
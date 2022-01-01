import java.util.*;

public class palindrome {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        String st = inp.nextLine();
        palindrome pp = new palindrome();
        if (pp.ifPalindrome(st))
            System.out.println("It is a palindrome");
        else
            System.out.println("It is not a palindrome");

        inp.close();
    }

    public Boolean ifPalindrome(String s) {
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!= s.charAt(s.length()-i-1))
                return false;
        }
        return true;
    }
}

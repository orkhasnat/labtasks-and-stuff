// my 2nd java program ever!!!
import java.util.Scanner;

public class ImBoredWithLife {

    public static void main(String args[]) {
        int a ,b, t;
        // input
        Scanner input = new Scanner(System.in);
        a= input.nextInt();
        b=input.nextInt();
        input.close();
        if (a < b) {
            t = b;
            b = a;
            a = t;
        }
        // a = factorial(b);
        System.out.println(factorial(b));
    }

    private static int factorial(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else if (n == 3)
            return 6;
        else {
            return n * factorial(n - 1);
        }
    }
}

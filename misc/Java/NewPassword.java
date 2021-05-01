import java.util.Scanner;

public class NewPassword {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int k = input.nextInt();
        while (n > 0) {
            for (int i = 0; i < k; i++) {
                System.out.printf("%c", 97 + i);
                n--;
                if (n == 0)
                    break;
            }
        }
        input.close();
    }
}
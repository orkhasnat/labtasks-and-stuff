//if x or y or m gets close to 10^18 it fails (TLE) :(


import java.util.Scanner;

public class PerfecrPair {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long x = input.nextLong();
        long y = input.nextLong();
        long m = input.nextLong();
        System.out.println(mPerfect(x, y, m));
        input.close();
    }

    private static int mPerfect(long x, long y, long m) {
        if (x >= m || y >= m)
            return 0;
        if (x <= 0 && y <= 0)
            return -1;
        int count = 0;
        if (x < 0) {
            count = (int) (Math.abs(x) / y);
            x += count * y;
        }
        else if (y < 0) {
			count = (int) (Math.abs(y) / x);
			y += count * x;
		}
        while (x < m && y < m) {
            if (x < y)
                x += y;
            else
                y += x;
            count++;
        }
        return count;
    }
}

// its very annoying to work with strings in java as for now
// for some obscure reason a String object is not iterable wth!!!
// cant use \0 with strings ,have to forget all tactics from cpp
// strings may or maynot be terminated by \0 but charAt() cannot get \0
// only way is using length() or maybe change the string to a charArray
//doesnt even have append WTAF!!! have to use stringbuffer or stringbuilder or something like that 
import java.util.Scanner;

public class HelpfulMaths {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String path = input.next();
        int one = 0, two = 0, three = 0, j = 0;
        for (int i = 0; i < path.length(); i++) {
            if (path.charAt(i) == '1')
                one++;
            else if (path.charAt(i) == '2')
                two++;
            else if (path.charAt(i) == '3')
                three++;
        }
        char[] newPath = new char[path.length()+1];
        for (int i = 0; i < one; i++, j++) {
            newPath[j] = '1';
            j++;
            newPath[j] = '+';
        }
        for (int i = 0; i < two; i++, j++) {
            newPath[j] = '2';
            j++;
            newPath[j] = '+';
        }
        for (int i = 0; i < three; i++, j++) {
            newPath[j] = '3';
            j++;
            newPath[j] = '+';
        }

        for (int i=0;i<j-1;i++) System.out.print(newPath[i]);
        input.close();
    }
}
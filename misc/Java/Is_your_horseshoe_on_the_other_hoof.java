//
// Need to learn more about  Set<String> set = new HashSet<String>(Arrays.asList(in.split(" ")));
// this entire line
//
import java.util.*;
public class Is_your_horseshoe_on_the_other_hoof {
    public static void main(String[] args) {
        Scanner input= new Scanner(System.in);
        String in = input.nextLine();
        Set<String> set = new HashSet<String>(Arrays.asList(in.split(" ")));
        int ans= 4- set.size();
        System.out.println(ans);
        input.close();
    }
}
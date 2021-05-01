//didnt work 
//copied and reformed in java from codeforces tutorials
//code in cpp given below 
import java.util.Scanner;
import java.util.ArrayList;

public class CrosswordSolving {
    public static void main(String args[]) {
        int p, q;
        Scanner input = new Scanner(System.in);
        p = input.nextInt();
        q = input.nextInt();
        String s, t;
        s = input.next();
        t = input.next();
        ArrayList<Integer> ans = new ArrayList<Integer>();
        ArrayList<Integer> newAns = new ArrayList<Integer>();
        for (int i = 0; i < p; i++) {
            ans.add(i);
        }
        for (int i = 0; i < q - p + 1; i++) {
            newAns.clear();
            for (int j = 0; j < p; j++) {
                if (s.charAt(j) != t.charAt(i + j))
                    newAns.add(j);
            }
                if (newAns.size() < ans.size())
                    ans = newAns;
            
        }
        int size = ans.size();
        System.out.println(size);
        for (int k = 0; k < size; k++) {
            // int c = (ans.get(k).intValue()) + 1;
            System.out.printf("%d ", (ans.get(k).intValue()) + 1);
        }
        input.close();
    }
}


// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     //const int maxn = 1050;

//     vector<int> ans;
//     vector<int> newAns;
//     int n, m;
//     scanf("%d%d\n", &n, &m);
//     char t1[n + 1];
//     char t2[m + 1];
//     gets(t1);
//     gets(t2);

//     for (int j = 0; j < n; j++)
//         ans.push_back(j);

//     for (int j = 0; j < m - n + 1; j++)
//     {
//         newAns.clear();
//         for (int i = 0; i < n; i++)
//             if (t1[i] != t2[i + j])
//                 newAns.push_back(i);
//         if (newAns.size() < ans.size())
//             ans = newAns;
//     }
//     int sz = ans.size();
//     printf("%d\n", sz);
//     for (int j = 0; j < sz; j++)
//         printf("%d ", ans[j] + 1);

//     return 0;
// }
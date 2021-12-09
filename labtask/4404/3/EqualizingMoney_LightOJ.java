import java.io.*;
import java.util.*;

public class EqualizingMoney_LightOJ {
  static int N = 1005;
  static int[] bal = new int[N];
  static boolean[] vis = new boolean[N];
  static int sz, tot;
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader input = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    int T = input.nextInt();
    for (int t = 1; t <= T; ++t) {
      int n = input.nextInt();
      int m = input.nextInt();
      int need = 0;
      for (int i = 1; i <= n; ++i) {
        bal[i] = input.nextInt();
        vis[i] = false;
        need += bal[i];
      }
      Graph G = new Graph(n);
      for (int i = 0; i < m; ++i) {
        int u = input.nextInt();
        int v = input.nextInt();
        G.add(u, v);
      }
      System.out.printf("Case %d: ", t);
      if (need % n != 0) {
        System.out.println("No");
      } else {
        need /= n;
        boolean ye = true;
        for (int i = 1; i <= n; ++i) {
          if (!vis[i]) {
            sz = 0; tot = 0;
            G.dfs(i);
            if (tot % sz != 0) {
              ye = false;
              break;
            } else {
              if (need != tot / sz) {
                ye = false;
                break;
              }
            }
          }
        }
        System.out.println(ye ? "Yes" : "No");
        System.gc();
      }
    }
  }
  static class Graph {
    private final int n;
    private final LinkedList<Integer>[] adj;
    public Graph(int _n) {
      n = _n + 2;
      adj = new LinkedList[n];
      for (int i = 0; i < n; ++i) {
        adj[i] = new LinkedList<>();
      }
    }
    void add(int u, int v) {
      adj[u].add(v);
      adj[v].add(u);
    }
    void dfs(int v) {
      ++sz;
      tot += bal[v];
      vis[v] = true;
      for (int u : adj[v]) {
        if (!vis[u]) {
          dfs(u);
        }
      }
    }
  }
  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

  }
}


import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static long[] dp;

    private static long fib(int n) {
        if (dp[n] != -1) {
            return dp[n];
        } else {
            return dp[n] = fib(n - 1) + fib(n - 2);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        dp = new long[N + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        dp[1] = 1;
        System.out.print(fib(N));
        br.close();
        bw.flush();
        bw.close();
    }
}

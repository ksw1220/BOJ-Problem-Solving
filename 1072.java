import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static long X, Y, Z;
    static long l, r, answer;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        X = Long.parseLong(st.nextToken());
        Y = Long.parseLong(st.nextToken());
        answer = X;
        Z = Y * 100 / X;

        if (Z >= 99) {
            System.out.println(-1);
        } else {
            l = 0;
            r = X;

            while (l <= r) {
                long mid = (l + r) / 2;
                long rate = (Y + mid) * 100 / (X + mid);
                if (rate != Z) {
                    answer = answer < mid ? answer : mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            System.out.println(answer);
        }
        br.close();
    }
}

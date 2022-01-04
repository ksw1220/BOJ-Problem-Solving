
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, S;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        arr = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int l = 0;
        int r = 0;
        int sum = arr[0];
        int answer = N + 1;
        while (r < N) {
            if (sum >= S) {
                answer = answer < (r - l + 1) ? answer : r - l + 1;
                sum -= arr[l++];
            } else {
                sum += arr[++r];
            }
        }
        if (answer == N + 1) {
            System.out.println(0);
        } else {
            System.out.print(answer);
        }
        br.close();
    }
}

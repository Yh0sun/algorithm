import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class RotateArr1 {
    static int N, M, R;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        int minVal = Math.min(N, M);

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < minVal / 2; i++) {
            rotate(i);
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                sb.append(arr[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }

    public static void rotate(int num) {
        Queue<Integer> que = new LinkedList<>();

        for (int i = num; i < M - num - 1; i++) que.add(arr[num][i]);
        for (int i = num; i < N - num - 1; i++) que.add(arr[i][M - num - 1]);
        for (int i = M - num - 1; i > num; i--) que.add(arr[N - num - 1][i]);
        for (int i = N - num - 1; i > num; i--) que.add(arr[i][num]);

        for (int i = 0; i < R; i++) que.add(que.poll());

        for (int i = num; i < M - num - 1; i++) arr[num][i] = que.poll();
        for (int i = num; i < N - num - 1; i++) arr[i][M - num - 1] = que.poll();
        for (int i = M - num - 1; i > num; i--) arr[N - num - 1][i] = que.poll();
        for (int i = N - num - 1; i > num; i--) arr[i][num] = que.poll();
    }
}

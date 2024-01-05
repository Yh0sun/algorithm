
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Tetromino {
    public static final int[] dx = {0, 1, 0, -1};
    public static final int[] dy = {1, 0, -1, 0};
    static int maxSum = -1;
    static int[][] table;
    static int[][] visited;
    static int h = 0, w = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        h = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        table = new int[h][w];
        visited = new int[h][w];

        for (int i = 0; i < h; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < w; j++) {
              table[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                Dfs(i, j, 0, 0);
                if (i != 0 && j > 0 && j < (w - 1))
                    maxSum = Math.max(maxSum, table[i][j] + table[i - 1][j - 1] + table[i - 1][j] + table[i - 1][j + 1]);
                if (i != (h - 1) && j > 0 && j < (w - 1))
                    maxSum = Math.max(maxSum, table[i][j] + table[i + 1][j - 1] + table[i + 1][j] + table[i + 1][j + 1]);
                if (j != 0 && i > 0 && i < (h - 1))
                    maxSum = Math.max(maxSum, table[i][j] + table[i - 1][j - 1] + table[i][j - 1] + table[i + 1][j - 1]);
                if (j != (w - 1) && i > 0 && i < (h - 1))
                    maxSum = Math.max(maxSum, table[i][j] + table[i - 1][j + 1] + table[i][j + 1] + table[i + 1][j + 1]);
            }
        }
        System.out.println(maxSum);
    }

    public static void Dfs(int x, int y, int sum, int cnt) {
        visited[x][y] = 1;
        sum += table[x][y];
        cnt++;
        if (cnt == 4) {
            maxSum = Math.max(maxSum, sum);
            visited[x][y] = 0;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 > nx || nx >= h || 0 > ny || ny >= w) continue;
            if (visited[nx][ny] == 1) continue;
            Dfs(nx, ny, sum, cnt);
        }
        visited[x][y] = 0;
    }
}
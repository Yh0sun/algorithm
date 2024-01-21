import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class SafeZone {
    final int[] dx = {0, 1, 0, -1};
    final int[] dy = {1, 0, -1, 0};
    int N, maxH = -1, waterHeight = 1;
    ArrayList<ArrayList<Integer>> map = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        SafeZone safeZone = new SafeZone();
        safeZone.input();
        System.out.println(safeZone.solution());
    }

    public void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                row.add(Integer.parseInt(st.nextToken()));
                maxH = Math.max(row.get(j), maxH);
            }
            map.add(row);
        }
    }

    public int solution() throws IOException {
        int ans = 1;

        while (waterHeight < maxH) {
            ans = Math.max(safeZoneCnt(), ans);
            waterHeight++;
        }
        return ans;
    }

    public int safeZoneCnt() {
        int safeZoneNum = 0;
        boolean[][] visited = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map.get(i).get(j) <= waterHeight) continue;
                if (visited[i][j]) continue;
                bfs(visited, i, j);
                safeZoneNum++;
            }
        }
        return safeZoneNum;

    }


    public void bfs(boolean[][] visited, int x, int y) {
        Queue<Pos> que = new LinkedList<>();
        que.add(new Pos(x, y));
        visited[x][y] = true;

        while (!que.isEmpty()) {
            Pos curr = que.poll();

            for (int i = 0; i < 4; i++) {
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (map.get(nx).get(ny) <= waterHeight) continue;
                if (visited[nx][ny]) continue;
                que.add(new Pos(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}
class Pos {
    int x;
    int y;

    Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

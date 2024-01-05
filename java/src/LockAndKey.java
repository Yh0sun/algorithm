import java.util.LinkedList;
import java.util.Queue;

public class LockAndKey {
    public static void main(String[] args) {

    }
    static int[][] tempKey;
    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = true;
        int grooveMinX = 100, grooveMaxX = -1;
        int grooveMinY = 100, grooveMaxY = -1;

        for (int i = 0; i < lock.length; i++) {
            for (int j = 0; j < lock[i].length; j++) {
                if (lock[i][j] == 0) {
                    grooveMinX = Math.min(grooveMinX, i);
                    grooveMaxX = Math.max(grooveMaxX, i);
                    grooveMinY = Math.min(grooveMinY, j);
                    grooveMaxY = Math.max(grooveMaxY, j);
                }
            }
        }

        if (grooveMaxX - grooveMinX + 1 > key.length || grooveMaxY - grooveMinY + 1 > key.length) return false;

        int[][] startSpot = {
                {grooveMinX, grooveMinY},
                {grooveMinX, grooveMaxY - key.length},
                {grooveMaxX - key.length, grooveMinY},
                {grooveMaxX - key.length, grooveMaxY - key.length}
        };

        tempKey = key.clone();

        for (int r = 0; r < 4; r++) {
            rotate();

            for (int sx = startSpot[3][0]; sx <= startSpot[0][0]; sx++) {
                for (int sy = startSpot[3][1]; sy <= startSpot[0][1]; sy++) {
                    boolean flag = true;
                    for (int x = 0; x < key.length; x++) {
                        for (int y = 0; y < key.length; y++) {
                            int cx = sx + x;
                            int cy = sy + y;
                            if (cx < 0 || cx >= lock.length || cy < 0 || cy >= lock.length) continue;
                            if (lock[cx][cy] == key[x][y]) {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) break;
                    }
                    if (flag) return true;
                }
            }
        }
        return false;
    }
    public void rotate() {
        int N = tempKey.length / 2;
        Queue<Integer> que = new LinkedList<>();

        for (int n = 0; n < N; n++) {
            for (int i = n; i < tempKey.length - n - 1; i++) que.add(tempKey[n][i]);
            for (int i = n; i < N - n - 1; i++) que.add(tempKey[i][tempKey.length - n - 1]);
            for (int i = tempKey.length - n - 1; i > n; i--) que.add(tempKey[tempKey.length - n - 1][i]);
            for (int i = tempKey.length - n - 1; i > n; i--) que.add(tempKey[i][n]);

            for (int i = n; i < tempKey.length - n - 1; i++) que.add(que.poll());

            for (int i = n; i < tempKey.length - n - 1; i++) tempKey[n][i] = que.poll();
            for (int i = n; i < N - n - 1; i++) tempKey[i][tempKey.length - n - 1] = que.poll();
            for (int i = tempKey.length - n - 1; i > n; i--) tempKey[tempKey.length - n - 1][i] = que.poll();
            for (int i = tempKey.length - n - 1; i > n; i--) tempKey[i][n] = que.poll();
        }
    }
}

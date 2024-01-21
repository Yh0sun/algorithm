import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SlopeWay {
    static int N, L;
    static int ans;
    static int[][] table;

    public static void main(String[] args) throws IOException {
        input();

        for (int i = 0; i < N; i++) {
            int cnt = 1;
            boolean rightSlope = false;
            boolean isPossible = true;

            //가로줄 경사로 만들기
            for (int j = 1; j < N; j++) {
                int dif = table[i][j] - table[i][j - 1];

                if (rightSlope && cnt == L) {   //내려오는 경사로를 완성하면
                    cnt = 0;
                    rightSlope = false;
                }
                if (dif == 0) ++cnt;
                else if (rightSlope) {    //내려오는 경사로를 만들어야하는데 경사가 다르면
                    isPossible = false;
                    rightSlope = false;
                    break;
                }
                if (Math.abs(dif) > 1) {    //경사 차가 1 이상이면
                    isPossible = false;
                    break;
                }
                if (dif > 0) {        //전의 길보다 지금의 길이 높으면
                    if (cnt >= L) cnt = 1;
                    else {
                        isPossible = false;
                        break;
                    }
                }
                if (dif < 0) {    //전의 길보다 지금의 길이 낮으면
                    cnt = 1;
                    rightSlope = true;
                }
            }
            if (rightSlope && cnt < L) isPossible = false;
            if (isPossible) ans++;
        }
        //세로줄 경사로 만들기
        for (int i = 0; i < N; i++) {
            int cnt = 1;
            boolean downSlope = false;
            boolean isPossible = true;

            for (int j = 1; j < N; j++) {
                int dif = table[j][i] - table[j - 1][i];

                if (downSlope && cnt == L) {   //내려오는 경사로를 완성하면
                    cnt = 0;
                    downSlope = false;
                }
                if (dif == 0) ++cnt;
                else if (downSlope) {  //내려오는 경사로를 만들어야하는데 경사가 다르면
                    isPossible = false;
                    downSlope = false;
                    break;
                }
                if (Math.abs(dif) > 1) {    //경사 차가 1 이상이면
                    isPossible = false;
                    break;
                }
                if (dif > 0) {        //전의 길보다 지금의 길이 높으면
                    if (cnt >= L) cnt = 1;
                    else {
                        isPossible = false;
                        break;
                    }
                }
                if (dif < 0) {    //전의 길보다 지금의 길이 낮으면
                    cnt = 1;
                    downSlope = true;
                }
            }
            if (downSlope && cnt < L) isPossible = false;
            if (isPossible) ans++;
        }
        System.out.println(ans);
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        ans = 0;
        table = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                table[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }
}

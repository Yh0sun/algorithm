import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class MakeLine {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ArrayList<Line> lines = new ArrayList<Line>();
        int N = Integer.parseInt(st.nextToken());
        int totalLength = 0;

        for (int i = 0; i < N; i++) {
            Line line = new Line(br.readLine().split(" "));
            lines.add(line);
        }

        Collections.sort(lines);

        int startSpot = lines.get(0).start;
        int endSpot = lines.get(0).end;
        for (int i = 1; i < N; i++) {
            int s = lines.get(i).start;
            int e = lines.get(i).end;

            if (s <= endSpot) {
                if (endSpot < e) endSpot = e;
            } else {
                totalLength += endSpot - startSpot;
                startSpot = s;
                endSpot = e;
            }
        }
        totalLength += endSpot - startSpot;
        System.out.println(totalLength);
    }
}
class Line implements Comparable<Line>{
    int start;
    int end;
    Line(String[] s){
        this.start=Integer.parseInt(s[0]);
        this.end=Integer.parseInt(s[1]);
    }
    @Override
    public int compareTo(Line o) {
        if(this.start>o.start)return 1;
        else if(this.start<o.start) return -1;
        else return 0;
    }
}

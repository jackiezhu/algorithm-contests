import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by zezhu on 7/16/17.
 */
A
class Point {
    public long si, fi, di;
    Point(long si, long fi, long di) {
        this.si = si;
        this.fi = fi;
        this.di = di;
    }

    public long getNearestArrivalTime(long now) {
        long l = -1, h = Integer.MAX_VALUE;
        while(l + 1 < h) {
            long m = (l + h) / 2;
            if(this.si + this.fi * m >= now) {
                h = m;
            } else {
                l = m;
            }
        }

        return this.si + h * this.fi + this.di;
    }
}

public class Main {

    public static String solve(int N, long ts, long tf, List<Point> stops) {
        long dp[][] = new long[N][N+1];
        for(int i=0; i<N; i++) {
            for(int j=0; j<=N; j++) {
                dp[i][j] = Long.MAX_VALUE;
            }
        }

        long current = 0L;
        dp[0][0] = 0;
        for(int j = 1; j < N; j ++) {
            long nextArrival = stops.get(j-1).getNearestArrivalTime(current);
            dp[0][j] = nextArrival;
            current = nextArrival;
        }
        if(current > tf) {
            return "IMPOSSIBLE";
        }
        for(int i = 1; i <= N - 1; i ++) {
            for(int j = 1; j < N; j ++) {
                if(i > j) continue;
                dp[i][j] = Math.min(stops.get(j-1).getNearestArrivalTime(dp[i-1][j-1]+ts), stops.get(j-1).getNearestArrivalTime(dp[i][j-1]));
            }
        }

        long ans = 0;
        for(int i=0; i<N; i++) {
            if(dp[i][N-1] < Long.MAX_VALUE && dp[i][N-1] <= tf) {
                ans = i;
            }
        }

        return Long.toString(ans);
    }

    public static void main(String args[]) throws IOException {

            File file = new File("/Users/zezhu/Downloads/A-large-practice.in");
            Scanner in = new Scanner(file);
            while(in.hasNext()) {
                int T = in.nextInt();
                for(int cas = 1; cas <= T; cas ++) {
                    long N = in.nextLong(), ts = in.nextLong(), tf = in.nextLong();
                    List<Point> stops = new ArrayList<Point>();
                    for(int i = 0; i < N - 1; i++) {
                        long si = in.nextLong(), fi = in.nextLong(), di = in.nextLong();
                        stops.add(new Point(si, fi, di));
                    }
                    System.out.println(String.format("Case #%s: %s", cas, solve((int)N, ts, tf, stops)));
                }

            }
    }
}

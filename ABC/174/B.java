import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        long d = Long.parseLong(line[1]);
        d *= d;
        int ans = 0;
        for(int i = 0; i < n; i++){
            line = br.readLine().split(" ");
            long x = Long.parseLong(line[0]);
            long y = Long.parseLong(line[1]);
            ans += x*x+y*y <= d ? 1 : 0;
        }
        System.out.println(ans);
    }
}

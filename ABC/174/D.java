import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();
        int r = 0;
        for(int i = 0; i < n; i++){
            r += s.charAt(i)=='R' ? 1 : 0;
        }
        int x = 0;
        for(int i = 0; i < r; i++){
            x += s.charAt(i)=='R' ? 0 : 1;
        }
        System.out.println(Math.min(x, Math.min(r, n-r)));
    }
}

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(br.readLine());
        long ret = x/500*1000L + x%500/5*5;
        System.out.println(ret);
    }
}

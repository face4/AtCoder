import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int res = 0;
        for(int i = 1; i <= n; i++){
            res = (res*10+7)%n;
            if(res == 0){
                System.out.println(i);
                System.exit(0);
            }
        }
        System.out.println(-1);
    }
}

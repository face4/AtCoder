import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int k = Integer.parseInt(line[0]);
        int n = Integer.parseInt(line[1]);
        line = br.readLine().split(" ");
        int a[] = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(line[i]);
        }
        int ma = a[0]+k-a[n-1];
        for(int i = 1; i < n; i++){
            ma = Math.max(ma, a[i]-a[i-1]);
        }
        System.out.println(k-ma);
    }
}

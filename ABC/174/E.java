import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line[] = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        line = br.readLine().split(" ");
        int a[] = new int[n];
        for(int i = 0; i < n; i++)  a[i] = Integer.parseInt(line[i]);
        int r = 1000000000, l = 0;
        while(r-l > 1){
            int mid = (l+r)/2;
            long x = 0;
            for(int i = 0; i < n; i++){
                x += (a[i]+mid-1)/mid-1;
            }
            if(x <= k)  r = mid;
            else        l = mid;
        }
        System.out.println(r);
    }
}

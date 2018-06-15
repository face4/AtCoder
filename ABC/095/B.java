import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int x = Integer.parseInt(input[1]);
        int moto[] = new int[n];
        for(int i = 0; i < n; i++){
            moto[i] = Integer.parseInt(br.readLine());
            x -= moto[i];
        }
        int ans = n;
        Arrays.sort(moto);
        ans += x / moto[0];
        System.out.println(ans);
    }
}
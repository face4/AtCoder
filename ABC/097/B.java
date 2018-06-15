import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(br.readLine());
        int ans = 1;
        for(int i = 2; i <= Math.sqrt(x); i++){
            int can = i;
            while(can*i <= x){
                can *= i;
            }
            ans = Math.max(ans,can);
        }
        System.out.println(ans);
    }
}
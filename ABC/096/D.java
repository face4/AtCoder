import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] isPrime = new boolean[55556];

        for(int i = 4; i < 55556; i+=2){
            isPrime[i] = true;
        }

        for(int i = 3; i < 55556; i+=2){
            if(!isPrime[i]){
                for(int j = i*2; j < 55556; j+=i){
                    isPrime[j] = true;
                }
            }
        }

        int n = Integer.parseInt(br.readLine());
        int count = 2; 

        System.out.print("11");
        for(int i = 13; i < 55556 && count <= n; i+=2){
            if(!isPrime[i] && i%10 == 1){
                count++;
                System.out.print(" " + i);
            }
        }


    }
}
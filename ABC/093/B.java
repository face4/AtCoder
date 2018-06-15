import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int k = Integer.parseInt(input[2]);
        
        int present = -1;

        for(int i = 0; i < k; i++){
            present = a+i;
            if(present > b) return;
            System.out.println(present);
        }

        int start = Math.max(present+1, Math.max(0,b-k+1));
        for(int i = start; i <= b; i++){
            System.out.println(i);
        }
    }
}
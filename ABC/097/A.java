import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int c = Integer.parseInt(input[2]);
        int d = Integer.parseInt(input[3]);
        if(Math.abs(a-c) <= d || (Math.abs(a-b) <= d && Math.abs(b-c) <= d)){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
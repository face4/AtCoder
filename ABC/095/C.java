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
        int x = Integer.parseInt(input[3]);
        int y = Integer.parseInt(input[4]);
        
        long sum = 0;
        if(a + b > 2*c){
            int buyc = Math.min(x,y);
            x -= buyc;
            y -= buyc;
            sum += buyc * 2 * c;
            if(x == 0){
                if(b > 2*c){
                    sum += y*2*c;
                }else{
                    sum += y*b;
                }
            }else if(y == 0){
                if(a > 2*c){
                    sum += x*2*c;
                }else{
                    sum += x*a;
                }
            }
        }else{
            sum += x * a;
            sum += y * b;
        }

        System.out.println(sum);
    }
}
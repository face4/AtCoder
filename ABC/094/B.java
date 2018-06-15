import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int x = Integer.parseInt(input[2]);

        input = br.readLine().split(" ");
        int left = 0;
        int right = 0;
        for(String s : input){
            if(Integer.parseInt(s) < x){
                left++;
            }else if(Integer.parseInt(s) > x){
                right++;
            }
        }

        System.out.println(Math.min(left,right));
    }
}
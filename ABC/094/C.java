import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] array = new int[n];
        String[] input = br.readLine().split(" ");
        for(int i = 0; i < n; i++){
            array[i] = Integer.parseInt(input[i]);
        }
        int[] sorted = array.clone();
        Arrays.sort(sorted);

        int left = sorted[n/2-1];
        int right = sorted[n/2];
        
        for(int i = 0; i < n; i++){
            if(array[i] <= sorted[n/2-1]){
                System.out.println(right);
            }else{
                System.out.println(left);
            }
        }
    }
}
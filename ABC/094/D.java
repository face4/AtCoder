import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        String[] input = br.readLine().split(" ");
        for(int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(arr);

        int max = arr[n-1];

        int selectValue = Integer.MAX_VALUE;
        int distance = Integer.MAX_VALUE;

        int l;
        if(max % 2 == 0){
            l = max / 2;
        }else{
            l = max / 2 + 1;
        }
        int r = max / 2 + 1;

        for(int i = 0; i < n-1; i++){
            int dist = Math.abs(l-arr[i]);
            if(distance > dist){
                distance = dist;
                selectValue = arr[i];
            }
            dist = Math.abs(r-arr[i]);
            if(distance > dist){
                distance = dist;
                selectValue = arr[i];
            }
        }

        System.out.println(max + " " + selectValue);
    }
}
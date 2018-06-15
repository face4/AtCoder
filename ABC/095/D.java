import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        long c = Long.parseLong(input[1]);
        long forwardMax[] = new long[n+1];
        long backwardMax[] = new long[n+1];

        long positions[] = new long[n+1];
        long values[] = new long[n+1];

        positions[0] = 0;
        values[0] = 0;
        for(int i = 1; i <= n; i++){
            input = br.readLine().split(" ");
            positions[i] = Long.parseLong(input[0]);
            values[i] = Long.parseLong(input[1]);
        }

        long max = 0;
        long sum = 0;
        for(int i = 0; i <= n; i++){
            sum += values[i];
            max = Math.max(max, sum - positions[i]);
            forwardMax[i] = max;
        }

        max = 0;
        sum = 0;
        for(int i = n; i >= 0; i--){
            sum += values[i];
            max = Math.max(max, sum - (c - positions[i]) );
            backwardMax[i] = max;
        }

        long res = 0;

        for(int i = 0; i <= n; i++){
            // forward OA + OA + OB
            res = Math.max(res, forwardMax[i]);
            if(i != n)
                res = Math.max(res, forwardMax[i] - (positions[i]) + backwardMax[i+1]);
            
            // backward OA + OB + OB        
            res = Math.max(res , backwardMax[i]);
            if(i != 0) 
                res = Math.max(res , backwardMax[i] - (c - positions[i]) + forwardMax[i-1]);
        }

        System.out.println(res);
    }
}

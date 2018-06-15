import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int A[] = new int[3];
        for(int i = 0; i < 3; i++){
            A[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(A);

        int n = Integer.parseInt(br.readLine());
        while(n-- > 0)  A[2] = A[2]*2;
        System.out.println(A[0]+A[1]+A[2]);
    }
}
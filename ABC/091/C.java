import java.util.Scanner;
import java.util.Arrays;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] a = new int[n][2];
        int[][] b = new int[n][2];

        for(int i = 0; i < n; i++){
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
        }

        for(int i = 0; i < n; i++){
            b[i][0] = sc.nextInt();
            b[i][1] = sc.nextInt();
        }

        sc.close();
        
        Arrays.sort(a, (s, t) -> Integer.compare(t[1],s[1]));

        Arrays.sort(b, (s, t) -> Integer.compare(s[0],t[0]));

        int result = 0;

        loop:
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((a[i][0] < b[j][0]) && (a[i][1] < b[j][1])){
                    result++;
                    b[j][0] = -1;
                    b[j][1] = -1;
                    continue loop;
                }
            }
        }
        System.out.println(result);
    }
}
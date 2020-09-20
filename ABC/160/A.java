import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        char c[] = s.toCharArray();
        String ans = "";
        if(c[2]==c[3]&&c[4]==c[5]){
            ans = "Yes";
        }else{
            ans = "No";
        }
        System.out.println(ans);
    }
}

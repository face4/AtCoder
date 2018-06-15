import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] abc = new boolean[3];

        for(char c : br.readLine().toCharArray()){
            abc[c-'a'] = true;
        }

        for(boolean b : abc){
            if(!b){
                System.out.println("No");
                return;
            }
        }

        System.out.println("Yes");
    }
}
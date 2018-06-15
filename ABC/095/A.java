import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int y = 700;
        for(char c : line.toCharArray()){
            if(c == 'o')    y += 100;
        }

        System.out.println(y);
    }
}
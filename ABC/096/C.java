import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    static char[][] map;

    static int h;
    static int w;

    static boolean check(int i, int j){
        if(i != 0){
            if(map[i-1][j] == '#')  return true;
        }
        if(i != h-1){
            if(map[i+1][j] == '#')  return true;
        }
        if(j != 0){
            if(map[i][j-1] == '#')  return true;
        }
        if(j != w-1){
            if(map[i][j+1] == '#')  return true;
        }

        return false;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        h = Integer.parseInt(input[0]);
        w = Integer.parseInt(input[1]);
        
        map = new char[h][w];

        for(int i = 0; i < h; i++){
            map[i] = br.readLine().toCharArray();
        }

        boolean res = true;
        a:
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j] == '#' && !check(i, j)){
                    res = false;
                    break a;
                }
            }
        }

        if(res){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
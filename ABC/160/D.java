import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int x = Integer.parseInt(line[1])-1;
        int y = Integer.parseInt(line[2])-1;
        ArrayList<Integer>[] arr = new ArrayList[n];
        arr[0] = new ArrayList<Integer>();
        for(int i = 0; i+1 < n; i++){
            arr[i+1] = new ArrayList<Integer>();
            arr[i].add(i+1);
            arr[i+1].add(i);
        }
        arr[x].add(y);
        arr[y].add(x);
        int ans[] = new int[n];
        for(int i = 0; i < n; i++){
            int dis[] = new int[n];
            LinkedList<Integer> l = new LinkedList<Integer>();
            l.add(i);
            while(!l.isEmpty()){
                int s = l.poll();
                ans[dis[s]]++;
                for(int b : arr[s]){
                    if(b == i || dis[b] > 0)    continue;
                    dis[b] = dis[s]+1;
                    l.add(b);
                }
            }
        }
        for(int i = 1; i < n; i++)  System.out.println(ans[i]/2);
    }
}

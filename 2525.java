import java.util.Scanner;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Scanner in = new Scanner(System.in);
        int hour = in.nextInt();
        int min = in.nextInt();
        int time = in.nextInt();

        hour +=time/60;
        min+=time%60;

        if(min>=60){
            min-=60;
            hour++;
        }
        if(hour>=24){
            hour-=24;
        }

        bw.write(hour+" "+min);
        in.close();
        bw.close();
    }
}

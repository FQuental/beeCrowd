import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        double a, b,c, media;
        Scanner sc = new Scanner(System.in);
        a = sc.nextDouble();
        b = sc.nextDouble();
        c = sc.nextDouble();
        sc.close();
        media =(((a*2)+(b*3)+(c*5))/10);
        System.out.println(media);
        System.out.println("MEDIA = "+String.format("%.1f", media, args));
    }
}
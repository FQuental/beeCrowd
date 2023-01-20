import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        double a, b, media;
        Scanner sc = new Scanner(System.in);
        a = sc.nextDouble();
        b = sc.nextDouble();
        sc.close();
        media =(((a*3.5)+(b*7.5))/11);
        System.out.println("MEDIA = "+String.format("%.5f", media, args));
    }
}
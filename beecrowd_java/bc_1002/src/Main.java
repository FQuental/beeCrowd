import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        double p = 3.14159, raio, area;
        Scanner sc = new Scanner(System.in);
        raio = sc.nextDouble();
        sc.close();
        area= p*Math.pow(raio,2);
        System.out.println("A="+String.format("%.4f", area, args));

    }
}

import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        //String nome;
        double sal, vend;
        Scanner sc = new Scanner(System.in);
        //nome=sc.next();
        sal=sc.nextDouble();
        vend=sc.nextDouble();
        sc.close();
        sal+=vend*0.15;
        System.out.println("TOTAL = R$ "+String.format("%.2f", sal, args));
    }
}
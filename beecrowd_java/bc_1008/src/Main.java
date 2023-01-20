import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        int fun,time;
        double sal, preco;
        Scanner sc = new Scanner(System.in);
        fun = sc.nextInt();
        time = sc.nextInt();
        preco = sc.nextDouble();
        sc.close();
        sal = preco*time;
        System.out.println("NUMBER = "+fun);
        System.out.println("SALARY = U$ "+String.format("%.2f", sal, args));
    }
}
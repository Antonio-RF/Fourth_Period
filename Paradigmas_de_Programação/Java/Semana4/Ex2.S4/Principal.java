import java.util.*;
public class Principal {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        Lampada obj1 = new LampadaFluorecente(true, 20);
        Lampada obj2 = new LampadaLed(false);

        System.out.printf("Escolha entre Lâmpada Fluorecente(número 1) ou Lâmpada Led(número 2). Digite o número escolhido: ");
        int escolha = teclado.nextInt();
        if (escolha == 1) {
            obj1.ligaDesliga();
            String temp = obj1.toString();
            System.out.printf("%s", temp);
        }
        else {
            obj2.ligaDesliga();
            String temp = obj2.toString();
            System.out.printf("%s", temp);
        }
    }
}
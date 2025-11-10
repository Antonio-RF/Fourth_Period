import java.util.Scanner;
public class Principal {
    public static void main (String [] args) {
        Scanner teclado = new Scanner(System.in);

        Time horario1 = new Time();
        horario1.setHora(12);
        horario1.setMinuto(10);

        Time horario2 = new Time();
        horario2.setHora(12);
        horario2.setMinuto(5);

        System.out.println("Horario 1: " + horario1.toString());
        System.out.println("Horario 2: " + horario2.toString());

        if (horario1.anterior(horario2.getHora(), horario2.getMinuto())) {
            System.out.printf("Horario 2 é anterior.\n");
        }
        else if (horario1.posterior(horario2.getHora(), horario2.getMinuto())) {
            System.out.printf("Horário 1 é anterior.\n");
        }
        else {
            System.out.printf("Horários iguais.\n");
        }

        teclado.close();
    }
}
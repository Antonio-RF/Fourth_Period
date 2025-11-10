import java.util.*;
public class Principal {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        
        Collection<Personagem> p = new TreeSet<>();

        for (int i=0 ; i<50 ; i++) {
            Personagem temp = null;
            if (i % 5 == 0 || i % 5 == 3)
                temp = new Guerreiro("Antonio", 1000, 5000);
            if (i % 5 == 1 || i % 5 == 4)
                temp = new Mago("Gastal", 400, 700);
            if (i % 5 == 2)
                temp = new Arqueiro("Pierobon", 10, 5);
            p.add(temp);
        }

       
        for (Personagem k : p) {
            System.out.printf("Personagem: %s | Dano %.2f%n", k.getNome(), k.calcularDano());
        }



    }
}
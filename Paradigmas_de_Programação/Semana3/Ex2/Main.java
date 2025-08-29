import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();

        Autor autor1 = new Autor(a, "Brasileiro");
        Autor autor2 = new Autor("Gary Chapman", "Estadunidense");
        Livro livro1 = new Livro("Dom Casmurro", 1899, autor1, 5);
        Livro livro2 = new Livro("As Cinco Linguagens do amor", 2013, autor2, 3);


        System.out.println(autor1);
        System.out.println(autor2);
        System.out.println(livro1);
        System.out.println(livro2);
    }
}
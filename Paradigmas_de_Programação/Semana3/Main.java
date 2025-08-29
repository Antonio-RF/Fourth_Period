import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Autor autor1 = new Autor("Machado de Assis", "Brasileiro");
        Livro livro1 = new Livro("Dom Casmurro", 1899, autor1);

        System.out.println(livro1);
    }
}
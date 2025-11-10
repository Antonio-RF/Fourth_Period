public class Principal {
    public static void main(String[] args) {
        Autor aut1 = new Autor("Antonio", "brazuca");
        Livro liv1 = new Livro("O programador que não programa em Java", 2025, aut1, 1);

        Autor aut2 = new Autor("Enzo", "americano");
        Livro liv2 = new Livro("O programador que tem aula com o Paulo Circutos", 2025, aut2, 2);

        liv1.exibirDados();
        System.out.printf("\n");
        liv2.exibirDados();

        
    }
}
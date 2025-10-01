public class Principal {
    public static void main(String[] args) {
        Autor aut = new Autor("Antonio", "brazuca");
        Livro liv = new Livro("O programador que não programa em Java", 2025, aut);

        System.out.printf("O livro ' %s ' do autor %s, que é %s, foi lançado em %d", liv.getTitulo(), liv.getAutor().getNome(), liv.getAutor().getNacionalidade(), liv.getAno());
    }
}
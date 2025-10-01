public class Livro {
    private String titulo;
    private int ano;
    private int edicao;
    private Autor aut;

    //Métodos GET:
    public String getTitulo() {
        return this.titulo;
    }
    public int getAno() {
        return this.ano;
    }
    public int getEdicao() {
        return this.edicao;
    }
    public Autor getAutor() {
        return this.aut;
    }
    
    //Métodos SET:
    public void setTitulo(String titulo) {
        if (titulo != null)
            this.titulo = titulo;
    }
    public void setAno(int ano) {
        if (ano > 0)
            this.ano = ano;
    }
    public void setEdicao(int edicao) {
        if (edicao > 0)
            this.edicao = edicao;
    }
    public void setAutor(Autor aut) {
        if (aut != null)
            this.aut = aut;
    }

    //Construtores:
    public Livro(String titulo) {
        this.setTitulo(titulo);
    }
    public Livro(String titulo, int ano) {
        this.setTitulo(titulo);
        this.setAno(ano);
    }
    public Livro(String titulo, int ano, Autor aut, int edicao) {
        this.setTitulo(titulo);
        this.setAno(ano);
        this.setAutor(aut);
        this.setEdicao(edicao);
    }

    public void exibirDados() {
        System.out.printf("a. Título: %s.\nb. Ano: %d.\nc. Autor: %s.\nd. Edição: %d.\n", getTitulo(), getAno(), getAutor().getNome(), getEdicao());
    }
}
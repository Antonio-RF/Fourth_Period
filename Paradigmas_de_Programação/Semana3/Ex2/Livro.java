public class Livro {
    private String titulo;
    private int anoPublicacao;
    private Autor autor;
    private int edicao;


    // Construtor 1:
    public Livro() {
    }
    // Construtor 2:
    public Livro(String titulo, int anoPublicacao) {
        this.titulo = titulo;
        this.setAnopub(anoPublicacao);
    }

    // Construtor 3:
    public Livro(String titulo, int anoPublicacao, Autor autor, int edicao) {
        this.setTitulo(titulo);
        this.setAnopub(anoPublicacao);
        this.setAutor(autor);
        this.setEdicao(edicao);
    }


    public Autor getAutor(){
        return autor;
    }
    public int getAnoPublicacao() {
        return anoPublicacao;
    }
    public String getTitulo() {
        return titulo;
    }
    public int getEdicao() {
        return edicao;
    }

    public void setAutor(Autor autor) {
        if (autor != null)
            this.autor = autor;
    }
    public void setAnopub(int anoPublicacao) {
        if (anoPublicacao > 0)
            this.anoPublicacao = anoPublicacao;
    }
    public void setTitulo(String titulo) {
        if (titulo != null)
            this.titulo = titulo;
    }
    public void setEdicao(int edicao) {
        if (edicao > 0)
            this.edicao = edicao;
    }

    public String toString() {
        return String.format("a. Titulo: %s \n b. Ano: (%d) \n c. Autor: %s \n Edição: %d\n", titulo, anoPublicacao, autor.getNome(), edicao);    
    }
}
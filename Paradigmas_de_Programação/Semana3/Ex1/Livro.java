public class Livro {
    private String titulo;
    private int anoPublicacao;
    private Autor autor;


    // Construtor 1:
    public Livro() {
    }
    // Construtor 2:
    public Livro(String titulo, int anoPublicacao) {
        this.titulo = titulo;
        this.setAnopub(anoPublicacao);
    }
    // Construtor 3:
    public Livro(String titulo, int anoPublicacao, Autor autor) {
        this.titulo = titulo;
        this.anoPublicacao = anoPublicacao;
        this.autor = autor;
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

    public void setAutor(Autor autor) {
        if (this.autor != null)
            this.autor = autor;
    }
    public void setAnopub(int ano_pub) {
        if (this.anoPublicacao > 0)
            this.anoPublicacao = anoPublicacao;
    }
    public void setTitulo(String titulo) {
        if (this.titulo != null)
            this.titulo = titulo;
    }

    public String toString() {
        return String.format("Livro: %s (%d) - %s", titulo, anoPublicacao, autor);    
    }
}
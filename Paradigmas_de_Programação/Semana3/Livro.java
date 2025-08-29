public class Autor {
    private String titulo;
    private int anoPublicacao;
    private Autor autor;


    // Construtor 1.
    public Livro() {
        this.titulo = "Sem título";
        this.anoPublicacao = 0;
        this.autor = new Autor();
    }

    // Construtor 2.
    public Livro(String titulo, int anoPublicacao) {
        this.titulo = titulo;
        this.anoPublicacao = anoPublicacao;
        this.autor = new Autor();
    }

    // Construtor 3.
    public Livro(String titulo, int anoPublicacao, Autor autor) {
        this.titulo = titulo;
        this.anoPublicacao = anoPublicacao;
        this.autor = autor;
    }


    public String getAutor(){
        return this.autor;
    }
    public int getAnoPublicacao() {
        return this.anoPublicacao;
    }
    public String getTitulo() {
        return this.titulo;
    }

    public void setAutor(autor) {
        if (this.autor != null)
            this.autor = autor;
    }
    public void setAnopub(ano_pub) {
        if (this.anoPublicacao > 0)
            this.anoPublicacao = anoPublicacao;
    }
    public void settitulo(titulo) {
        if (this.titulo != null)
            this.titulo = titulo;
    }

    public String toString() {
        return String.format("O autor %s publicou seu livro %s em: %s: %s\n", this.autor, this.titulo, this.anoPublicacao);
    }
}
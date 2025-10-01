public class Livro {
    private String titulo;
    private int ano;
    private Autor aut;

    //Métodos GET:
    public String getTitulo() {
        return this.titulo;
    }
    public int getAno() {
        return this.ano;
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
    public Livro(String titulo, int ano, Autor aut) {
        this.setTitulo(titulo);
        this.setAno(ano);
        this.setAutor(aut);
    }
}
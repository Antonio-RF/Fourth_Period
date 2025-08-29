public class Autor {
    private String nome;
    private String nacionalidade;

    public Autor() {
    }

    //Construtor 2:
    public Autor(String nome) {
        this.nome = nome;
    }

    //Construtor 3:
    public Autor(String nome, String nacionalidade) {
        this.setNome(nome);
        this.setNacionalidade(nacionaldade);
    }


    public String getNome(){
        return this.nome;
    }
    public String getNacionalidade() {
        return this.nacionalidade;
    }

    public void setNome(String nome) {
        if (this.nome != null)
            this.nome = nome;
    }
    public void setNacionalidade(String nacionalidade) {
        if (this.nacionalidade != null)
            this.nacionalidade = nacionalidade;
    }

    public String toString() {
        return String.format("O autor %s tem nacionaldade: %s\n", this.nome, this.nacionalidade);
    }
}
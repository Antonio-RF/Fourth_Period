public class Autor {
    private String nome;
    private String nacionalidade;

    public Autor() {
        this.nome = "Desconhecido";
        this.nacionalidade = "Desconhecida";
    }

    public Autor(String nome) {
        this.nome = nome;
        this.nacionalidade = "Desconhecida";
    }

    public Autor(String nome, String nacionalidade) {
        this.nome = nome;
        this.nacionalidade = nacionalidade;
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
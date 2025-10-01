public class Autor {
    private String nome;
    private String nacionalidade;

    //Métodos GET:
    public String getNome() {
        return this.nome;
    }
    public String getNacionalidade() {
        return this.nacionalidade;
    }

    //Métodos SET:
    public void setNome(String nome) {
        if (nome != null)
            this.nome = nome;
    }
    public void setNacionalidade(String nacionalidade){
        if (nacionalidade != null)
            this.nacionalidade = nacionalidade;
    }

    public Autor(String nome) {
        this.setNome(nome);
    }
    public Autor(String nome, String nacionalidade) {
        this.setNome(nome);
        this.setNacionalidade(nacionalidade);
    }
    public Autor() {}


}
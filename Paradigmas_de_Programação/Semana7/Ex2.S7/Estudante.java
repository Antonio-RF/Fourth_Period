public abstract class Estudante {
    protected String nome;
    protected int matricula;

    //Métodos GET:
    public String getNome() {
        return this.nome;
    }
    public int getMatricula() {
        return this.matricula;
    }

    //Métodos SET:
    public void setNome(String nome) {
        if (nome != null)
            this.nome = nome;
    }
    public void setMatricula(int matricula) {
        if (matricula > 0)
            this.matricula = matricula;
    }

    //Construtor:
    public Estudante(String nome, int matricula) {
        this.setNome(nome);
        this.setMatricula(matricula);
    }

}
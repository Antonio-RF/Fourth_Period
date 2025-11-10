public class Aluno {
    private String nome;
    private int GRR;

    //Métodos GET:
    public String getNome() {
        return this.nome;
    }
    public int getGRR() {
        return this.GRR;        
    }

    //Métodos SET:
    public void setNome(String nome) {
        if (nome != null)
            this.nome = nome;
    }
    public void setGRR(int GRR) {
        if (GRR > 0)
            this.GRR = GRR;
    }

    //Construtores:
    public Aluno(String nome) {
        this.setNome(nome);
    }
    public Aluno(String nome, int GRR) {
        this.setNome(nome);
        this.setGRR(GRR);
    }

}
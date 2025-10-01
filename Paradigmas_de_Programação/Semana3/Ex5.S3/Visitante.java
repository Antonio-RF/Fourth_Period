public class Visitante {
    private String nome;
    private int idade;
    //Adicionei a mais pq a professora não tinha falado no enunciado:
    private double alturaVisitante;
    private int saldo;

    //Métodos GET:
    public String getNome() {
        return this.nome;
    }
    public int getIdade() {
        return this.idade;
    }
    public int getSaldo() {
        return this.saldo;
    }
    public double getAlturaVisitante() {
        return this.alturaVisitante;
    }

    //Métodos SET:
    public void setNome(String nome) {
        if (nome != null)
            this.nome = nome;
    } 
    public void setIdade(int idade){
        if (idade > 0)
            this.idade = idade;
    }
    public void setSaldo(int saldo) {
        if (saldo > 0)
            this.saldo = saldo;
    }
    public void setAlturaVisitante(double alturaVisitante) {
        if (alturaVisitante > 0)
            this.alturaVisitante = alturaVisitante;
    }

    //Construtor:
    public Visitante(String nome, int idade, int saldo, double alturaVisitante) {
        this.setNome(nome);
        this.setIdade(idade);
        this.setSaldo(saldo);
        this.setAlturaVisitante(alturaVisitante);
    }

    public void CompraIngresso(int qntdIngressos, int valorIngresso) {
        if (this.saldo > qntdIngressos*valorIngresso) {
            this.saldo -= qntdIngressos*valorIngresso;
        }
    }

}
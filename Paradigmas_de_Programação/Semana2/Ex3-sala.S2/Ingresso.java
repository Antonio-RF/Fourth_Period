public class Ingresso {
    private String nomeDoFilme;
    private int numeroDaSala;
    private int preco;

    //Métodos Get:
    public String getNomeDoFilme(){
        return this.nomeDoFilme;
    }
    public int getNumeroDaSala() {
        return this.numeroDaSala;
    }
    public int getPreco() {
        return this.preco;
    }

    //Métodos Set:
    public void setNomeDoFilme(String nomeDoFilme) {
        if (nomeDoFilme != null)
            this.nomeDoFilme = nomeDoFilme;
    }
    public void setNumeroDaSala(int numeroDaSala) {
        if (numeroDaSala > 0)
            this.numeroDaSala = numeroDaSala;        
    }
    public void setPreco(int preco) {
        if (preco > 0)
            this.preco = preco;
    }

    public void exibirDados() {
        System.out.printf("O filme %s será exibido na sala número %d. Os ingressos já estão disponíveis e custam %d", getNomeDoFilme(), getNumeroDaSala(), getPreco());
    }

}
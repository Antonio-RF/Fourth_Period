public class Ingresso {
    protected int valorIngresso;

    //Método GET:
    public int getValorIngresso() {
        return this.valorIngresso;
    }

    //Método SET:
    public void setValorIngresso(int valorIngresso) {
        if (valorIngresso > 0)
            this.valorIngresso = valorIngresso;
    }

    //Construtor:
    public Ingresso(int valorIngresso) {
        this.setValorIngresso(valorIngresso);
    }

    public void exibirDados() {
        System.out.printf("O valor do ingresso é: %d", getValorIngresso());
    }

}
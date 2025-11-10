public class IngressoNormal extends Ingresso {
    
    //Construtor:
    public IngressoNormal(int valorIngresso) {
        super(valorIngresso);
    }

    @Override
    public void exibirDados() {
        System.out.printf("O preço do ingresso é: %d\n", getValorIngresso());
    }

}
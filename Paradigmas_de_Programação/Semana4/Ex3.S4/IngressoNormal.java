public class IngressoNormal extends Ingresso {
    
    //Construtor:
    public IngressoNormal(int valorIngresso) {
        super(valorIngresso);
    }

    public void imprimeIngressoNormal() {
        System.out.printf("O preço do ingresso normal é %d", getValorIngresso());
    }

}
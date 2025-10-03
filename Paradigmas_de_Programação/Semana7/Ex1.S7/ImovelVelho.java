public class ImovelVelho extends Imovel {

    public ImovelVelho(String endereco, int preco) {
        super(endereco, preco);
    }

    public void calcularValorImovel() {
        System.out.printf("O preco do imovel é: %d\n", this.preco);
    }

}
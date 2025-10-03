public abstract class Imovel {
    protected String endereco;
    protected int preco;


    //Métodos GET:
    public String getEndereco() {
        return this.endereco;
    }
    public int getPreco() {
        return this.preco;
    }

    //Métodos SET:
    public void setEndereco(String endereco) {
        if (endereco != null)
            this.endereco = endereco;
    }
    public void setPreco(int preco) {
        if (preco > 0)
            this.preco = preco;
    }

    //Construtor:
    public Imovel(String endereco, int preco) {
        this.setEndereco(endereco);
        this.setPreco(preco);
    }

    public abstract void calcularValorImovel();

}
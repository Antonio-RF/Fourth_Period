public class ItemPedido {
    private String nomeDoItem;
    private int preco;

    //Métodos GET:
    public String getNomeDoItem() {
        return this.nomeDoItem;
    }
    public int getPreco() {
        return this.preco;
    }

    //Métodos SET:
    public void setNomeDoItem(String nomeDoItem) {
        if (nomeDoItem != null)
            this.nomeDoItem = nomeDoItem;
    }
    public void setPreco(int preco) {
        if (preco > 0)
            this.preco = preco;
    }

    //Construtor:
    public ItemPedido() {}
    public ItemPedido(String nomeDoItem, int preco) {
        this.setNomeDoItem(nomeDoItem);
        this.setPreco(preco);
    }
}
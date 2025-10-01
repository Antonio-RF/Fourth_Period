public class Pedido {
    private int numeroDoPedido;
    private ItemPedido[] listaItens;
    private int qntdItens;

    //Métodos GET:
    public int getNumeroDoPedido() {
        return this.numeroDoPedido;
    }
    public ItemPedido[] getListaIntens() {
        return this.listaItens;
    }

    //Métodos SET:
    public void setNumeroDoPedido(int numeroDoPedido) {
        if (numeroDoPedido > 0)
            this.numeroDoPedido = numeroDoPedido;
    }
    
    //Construtor:
    public Pedido(int numeroDoPedido, int maxItens) {
        this.setNumeroDoPedido(numeroDoPedido);
        this.listaItens = new ItemPedido[maxItens];
        this.qntdItens = 0;
    }

    //Métodos:
    public void adicionarPedidos(String nomeDoItem, int preco) {
        if (this.qntdItens < listaItens.length) {
            listaItens[this.qntdItens] = new ItemPedido(nomeDoItem, preco);
            this.qntdItens++;
        }
    }
    public int calculaValorTotalPedido() {
        int total = 0;
        for (int i=0 ; i<this.qntdItens ; i++) {
            total += listaItens[i].getPreco();
        }
        return total;
    }
    public void imprimirPedidos() {
        System.out.printf("Pedido #%d\n", this.numeroDoPedido);
        for (int i=0 ; i<this.qntdItens ; i++) {
            System.out.printf("%d- %s ($%d).\n", i+1, listaItens[i].getNomeDoItem(), listaItens[i].getPreco());
        }
        int total = calculaValorTotalPedido();
        System.out.printf("Total: $%d.\n", total);
    }
}
public class Principal {
    public static void main(String[] args) {


        Pedido itens = new Pedido(101, 4);
        itens.adicionarPedidos("Mostarda", 100);
        itens.adicionarPedidos("Pizza", 35);
        itens.adicionarPedidos("Suco", 8);

        itens.imprimirPedidos();

    }
}
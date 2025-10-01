public class ParqueDeDiversao {
    public static void main(String[] args) {
        Visitante vis1 = new Visitante("Antonio", 20, 10000, 1.80);
        Visitante vis2 = new Visitante("Heric", 25, 5000, 1.75);

        Brinquedo brinq1 = new Brinquedo("Montanha Russa", 1.80, 1000);
        Brinquedo brinq2 = new Brinquedo("Big Tower", 1.50, 50);

        AtracaoEspecial atra1 = new AtracaoEspecial("Casa Assombrada", 2, 0);
        AtracaoEspecial atra2 = new AtracaoEspecial("Casa da Fantasia", 1, 0);

        //i:
        
        if (brinq1.verificaAltura(vis1.getAlturaVisitante())) {
            System.out.printf("Visitante %s pode ir no brinquedo %s\n", vis1.getNome(), brinq1.getNomeDoBrinquedo());
        }
        else System.out.printf("Visitante %s não pode ir no brinquedo %s\n", vis1.getNome(), brinq1.getNomeDoBrinquedo());

        //ii:
        atra1.adicionaPessoas(5);
        if (atra1.verificaCapacidadeMaxima()) {
            System.out.printf("A atração %s respeita a capacidade máxima\n", atra1.getNomeDaAtracao());
        }
        else System.out.printf("A atração %s está cheia e não respeita a capacidade máxima\n", atra1.getNomeDaAtracao());

        //iii:
        System.out.printf("Saldo do visitante antes da compra: %d\n", vis1.getSaldo());
        vis1.CompraIngresso(2, brinq1.getPrecoDoIngresso());
        System.out.printf("Saldo do visitante depois da compra: %d\n", vis1.getSaldo());


    }
}
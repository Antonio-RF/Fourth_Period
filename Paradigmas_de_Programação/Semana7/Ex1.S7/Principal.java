import java.util.*;
public class Principal {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        System.out.printf("Escolha um nome de casa velha: ");
        String nomeVelha = teclado.next();
        System.out.printf("Escolha um nome de casa nova: ");
        String nomeNova = teclado.next();

        Imovel[] imoveis = new Imovel[200];
        for (int i=0 ; i<200 ; i++) {
            if (i % 2 == 0)
                imoveis[i] = new ImovelNovo(nomeNova, i*1000);
            else
                imoveis[i] = new ImovelVelho(nomeVelha, i*1000);
        }

        for (Imovel i : imoveis) {
            i.calcularValorImovel();
        }

    }
}
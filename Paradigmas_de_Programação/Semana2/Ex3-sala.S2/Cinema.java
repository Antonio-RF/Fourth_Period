import java.util.Scanner;

public class Cinema {
    public static void main (String[] args) {
        Scanner teclado = new Scanner(System.in);
        Ingresso[] tickets = new Ingresso[5];
        
        for (int i=0 ; i<5 ; i++) {
            String temp_nome = teclado.next();
            int temp_nmr_sala = teclado.nextInt();
            int temp_preco = teclado.nextInt();

            tickets[i] = new Ingresso();
            tickets[i].setNomeDoFilme(temp_nome);
            tickets[i].setNumeroDaSala(temp_nmr_sala);
            tickets[i].setPreco(temp_preco);
        }

        int total_arrecadado = 0;
        String nome_mais_caro = tickets[0].getNomeDoFilme();
        int preco_mais_caro = tickets[0].getPreco();
        for (int i=0 ; i<5 ; i++) {
            if (preco_mais_caro < tickets[i].getPreco()) {
                preco_mais_caro = tickets[i].getPreco();
                nome_mais_caro = tickets[i].getNomeDoFilme();
            }
            total_arrecadado += tickets[i].getPreco();
        }

        System.out.printf("Total Arrecadado: %d | Filme com preço mais caro: %s | Preco mais caro: %d", total_arrecadado, nome_mais_caro, preco_mais_caro);
    }
}
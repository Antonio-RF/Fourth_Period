import java.util.Scanner;
public class Principal {
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        ContaBancaria[] dados = new ContaBancaria[3];
        for (int i=0 ; i<3 ; i++) {
            System.out.print("Digite o nome: ");
            String temp_nome = teclado.next();
            System.out.print("Digite o saldo: ");
            int temp_saldo = teclado.nextInt();
            System.out.print("Digite o limite: ");
            int temp_limite = teclado.nextInt();

            dados[i] = new ContaBancaria();
            dados[i].setNomeDoTitulo(temp_nome);
            dados[i].setSaldo(temp_saldo);
            dados[i].setLimiteDeSaque(temp_limite);
        }

        int saldo_total = 0;
        int maior_saldo = dados[0].getSaldo();
        int menor_saldo = dados[0].getSaldo();
        String nome_menor = dados[0].getNomeDoTitulo();
        for (int j=0 ; j<3 ; j++) {
            if (maior_saldo < dados[j].getSaldo())
                maior_saldo = dados[j].getSaldo();

            if (menor_saldo > dados[j].getSaldo()) {
                menor_saldo = dados[j].getSaldo();
                nome_menor = dados[j].getNomeDoTitulo();
            }

            saldo_total += dados[j].getSaldo();
        }

        System.out.printf("O saldo total é: %d.\n O maior saldo é: %d.\n Por fim, o menor saldo é: %d e é do(a): %s.\n", saldo_total, maior_saldo, menor_saldo, nome_menor);

    }
}
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String remetente = "Antonio R.F";

        String aniver = sc.nextLine();
        System.out.println("aniver: " + aniver);
        String natal = sc.nextLine();
        System.out.println("natal: " + natal);
        String namorado = sc.nextLine();
        System.out.println("namorado: " + namorado);

        CartaoWeb[] cartoes = new CartaoWeb[3];
        cartoes[0] = new CartaoDiaDosNamorados(namorado);
        cartoes[1] = new CartaoNatal(natal);
        cartoes[2] = new CartaoAniversario(aniver);

        System.out.println("Mensagem dos cartões: \n");
        for (int i=0 ; i<3 ; i++) {
            System.out.println(cartoes[i].retornarMensagem(remetente));
        }

        sc.close();

    }
}